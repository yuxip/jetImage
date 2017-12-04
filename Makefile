# deal with pythia
PROJECTDIR = /home/osboxes/bjet

PYTHIADIR   = $(PROJECTDIR)/pythia8223
PYTHIAFLAGS = -I$(PYTHIADIR)/include 
PYTHIALIBS  = -Wl,-rpath,$(PYTHIADIR)/lib -L$(PYTHIADIR)/lib -lpythia8

# deal with fastjet
FASTJETDIR  = $(PROJECTDIR)/fastjet-install
FASTJETARGS = `$(FASTJETDIR)/bin/fastjet-config --cxxflags --libs --plugins`

# deal with ROOT
ROOTDIR = $(PROJECTDIR)/root-install
ROOTARGS = `$(ROOTDIR)/bin/root-config --cflags --ldflags --libs`
ROOTCFLAGS = `$(ROOTDIR)/bin/root-config --cflags`
ROOTGLIBS = `$(ROOTDIR)/bin/root-config --glibs`

# local library
LOCALDIR = $(PROJECTDIR)/jet-fast
LOCALLIBS = -Wl,-rpath,$(LOCALDIR) -L$(LOCALDIR) -lPevent
#LOCALLIBS = -L$(LOCALDIR) -lPjet


# pythia together with root and fastjet
all: generate_jets
generate_jets: generate_jets.cc libPevent.so
	g++ -o generate_jets generate_jets.cc $(PYTHIAFLAGS) $(LOCALLIBS) $(PYTHIALIBS) $(FASTJETARGS) $(ROOTARGS)

libPevent.so: Ptrack.h Ptrack.cpp Pjet.h Pjet.cpp Pevent.h Pevent.cpp PeventDict.cpp
	g++ Pevent.cpp Pjet.cpp Ptrack.cpp PeventDict.cpp -shared $(ROOTCFLAGS) -fPIC -g $(ROOTGLIBS) -o $@

PeventDict.cpp: Ptrack.h Pjet.h Pevent.h PeventLinkDef.h
	@echo "Generating dictionary $@..."
	@rootcint -f $@ -c Ptrack.h Pjet.h Pevent.h PeventLinkDef.h
	@echo "$@ done..."

.PHONY: clean
clean:
	rm -f generate_jets
	rm -f *.so
	rm -f *.o
	rm -f PeventDict*
