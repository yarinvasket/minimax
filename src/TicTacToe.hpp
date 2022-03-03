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
		constexpr TicTacToe();
	//	Copy constructor
		constexpr TicTacToe(TicTacToe& s);
	//	Copy TicTacToe game and take action a
		constexpr TicTacToe(TicTacToe& s, byte a);
	//	Take board array and start with player X
		constexpr TicTacToe(std::array<std::array<Cell, 3>, 3> board);
	//	Reverse the game, such that all Xses become Os
		constexpr void reverse();

		constexpr bool validateAction(byte a);
		constexpr void takeAction(byte a);
	//	Take best action using minimax algorithm
		constexpr void takeBestAction(std::array<byte, 19683> &T);
		constexpr std::unique_ptr<std::vector<byte>> possibleActions();
		constexpr void minimaxValue(std::array<byte, 19683> &T);
		static constexpr std::array<byte, 19683> calculateLookupTable();

	//	Returns 0 if the game is still going, 1 if current player won, -1 if the opposite player won, and 2 if tie
		constexpr char isGameOver();

		std::unique_ptr<std::string> toString();
};
