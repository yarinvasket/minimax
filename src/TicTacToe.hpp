#pragma once

#include "Cell.hpp"
#include <vector>
#include <string>
#include <memory>
#include <array>

using byte = unsigned char;
using sbyte = char;

class TicTacToe {
	public:
		Cell m_board[3][3];
	//	True for player X, false for player O
		bool m_player;

	//	Build Empty TicTacToe game with starting player X
		TicTacToe();
	//	Copy constructor
		TicTacToe(TicTacToe& s);
	//	Copy TicTacToe game and take action a
		TicTacToe(TicTacToe& s, byte a);
	//	Take board array and start with player X
		TicTacToe(std::array<std::array<Cell, 3>, 3> board);

		bool validateAction(byte a);
		void takeAction(byte a);
	//	Take best action using minimax algorithm
		void takeBestAction();
		std::unique_ptr<std::vector<byte>> possibleActions();
		byte minimaxValue(std::array<byte, 19683> &T);

	//	Returns 0 if the game is still going, 1 if current player won, -1 if the opposite player won, and 2 if tie
		char isGameOver();

		std::unique_ptr<std::string> toString();
};
