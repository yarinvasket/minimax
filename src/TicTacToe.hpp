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
		Cell m_board[3][3] = {};
	//	True for player X, false for player O
		bool m_player = true;

	//	Build Empty TicTacToe game with starting player X
		constexpr TicTacToe();
	//	Copy constructor
		constexpr TicTacToe(TicTacToe& s);
	//	Copy TicTacToe game and take action a
		constexpr TicTacToe(TicTacToe& s, byte a);
	//	Build TicTacToe game with given board and starting player X
		constexpr TicTacToe(const Cell (&board)[3][3]);

		bool validateAction(byte a);
		void takeAction(byte a);
	//	Take best action using minimax algorithm
		void takeBestAction();
		std::unique_ptr<std::vector<byte>> possibleActions();

	//	Returns 0 if the game is still going, 1 if current player won, -1 if the opposite player won, and 2 if tie
		char isGameOver();

		std::unique_ptr<std::string> toString();
};
