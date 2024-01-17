CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
SFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
DEPS = RandomWriter.hpp
LIBS = -lboost_unit_test_framework


all: TextWriter test lint

RandomWriter.o: RandomWriter.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

TextWriter.o: TextWriter.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<
	
TextWriter: TextWriter.o RandomWriter.o
	$(CC) -o $@ $^

test.o: test.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<
	
test: test.o RandomWriter.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

lint:
	cpplint --filter=-runtime/references,-build/c++11,-build/include_subdir,--root=. *.cpp *.hpp
	
clean:
	rm *.o test TextWriter
