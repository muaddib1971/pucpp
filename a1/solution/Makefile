###############################################################################
# Author Name: Paul Miller
# Author ID: E70949
# File Name: Makefile
# All copyright in this material resides with RMIT University.
###############################################################################
SOURCES=list.cpp main.cpp reader.cpp saver.cpp tree.cpp
HEADERS=list.h main.h reader.h saver.h tree.h
CXXFLAGS=-Wall -pedantic -std=c++17 -g
LXXFLAGS=-lboost_system -lboost_program_options
LISTOBJS=list.o main.o reader.o saver.o
TREEOBJS=tree.o main.o reader.o saver.o
STDLISTOBJS=main.o reader.o saver.o
SETOBJS=main.o reader.o saver.o
VECTOROBJS=main.o reader.o saver.o
EXES=listsorter treesorter stdlistsorter setsorter vectorsorter

listsorter:CXXFLAGS+=-DUSELIST
listsorter:cleanobjs  $(LISTOBJS)
	g++ $(LISTOBJS) -o $@ $(LXXFLAGS)

treesorter:CXXFLAGS+=-DUSETREE
treesorter:cleanobjs  $(TREEOBJS)
	g++ $(TREEOBJS) -o $@ $(LXXFLAGS)

stdlistsorter:CXXFLAGS+=-DUSESTDLIST
stdlistsorter:cleanobjs  $(STDLISTOBJS)
	g++ $(STDLISTOBJS) -o $@ $(LXXFLAGS)

setsorter:CXXFLAGS+=-DUSESET
setsorter:cleanobjs  $(SETOBJS)
	g++ $(STDLISTOBJS) -o $@ $(LXXFLAGS)

vectorsorter:CXXFLAGS+=-DUSEVECTOR
vectorsorter:cleanobjs  $(VECTOROBJS)
	g++ $(VECTOROBJS) -o $@ $(LXXFLAGS)

%.o: %.c $(HEADERS)
	g++ $(CXXFLAGS) -c $<

.PHONY:cleanobjs
cleanobjs:
	rm -f *.o

.PHONY:clean
clean: cleanobjs
	rm -f $(EXES)
