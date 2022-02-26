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
			while (std::cout << "What action would you like to take? " &&
			!(std::cin >> action) &&
			!s.validateAction((byte)action)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid action!" << std::endl;
			}
			s.takeAction((byte)action);
		}
		else {
			s.takeBestAction();
		}
		std::cout << *(s.toString()) << std::endl;
	}
}
