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

}

std::vector<byte>& TicTacToe::possibleActions() {
	std::shared_ptr<std::vector<byte>> actions = std::make_shared<std::vector<byte>>();
	for (byte i = 0; i < 9; i++) {
		if (validateAction(i)) {
			actions->push_back(i);
		}
	}

	return *actions;
}

char isGameOver() {
	return 'F';
}

std::string& TicTacToe::toString() {
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

	return *s;
}
