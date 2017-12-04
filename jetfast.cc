#include "Pythia8/Pythia.h"
#include "fastjet/ClusterSequence.hh"
#include <TH1F.h>
#include <TFile.h>
#include <cmath>

using namespace Pythia8;
using namespace fastjet;
using namespace std;
  

float pTjetMin = 15.5;
float pTjetMax = 515.5;
int nrange = 500;
float radius = 0.3; // jet cone radius
float DR = radius; // parameter to check if b/c is inside the jet
float min_eta_jet = 0.0; // minimum of |eta|
float max_eta_jet = 2.0; // maximum of |eta|
float etaMax = max_eta_jet; // max rapidity in jet analysis
int partSel = 1; // use all final state particles
int massSel = 2; // use particles real mass in the reconstruction

 
int main() {

  TFile *file = new TFile("Jet_fast.root","RECREATE");
  file->cd();
    
  TH1F *hJetsPart = new TH1F("jet-part", Form("jet pT"), nrange, pTjetMin, pTjetMax);
  TH1F *hJets = new TH1F("jet", Form("jet pT"), nrange, pTjetMin, pTjetMax);
    
  // Generator. Process selection. 
  Pythia pythia;
  // Shorthand for some public members
  Event& event = pythia.event;
  Settings& settings = pythia.settings;
  Info& info = pythia.info;

  // Set up FastJet jet finder, with anti-kT clustering 
  JetDefinition jet_def(antikt_algorithm, radius);
  vector <PseudoJet> fjInputs; /* Fastjet input */

  // Common settings for all the subruns
  // for q, g, b initiated jets, change accordingly
  // jet_q.cmnd, jet_g.cmnd, jet_b.cmnd
  pythia.readFile("jet_q.cmnd");
  
  // Number of events per bin, generated and listed ones.
  int nEvent = 200;
  int nList = 0, nListJets = 3;
  int nBin = 7;
  double pTlimit[8] = {20., 50., 100., 150., 200., 300., 500., 0.};

  // start bin loop
  for (int iBin = 0; iBin < nBin; ++iBin) {
    settings.parm("PhaseSpace:pTHatMin", pTlimit[iBin]);  
    settings.parm("PhaseSpace:pTHatMax", pTlimit[iBin + 1]);
    pythia.init();
    // settings.listChanged();

    // Reset local histograms
    hJetsPart->Reset();
 
    // Begin event loop
    for (int iEvent = 0; iEvent < nEvent; ++iEvent) {
      if (!pythia.next()) continue;
      
      // fastjet analysis
      fjInputs.resize(0);
      for (int i = 0; i < event.size(); ++i) if (event[i].isFinal()) {
	  PseudoJet particle( event[i].px(), event[i].py(), 
			      event[i].pz(), event[i].e() );
	  // add particle charge information into fastjet
	  float charge = event[i].charge();
	  int ic;
	  if(charge > 0) ic = 1;
	  else if(charge < 0) ic = -1;
	  else ic = 0;
	  particle.set_user_index(ic);
	  fjInputs.push_back(particle);
      }
      if(fjInputs.size() == 0) continue;
      vector <PseudoJet> inclusiveJets, sortedJets;
      ClusterSequence clust_seq(fjInputs, jet_def);
      inclusiveJets = clust_seq.inclusive_jets(pTjetMin);
      sortedJets = sorted_by_pt(inclusiveJets);  

      for ( int i = 0; i < sortedJets.size(); ++i ) {
	float phiJet, etaJet;
	phiJet = sortedJets[i].phi();
	etaJet = sortedJets[i].rap();
	if(abs(etaJet) < min_eta_jet) continue;
	if(abs(etaJet) > max_eta_jet) continue;
            
	hJetsPart->Fill( sortedJets[i].pt() );	
	// get the constituents of the jet
	// note: constituents is PseudoJet object, and thus 
	// all the components of PsudoJet can be accessed
	// see fastjet manual page 10, e.g.
	// constituents.phi_std(): azimuthal angle in [-pi, pi]
	// constituents.eta(): pseudo-rapiity
	// constituents.pt(): transverse momentum
	// constituents.user_index(): our user-defined index = charge type 
	// (+1, 0, -1) for positive, neutral, negative charge
	vector <PseudoJet> constituents = sortedJets[i].constituents();
	for (int j = 0; j < constituents.size(); j++) {
	  cout << constituents[j].user_index() <<'\t' 
	       << constituents[j].eta() << '\t' 
	       << constituents[j].pt() << endl;
	}
      }// end of jet loop 
    } // end of event loop. statistics
    pythia.stat();

    // normalized to cross section 
    float sigma = info.sigmaGen()*1.0e9; // total cross section in pb
    float norm = sigma/nEvent * nrange/(pTjetMax - pTjetMin);
    hJets->Add(hJets, hJetsPart, 1, norm);

  } // end of pT-bin loop
  
  file->Write();
  
  return 0;
}
