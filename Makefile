FLAGS = -Ofast
cc = g++

all : bin/TicTacToe.o bin/ToNum.o bin/CalculateLookupTable.o src/main.cpp
	$(cc) $(FLAGS) -o bin/main.out src/main.cpp bin/TicTacToe.o bin/ToNum.o bin/CalculateLookupTable.o

debug : FLAGS = -g
debug : all

bin/TicTacToe.o : src/TicTacToe.hpp src/TicTacToe.cpp
	mkdir -p bin
	$(cc) $(FLAGS) -c -o bin/TicTacToe.o src/TicTacToe.cpp

bin/ToNum.o : src/ToNum.cpp src/ToNum.hpp
	mkdir -p bin
	$(cc) $(FLAGS) -c -o bin/ToNum.o src/ToNum.cpp

bin/CalculateLookupTable.o : src/CalculateLookupTable.cpp src/CalculateLookupTable.hpp
	mkdir -p bin
	$(cc) $(FLAGS) -c -o bin/CalculateLookupTable.o src/CalculateLookupTable.cpp

.PHONY : clean
clean :
	-rm -r bin
