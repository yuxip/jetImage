#include "Ptrack.h"

ClassImp(Ptrack)

Ptrack::Ptrack():TObject() {;}

Ptrack::Ptrack( TLorentzVector p4, Int_t pdgid, Float_t charge ):TObject() {
    mFourMomentum = p4;
    mPdgId = pdgid;
    mCharge = charge;
}

Ptrack::Ptrack( Ptrack& other ) {
    mFourMomentum = other.fourMomentum();
    mPdgId = other.pdgId();
    mCharge = other.charge();
}

Ptrack::~Ptrack() {;}

void Ptrack::Print( const Option_t* opt ) const { cout << *this << endl; }

void Ptrack::Clear( Option_t* opt ) {

    mFourMomentum.SetPxPyPzE(0., 0., 0., 0.);
    mPdgId = 9999;
    mCharge = 9999;
}

ostream& operator<<( ostream& os, const Ptrack& v ) {
    
    return os << "Ptrack:\n\tfourMomentum (P, eta, phi, E): (" << v.fourMomentum().P()
              << "," << v.fourMomentum().Eta()
              << "," << v.fourMomentum().Phi()
              << "," << v.fourMomentum().E()
              << ")\n"
              << "\tpdgId: " << v.pdgId()
              << "\tcharge: " << v.charge()
              << "\n";
}
