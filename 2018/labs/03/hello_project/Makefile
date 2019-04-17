CXXFLAGS=-ansi -Wall -Wextra -std=c++17 
LDFLAGS=
OBJECTS=hello.o main.o
HEADERS=hello.h main.h
CC=g++

all:hello

hello: ${OBJECTS}
	${CC} ${LDFLAGS} ${OBJECTS} -o $@

%.o:%.cpp ${HEADERS}
	${CC} ${CXXFLAGS} -c $<

clean:
	rm -f *.o hello
