#include <array>
#include "ToNum.hpp"
#include "TicTacToe.hpp"
#include "Cell.hpp"

unsigned int ToNum::toNum(TicTacToe &s) {
	TicTacToe rev(s);
	if (!rev.m_player) rev.reverse();
	unsigned int num = 0;
	for (byte i = 0; i < 8; i++) {
		num += rev.m_board[i / 3][i % 3];
		num *= 3;
	}
	num += rev.m_board[2][2];
	return num;
}

TicTacToe ToNum::toBoard(unsigned int num) {
	TicTacToe s;
	for (char i = 8; i >= 0; i--) {
		s.m_board[i / 3][i % 3] = (Cell)(num % 3);
		num /= 3;
	}
	s.m_player = true;
	return s;
}
