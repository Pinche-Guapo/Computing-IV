CC = g++
DEP = FibLFSR.hpp
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIB = -lsfml-graphics -lsfml-window -lsfml-system

all: PhotoMagic test

PhotoMagic.o: PhotoMagic.cpp $(DEP)
	$(CC) $(CFLAGS) -o $@ -c $<

FibLFSR.o: FibLFSR.cpp $(DEP)
	$(CC) $(CFLAGS) -o $@ -c $<
	
PhotoMagic: PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

test.o: test.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

test: test.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB) -lboost_unit_test_framework

clean:
	rm *.o PhotoMagic test

