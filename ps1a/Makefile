CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
DEPS = FibLFSR.hpp
LIBS = -lboost_unit_test_framework

all: ps1 test lint

main.o: main.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<
	
FibLFSR.o: FibLFSR.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

ps1: main.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ 
	
test.o: test.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<
	
test: test.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

lint:
	cpplint --filter=-runtime/references,-build/c++11,-build/include_subdir,--root=. *.cpp *.hpp
	
clean:
	rm *.o ps1 test
