#include "Pevent.h"

ClassImp(Pevent)

Pevent::Pevent():TObject() {;}

Pevent::Pevent( Pevent& other ) {
    mJets = other.jets();
}

Pevent::~Pevent() {

    //delete the constituents
    //for (VecPjetIterator it = mJets.begin(); it != mJets.end(); it++ ) {
    //    delete(*it);
    //}
    mJets.clear();
}

void Pevent::Print( const Option_t* opt ) const { 
    cout << *this << endl; 
    for (VecPjetConstIterator it = mJets.begin(); it != mJets.end(); it++ ) {
        (*it)->Print();
    } //do not delete the Pjets
}

void Pevent::Clear( Option_t* opt ) {

    //for (VecPjetIterator it = mJets.begin(); it != mJets.end(); it++ ) {
    //    delete(*it);
    //} //do not delete the Pjets
    mJets.clear(); //only delete the pointers to Pjets
}

ostream& operator<<( ostream& os, const Pevent& v ) {
    
    return os << "Pevent:\n\t"
              << "partons:\n\n\t" << v.partons()[0] << "\n\t" << v.partons()[1]
              << "\n\tnumber of jets: " << v.jets().size()
              <<"\n";
}
