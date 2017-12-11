import ROOT
import numpy as np
import matplotlib.pyplot as plt
from sklearn import preprocessing

def readevent():

    ROOT.gSystem.Load("libPevent.so")
    filename = "pevents_jetq.root"
    infile = ROOT.TFile(filename)
    tevent = infile.Get("tevent")
    tevent.Print()
    
    pevent = ROOT.Pevent()
    tevent.SetBranchAddress("pevent", pevent)
    nentries = tevent.GetEntries()
    for i in xrange(0, nentries):
        tevent.GetEntry(i)
        print "------event %d------" % i
        pevent.Print()
     

def readjets():
    
    ROOT.gSystem.Load("libPevent.so")
    filename = "pevents_jetq.root"
    infile = ROOT.TFile(filename)
    tevent = infile.Get("tevent")
    tevent.Print()
    
    pevent = ROOT.Pevent()
    tevent.SetBranchAddress("pevent", pevent)
    nentries = tevent.GetEntries()
    for i in xrange(0, nentries):
        tevent.GetEntry(i)
        pjets = pevent.jets()
        njets = pjets.size()
        for j in xrange(0, njets):
            #
            # filter jets here
            #
            yield pjets[j]


def generateJetImages():
    
    R = 0.4
    nEta = 33
    nPhi = 33
    wEta = 2*R / nEta # eta bin width
    wPhi = 2*R / nPhi # phi bin width
    
    jetImages = []
    njets = 0
    for t,pjet in enumerate(readjets()):
        #pjet.Print()
        njets += 1
        # compute the pt-weighted centroid
        etawSum = 0
        phiwSum = 0
        ptSum = 0
        ptracks = pjet.constituents()
        nptracks = ptracks.size()
        for i in xrange(0, nptracks):
            
            ptrk = ptracks[i]
            ptrk4vec = ptrk.fourMomentum()
            
            pt = ptrk4vec.Pt()
            ptSum += pt
            
            eta = ptrk4vec.Eta()
            etawSum += eta*pt
            
            phi = ptrk4vec.Phi()
            phiwSum += phi*pt
        
        etaC = etawSum / ptSum
        phiC = phiwSum / ptSum
        
        #print 'etaC: ',etaC
        #print 'phiC: ',phiC
        #print 'jetEtaC: ',pjet.fourMomentum().Eta()
        #print 'jetPhiC: ',pjet.fourMomentum().Phi()
        # At mid-rapidity etaC ~ jetEtaC, phiC ~ jetPhiC

        # three channels
        imagePtCharged = np.zeros((nEta, nPhi)) # charged particle pT
        imagePtNeutral = np.zeros((nEta, nPhi)) # neutral particle pT
        imageMultCharged = np.zeros((nEta, nPhi)) # charge particle multiplicity
        # re-center the tracks in a jet, fill in each channel
        for i in xrange(0, nptracks):
            
            ptrk = ptracks[i]
            ptrk4vec = ptrk.fourMomentum()
            pt = ptrk4vec.Pt()
            eta = ptrk4vec.Eta()
            phi = ptrk4vec.Phi()
            charge = ptrk.charge()

            if abs(eta - etaC) > R or abs(phi - phiC) > R: continue

            # find bin number
            etaBin = int(nEta / 2) + int((eta - etaC) / wEta)
            phiBin = int(nPhi / 2) + int((phi - phiC) / wPhi)
            #print etaBin, phiBin
            if charge == 0:
                imagePtNeutral[etaBin, phiBin] += pt
            else:
                imagePtCharged[etaBin, phiBin] += pt
                imageMultCharged[etaBin, phiBin] += 1
                
        jetImages.append([imagePtCharged, imagePtNeutral, imageMultCharged])

    print 'njets: ',njets
    jetImages = np.array(jetImages)
    print 'jetImages.shape:'
    print jetImages.shape
    
    # plot mean imagePtCharged
    meanImagePtCharged = np.mean(jetImages[:,0,:,:], axis=0)
    print meanImagePtCharged.shape
    plt.imshow(meanImagePtCharged)
    plt.colorbar()
    plt.savefig('ptcharged_mean_q.png')
    
    # plot mean imagesPtNeutral
    plt.clf()
    meanImagePtNeutral = np.mean(jetImages[:,1,:,:], axis=0)
    print meanImagePtNeutral.shape
    plt.imshow(meanImagePtNeutral)
    plt.colorbar()
    plt.savefig('ptneutral_mean_q.png')
    
    # plot mean imageMultCharged
    plt.clf()
    meanImageMultCharged = np.mean(jetImages[:,2,:,:], axis=0)
    print meanImageMultCharged.shape
    plt.imshow(meanImageMultCharged)
    plt.colorbar()
    plt.savefig('multcharged_mean_q.png')
    
    # normalize & standardize each channel
    normJetImages = np.zeros_like(jetImages)
    stJetImages = np.zeros_like(jetImages)
    # 1). normalize, divide each pixel by the sum of all pixel values in the same channel
    sumImagePtCharged = np.sum(jetImages[:,0,:,:], axis=(1,2))
    print 'sumImagePtCharged.shape:'
    print sumImagePtCharged.shape
    print 'min sumImagePtCharged'
    print np.min(sumImagePtCharged)
    print 'argmin sumImagePtCharged'
    print np.argmin(sumImagePtCharged, axis=0)
    # some images only contain zero pixel values, remove them?

    # boradcast the sum to match the shape of jetImages
    normJetImages[:,0,:,:] = np.nan_to_num(jetImages[:,0,:,:]/sumImagePtCharged[:, np.newaxis, np.newaxis])

    # to the same for the other two channels
    sumImagePtNeutral = np.sum(jetImages[:,1,:,:], axis=(1,2))
    normJetImages[:,1,:,:] = np.nan_to_num(jetImages[:,1,:,:]/sumImagePtNeutral[:, np.newaxis, np.newaxis])

    sumImageMultCharged = np.sum(jetImages[:,2,:,:], axis=(1,2))
    normJetImages[:,2,:,:] = np.nan_to_num(jetImages[:,2,:,:]/sumImageMultCharged[:, np.newaxis, np.newaxis])
    
    # double-check
    normJetSum = np.sum(normJetImages, axis=(2,3))
    print np.mean(normJetSum[normJetSum!=np.zeros_like(normJetSum)])
    
    # standardize
    r = 1e-5
    stJetImages[:,0,:,:] = np.nan_to_num((normJetImages[:,0,:,:] - np.mean(normJetImages[:,0,:,:], 
        axis=(1,2))[:, np.newaxis, np.newaxis]) / (np.std(normJetImages[:,0,:,:], axis=(1,2))[:, np.newaxis, np.newaxis]
        + r*np.ones(normJetImages[:,0,:,:].shape)))
    
    stJetImages[:,1,:,:] = np.nan_to_num((normJetImages[:,1,:,:] - np.mean(normJetImages[:,1,:,:], 
        axis=(1,2))[:, np.newaxis, np.newaxis]) / (np.std(normJetImages[:,1,:,:], axis=(1,2))[:, np.newaxis, np.newaxis]
        + r*np.ones(normJetImages[:,1,:,:].shape)))
    
    stJetImages[:,2,:,:] = np.nan_to_num((normJetImages[:,2,:,:] - np.mean(normJetImages[:,2,:,:], 
        axis=(1,2))[:, np.newaxis, np.newaxis]) / (np.std(normJetImages[:,2,:,:], axis=(1,2))[:, np.newaxis, np.newaxis]
        + r*np.ones(normJetImages[:,2,:,:].shape)))
    
    # double-check
    print np.sum(np.mean(stJetImages, axis=(2,3)))
    #print np.mean(np.std(stJetImages, axis=(2,3)))
    #return 1

    with open('stjetimages_q.npy', 'wb') as outfile:
        np.save(outfile, jetImages)

def readJetImages():
    
    print 'reading jet images...'
    jetImages = np.load('stjetimages_q.npy')
    print 'jetImages.shape:'
    print jetImages.shape

if __name__ == '__main__':
    #readevent()
    generateJetImages()
    readJetImages()
