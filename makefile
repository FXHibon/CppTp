export CXX=g++
export CXXFLAGS=-g -W -Wall -Werror -pedantic -std=c++11
all: main

main.o:
    $(CXX) $(CXXFLAGS) -c main.cpp
main: main.cpp
    $(CXX) $(CXXFLAGS) main.cpp -o main

clean:
    rm -f main

.PHONY clean
