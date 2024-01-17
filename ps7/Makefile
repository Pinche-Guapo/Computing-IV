CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
SFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
RFLAGS = -lboost_regex -lboost_date_time
DEPS = RandomWriter.hpp
LIBS = -lboost_unit_test_framework


all: ps7 lint

main.o: main.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

ps7: main.o
	$(CC) -o $@ $^ $(RFLAGS)

lint:
	cpplint --filter=-runtime/references,-build/c++11,-build/include_subdir,--root=. main.cpp
	
clean:
	rm *.o ps7 *.rpt
