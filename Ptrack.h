//a class to hold jet constituent info

#ifndef PTRACK_H
#define PTRACK_H

#include <iostream>
#include <vector>

#include "TObject.h"
#include "TLorentzVector.h"

using namespace std;

class Ptrack : public TObject {

    public:
        Ptrack();
        Ptrack( TLorentzVector p4, Int_t pdgid, Float_t charge );
        Ptrack( Ptrack& other );
        ~Ptrack();

        void Print( const Option_t* opt = "" ) const;
        void Clear( Option_t *opt = "" );

        TLorentzVector fourMomentum() const { return mFourMomentum; }
        Int_t pdgId() const { return mPdgId; }
        Float_t charge() const { return mCharge; }

        void setFourMomentum( TLorentzVector p4 ) { mFourMomentum = p4; }
        void setPdgId( Int_t pdgid ) { mPdgId = pdgid; }
        void setCharge( Float_t charge ) { mCharge = charge; }

    private:
        
        TLorentzVector mFourMomentum;
        Int_t mPdgId;
        Int_t mCharge;

    ClassDef(Ptrack, 1)
};

ostream& operator<<(ostream&, const Ptrack&);

typedef vector<Ptrack*> VecPtrack;
typedef VecPtrack::iterator VecPtrackIterator;
typedef VecPtrack::const_iterator VecPtrackConstIterator;

#endif
