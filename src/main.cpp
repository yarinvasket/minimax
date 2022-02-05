#include <iostream>
#include <string>
#include "TicTacToe.hpp"

int main() {
	TicTacToe s;
	s.takeBestAction();
	auto str = *s.toString();
	std::cout << str << std::endl;
}
