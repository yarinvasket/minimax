#include <iostream>
#include <string>
#include <limits>
#include "TicTacToe.hpp"

int main() {
	TicTacToe s;
	while (!s.isGameOver()) {
		unsigned int player;
		while (std::cout << "Bot or player action? [0-bot, 1-player] " && !(std::cin >> player)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input!" << std::endl;
		}

		if (player) {
			unsigned int action;
inp:
			std::cout << "What action would you like to take? ";
			std::cin >> action;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid action!" << std::endl;
				goto inp;
			}
			if (!s.validateAction((byte)action)) {
				std::cout << "Invalid action!" << std::endl;
				goto inp;
			}
			s.takeAction((byte)action);
		}

		else {
			s.takeBestAction();
		}
		std::cout << *(s.toString()) << std::endl;
	}
}
