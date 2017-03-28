all:treemaker

treemaker:tree.h main.o
	g++ main.o -o treemaker

main.o:main.cpp tree.h
	g++ -Wall -pedantic -std=c++14 -c $<

.PHONY:clean
clean:
	rm -f main.o treemaker
