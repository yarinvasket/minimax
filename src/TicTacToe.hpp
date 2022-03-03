#pragma once

#include "Cell.hpp"
#include "ToNum.hpp"
#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
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
	constexpr TicTacToe() {
		for (byte i = 0; i < 3; i++) {
			for (byte j = 0; j < 3; j++) {
				m_board[i][j] = Cell::BLANK;
			}
		}
	}

//	Copy constructor
	constexpr TicTacToe(TicTacToe& s) {
		for (byte i = 0; i < 3; i++) {
			for (byte j = 0; j < 3; j++) {
				m_board[i][j] = s.m_board[i][j];
			}
		}
		m_player = s.m_player;
	}

//	Copy TicTacToe game and take action a
	constexpr TicTacToe(TicTacToe& s, byte a) : TicTacToe(s) {
		takeAction(a);
	}

//	Take board array and start with player X
	constexpr TicTacToe(std::array<std::array<Cell, 3>, 3> board) {
		for (byte i = 0; i < 3; i++) {
			for (byte j = 0; j < 3; j++) {
				m_board[i][j] = board[i][j];
			}
		}
	}

//	Reverse the game, such that all Xses become Os
	constexpr void reverse() {
		for (byte i = 0; i < 3; i++) {
			for (byte j = 0; j < 3; j++) {
				if (m_board[i][j] == Cell::BLANK) continue;
				else {
//					Turn Xes into Os and Os into Xs
					m_board[i][j] = (Cell)(m_board[i][j] ^ 0b11);
				}
			}
		}
		m_player = !m_player;
	}

	constexpr bool validateAction(byte a) {
		if (a < 0 || a > 8) return false;
		return m_board[a / 3][a % 3] == Cell::BLANK;
	}

	constexpr void takeAction(byte a) {
		m_board[a / 3][a % 3] = m_player ? X : O;
		m_player = !m_player;
	}

//	Take best action using minimax algorithm
	void takeBestAction(const std::array<byte, 19683> &T) {
		if (isGameOver()) return;
		takeAction(T[ToNum::toNum(*this)] / 3);
	}

	constexpr void minimaxValue(std::array<byte, 19683> &T) {
		auto idx = ToNum::toNum(*this);
		if (T[idx] < 255) return;
		auto c = isGameOver();
		if (c) { //Edge cases
			byte val = 1;
			if (c == -1) val = 0;
			if (c == 1) val = 2;
			T[idx] = val;
			return;
		}

		char max = -1;
		byte maxAction = 0;
		for (byte a = 0; a < 9; a++) {
			if (!validateAction(a)) continue;
			TicTacToe stag(*this, a);
			auto ctag = stag.isGameOver();
			if (ctag) {
				if (ctag == -1) {
					T[idx] =  3 * a + 2;
					return;
				}
				if (ctag == 1 && max < 0) {
					max = 0;
					maxAction = a;
				}
				if (ctag == 2 && max < 1) {
					max = 1;
					maxAction = a;
				}
				continue;
			}
			byte min = 3;
			for (byte atag = 0; atag < 9; atag++) {
				if (!stag.validateAction(atag)) continue;
				TicTacToe stagtag(stag, atag);
				stagtag.minimaxValue(T);
				byte stagtagminimaxval = T[ToNum::toNum(stagtag)] % 3;
				if (stagtagminimaxval < min) {
					min = stagtagminimaxval;
				}
			}

			if (min > max) {
				max = min;
				maxAction = a;
			}
		}

		T[idx] = 3 * maxAction + max;
	}

//	Returns 0 if the game is still going, 1 if current player won, -1 if the opposite player won, and 2 if tie
	constexpr char isGameOver() {
		for (byte i = 0; i < 3; i++) {
			if (m_board[i][0] == m_board[i][1] && m_board[i][1] == m_board[i][2]) {
				Cell cell = m_board[i][0];
				if (cell) {
					char ret = 1;
					if (cell == Cell::O) ret = -ret;
					if (!m_player) ret = -ret;
					return ret;
				}
			}

			if (m_board[0][i] == m_board[1][i] && m_board[1][i] == m_board[2][i]) {
				Cell cell = m_board[0][i];
				if (cell) {
					char ret = 1;
					if (cell == Cell::O) ret = -ret;
					if (!m_player) ret = -ret;
					return ret;
				}
			}
		}

		if (m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2]) {
			Cell cell = m_board[0][0];
			if (cell) {
				char ret = 1;
				if (cell == Cell::O) ret = -ret;
				if (!m_player) ret = -ret;
				return ret;
			}
		}

		if (m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0]) {
			Cell cell = m_board[0][2];
			if (cell) {
				char ret = 1;
				if (cell == Cell::O) ret = -ret;
				if (!m_player) ret = -ret;
				return ret;
			}
		}

		for (byte i = 0; i < 3; i++) {
			for (byte j = 0; j < 3; j++) {
				if (!m_board[i][j]) return 0;
			}
		}
		return 2;
	}

	std::unique_ptr<std::string> toString() {
		std::unique_ptr<std::string> s = std::make_unique<std::string>();
		for (byte i = 0; i < 3; i++) {
			for (byte j = 0; j < 3; j++) {
				Cell cell = m_board[i][j];
				*s += cell ?
					cell == Cell::X ? 'X' : 'O' :
					' ';
			}
			*s += '\n';
		}

		return s;
	}
};
