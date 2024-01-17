CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
SFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
DEPS = CircularBuffer.hpp StringSound.hpp
LIBS = -lboost_unit_test_framework


all: KSGuitarSim test lint

StringSound.o: StringSound.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

KSGuitarSim.o: KSGuitarSim.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<
	
KSGuitarSim: KSGuitarSim.o StringSound.o
	$(CC) -o $@ $^ $(SFLAGS)

test.o: test.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<
	
test: test.o StringSound.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

lint:
	cpplint --filter=-runtime/references,-build/c++11,-build/include_subdir,--root=. *.cpp *.hpp
	
clean:
	rm *.o test KSGuitarSim
