#include "Pjet.h"

ClassImp(Pjet)

Pjet::Pjet():TObject() {;}

Pjet::Pjet( TLorentzVector p4, VecPtrack constituents ):TObject() {
    mFourMomentum = p4;
    mConstituents = constituents;
}

Pjet::Pjet( Pjet& other ) {
    mFourMomentum = other.fourMomentum();
    mConstituents = other.constituents();
}

Pjet::~Pjet() {

    //delete the constituents
    //for (VecPtrackIterator it = mConstituents.begin(); it != mConstituents.end(); it++ ) {
    //    delete(*it);
    //}
    mConstituents.clear();
}

void Pjet::Print( const Option_t* opt ) const { 
    cout << *this << endl;
    for (VecPtrackConstIterator it = mConstituents.begin(); 
            it != mConstituents.end(); it++) {
        cout << "\t"; 
        (*it)->Print();
    }
}

void Pjet::Clear( Option_t* opt ) {

    mFourMomentum.SetPxPyPzE(0., 0., 0., 0.);
    //for (VecPtrackIterator it = mConstituents.begin(); it != mConstituents.end(); it++ ) {
    //    delete(*it);
    //} //do not delete the Ptracks
    mConstituents.clear(); //only delete the pointers to Ptracks
}

ostream& operator<<( ostream& os, const Pjet& v ) {
    
    return os << "Pjet:\n\tfourMomentum (P, eta, phi, E): (" << v.fourMomentum().P()
              << "," << v.fourMomentum().Eta()
              << "," << v.fourMomentum().Phi()
              << "," << v.fourMomentum().E()
              << ")\n\tnumber of constituents: " << v.constituents().size()
              <<"\n";
}
