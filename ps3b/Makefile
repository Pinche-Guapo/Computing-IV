CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIB = -lsfml-graphics -lsfml-window -lsfml-system

all: NBody lint

main.o: main.cpp universe.hpp
	$(CC) $(CFLAGS) -o $@ -c $<

universe.o: universe.cpp universe.hpp CelestialBody.hpp
	$(CC) $(CFLAGS) -c $<

CelestialBody.o: CelestialBody.cpp CelestialBody.hpp
	$(CC) $(CLFAGS) -c $<

NBody: main.o universe.o CelestialBody.o
	$(CC) $(CLFAGS) -o $@ $^ $(LIB)
	
lint:
	cpplint --filter=-runtime/references,-build/c++11,-build/include_subdir,--root=. *.cpp *.hpp

clean: 
	rm *.o NBody
