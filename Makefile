FLAGS = -fconstexpr-ops-limit=999999999
cc = g++

default : FLAGS += -Ofast
default : all

debug : FLAGS += -g
debug : all

all : src/main.cpp src/TicTacToe.hpp src/ToNum.hpp src/Cell.hpp src/CalculateLookupTable.hpp
	mkdir -p bin
	$(cc) $(FLAGS) -o bin/main.out src/main.cpp

.PHONY : clean
clean :
	-rm -r bin
