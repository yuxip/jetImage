//a class to hold pythia event info
//e.g. partonic-pT, type of partons involved in hard-scattering, etc.

#ifndef PEVENT_H
#define PEVENT_H

#include <iostream>
#include <vector>

#include "TObject.h"
#include "TLorentzVector.h"
#include "Pjet.h"

using namespace std;

class Pevent : public TObject {

    public:
        
        Pevent();
        Pevent( Pevent& other );
        ~Pevent();

        void Print( const Option_t* opt = "" ) const;
        void Clear( Option_t *opt = "" );

        VecPjet jets() const { return mJets; }
        const Ptrack* partons() const { return mPartons; }

        void setJets ( VecPjet pjets ) { mJets = pjets; }
        void setPartons ( Ptrack* ppartons ) { 
            mPartons[0] = ppartons[0];
            mPartons[1] = ppartons[1]; 
        }

    private:
        
        //out-going parton info (2 partons)      
        Ptrack mPartons[2];
        VecPjet mJets;

    ClassDef(Pevent, 1)
};

ostream& operator<<(ostream&, const Pevent&);

#endif
