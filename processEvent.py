import ROOT
import numpy as np
import matplotlib.pyplot as plt


def readevent():

    ROOT.gSystem.Load("libPevent.so")
    filename = "pevents.root"
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
    filename = "pevents.root"
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
    for pjet in readjets():
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
    plt.savefig('ptcharged_mean.png')
    
    # plot mean imagesPtNeutral
    plt.clf()
    meanImagePtNeutral = np.mean(jetImages[:,1,:,:], axis=0)
    print meanImagePtNeutral.shape
    plt.imshow(meanImagePtNeutral)
    plt.colorbar()
    plt.savefig('ptneutral_mean.png')
    
    # plot mean imageMultCharged
    plt.clf()
    meanImageMultCharged = np.mean(jetImages[:,2,:,:], axis=0)
    print meanImageMultCharged.shape
    plt.imshow(meanImageMultCharged)
    plt.colorbar()
    plt.savefig('multcharged_mean.png')

    with open('jetimages.npy', 'wb') as outfile:
        np.save(outfile, jetImages)

def readJetImages():
    
    print 'reading jet images...'
    jetImages = np.load('jetimages.npy')
    print 'jetImages.shape:'
    print jetImages.shape

if __name__ == '__main__':
    #readevent()
    generateJetImages()
    readJetImages()
