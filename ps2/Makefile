CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIB = -lsfml-graphics -lsfml-window -lsfml-system
DEP = TFractal.hpp

all: TFractal lint

TFractal.o: TFractal.cpp $(DEP)
	$(CC) $(CFLAGS) -o $@ -c $<

TFractal: TFractal.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

lint:
	cpplint --filter=-runtime/references,-build/header_guard,-build/c++11 --extensions=cpp,hpp

clean:
	rm *.o TFractal