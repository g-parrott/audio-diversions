all: test.o
	clang++ test.o -lSDL2 -o test

test.o: test.cpp
	clang++ -c -std=c++14 test.cpp
