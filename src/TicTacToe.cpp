#include "TicTacToe.hpp"
#include <cstddef>
#include "Cell.hpp"
#include <vector>

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

}

void TicTacToe::takeBestAction() {

}

std::vector<byte>& TicTacToe::possibleActions() {
	return actions;
}
