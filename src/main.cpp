#include <iostream>
#include <string>
#include "TicTacToe.hpp"

int main() {
	TicTacToe s;
	while (!s.isGameOver()) {
		std::cout << "What action would you like to take?" << std::endl;
		unsigned int action;
		std::cin >> action;
		byte a = (byte)action;
		if (s.validateAction(a)) {
			s.takeAction(a);
		}
		else {
			std::cout << "Invalid action!" << std::endl;
			continue;
		}
		std::cout << *(s.toString()) << std::endl;
		if (s.isGameOver()) break;
		std::cout << "My turn!" << std::endl;
		s.takeBestAction();
		std::cout << *(s.toString()) << std::endl;
	}
}
