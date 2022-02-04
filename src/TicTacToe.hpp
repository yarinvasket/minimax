#pragma once

#include "Cell.hpp"
#include <vector>

using byte = unsigned char;
using sbyte = char;

class TicTacToe {
	public:
		Cell m_board[3][3];
	//	True for player X, false for player O
		bool m_player;
	//	Possible actions
		std::vector<byte> actions;

	//	Build Empty TicTacToe game with starting player X
		TicTacToe();
	//	Copy constructor
		TicTacToe(TicTacToe& s);
	//	Copy TicTacToe game and take action a
		TicTacToe(TicTacToe& s, byte a);

		bool validateAction(byte a);
		void takeAction(byte a);
	//	Take best action using minimax algorithm
		void takeBestAction();
		std::vector<byte>& possibleActions();
};
