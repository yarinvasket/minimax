FLAGS = -Ofast
cc = g++

all : bin/TicTacToe.o src/main.cpp
	$(cc) $(FLAGS) -o bin/main.out src/main.cpp bin/TicTacToe.o

debug : FLAGS = -g
debug : all

bin/TicTacToe.o : src/TicTacToe.hpp src/TicTacToe.cpp
	mkdir -p bin
	$(cc) $(FLAGS) -c -o bin/TicTacToe.o src/TicTacToe.cpp

.PHONY : clean
clean :
	-rm -r bin
