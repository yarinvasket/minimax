FLAGS = -Ofast
cc = g++

all : src/main.cpp
	mkdir -p bin
	$(cc) $(FLAGS) -o bin/main.out src/main.cpp

debug : FLAGS = -g
debug : all

.PHONY : clean
clean :
	-rm -r bin
