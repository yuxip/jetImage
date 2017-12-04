//a class to hold particle-jet info

#ifndef PJET_H
#define PJET_H

#include <iostream>
#include <vector>

#include "TObject.h"
#include "TLorentzVector.h"
#include "Ptrack.h"

using namespace std;

class Pjet : public TObject {

    public:
        
        Pjet();
        Pjet( TLorentzVector p4, VecPtrack constituents );
        Pjet( Pjet& other );
        ~Pjet();

        void Print( const Option_t* opt = "" ) const;
        void Clear( Option_t *opt = "" );

        TLorentzVector fourMomentum() const { return mFourMomentum; }
        VecPtrack constituents() const { return mConstituents; }

        void setFourMomentum( TLorentzVector p4 ) { mFourMomentum = p4; }
        void setConstituents( VecPtrack ptracks ) { mConstituents = ptracks; }

    private:
        
        TLorentzVector mFourMomentum;
        VecPtrack mConstituents;
        
    ClassDef(Pjet, 1)
};

ostream& operator<<(ostream&, const Pjet&);

typedef vector<Pjet*> VecPjet;
typedef VecPjet::iterator VecPjetIterator;
typedef VecPjet::const_iterator VecPjetConstIterator;

#endif
