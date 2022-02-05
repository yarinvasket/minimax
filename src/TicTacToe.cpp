#include "TicTacToe.hpp"
#include <cstddef>
#include "Cell.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

TicTacToe::TicTacToe() {
	for (byte i = 0; i < 3; i++) {
		for (byte j = 0; j < 3; j++) {
			m_board[i][j] = Cell::BLANK;
		}
	}
	m_player = true;
}

TicTacToe::TicTacToe(TicTacToe& s) {
	for (byte i = 0; i < 3; i++) {
		for (byte j = 0; j < 3; j++) {
			m_board[i][j] = s.m_board[i][j];
		}
	}
	m_player = s.m_player;
}

TicTacToe::TicTacToe(TicTacToe& s, byte a) : TicTacToe::TicTacToe(s) {
	takeAction(a);
}

bool TicTacToe::validateAction(byte a) {
	return m_board[a / 3][a % 3] == Cell::BLANK;
}

void TicTacToe::takeAction(byte a) {
	m_board[a / 3][a % 3] = m_player ? X : O;
	m_player = !m_player;
}

void TicTacToe::takeBestAction() {
	if (isGameOver()) return;
	auto actionval = minimaxValue();
	byte action = actionval >> 8;
	takeAction(action);
}

short TicTacToe::minimaxValue() {
	char c = isGameOver();
	if (c) { //Edge cases
		if (c == -1) return 0;
		if (c == 1) return 2;
		return 1;
	}

	byte max = 0;
	byte maxAction;
	auto vec = *possibleActions();
	for (auto a : vec) {
		TicTacToe stag(*this, a);
		char ctag = stag.isGameOver();
		if (ctag) {
			if (ctag == -1) return ((short)a << 8) | 2;
			if (1 > max) {
				max = 1;
				maxAction = a;
			}
			continue;
		}
		byte min = 2;
		byte minAction;
		auto vectag = *(stag.possibleActions());
		for (auto atag : vectag) {
			TicTacToe stagtag(stag, atag);
			byte stagtagminimaxval = stagtag.minimaxValue() & 255;
			if (stagtagminimaxval < min) {
				min = stagtagminimaxval;
				minAction = atag;
			}
		}

		if (min > max) {
			max = min;
			maxAction = a;
		}
	}

	return ((short)maxAction << 8) | max;
}

std::shared_ptr<std::vector<byte>> TicTacToe::possibleActions() {
	std::shared_ptr<std::vector<byte>> actions = std::make_shared<std::vector<byte>>();
	for (byte i = 0; i < 9; i++) {
		if (validateAction(i)) {
			actions->push_back(i);
		}
	}

	return actions;
}

char TicTacToe::isGameOver() {
	for (byte i = 0; i < 3; i++) {
		if (m_board[i][0] == m_board[i][1] == m_board[i][2]) {
			Cell cell = m_board[i][0];
			if (cell) {
				char ret = 1;
				if (cell == Cell::O) ret = -ret;
				if (!m_player) ret = -ret;
				return ret;
			}
		}

		if (m_board[0][i] == m_board[1][i] == m_board[2][i]) {
			Cell cell = m_board[0][i];
			if (cell) {
				char ret = 1;
				if (cell == Cell::O) ret = -ret;
				if (!m_player) ret = -ret;
				return ret;
			}
		}
	}

	if (m_board[0][0] == m_board[1][1] == m_board[2][2]) {
		Cell cell = m_board[0][0];
		if (cell) {
			char ret = 1;
			if (cell == Cell::O) ret = -ret;
			if (!m_player) ret = -ret;
			return ret;
		}
	}

	if (m_board[0][2] == m_board[1][1] == m_board[2][0]) {
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

std::shared_ptr<std::string> TicTacToe::toString() {
	std::shared_ptr<std::string> s = std::make_shared<std::string>();
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
