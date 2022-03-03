FLAGS = -Ofast
cc = g++

all : src/main.cpp src/TicTacToe.hpp src/ToNum.hpp src/Cell.hpp src/CalculateLookupTable.hpp
	mkdir -p bin
	$(cc) $(FLAGS) -o bin/main.out src/main.cpp

debug : FLAGS = -g
debug : all

.PHONY : clean
clean :
	-rm -r bin
