#include <array>
#include "ToNum.hpp"
#include "Cell.hpp"

unsigned int ToNum::toNum(const Cell (&board)[3][3]) {
	unsigned int num = 0;
	for (byte i = 0; i < 8; i++) {
		num += board[i / 3][i % 3];
		num *= 3;
	}
	num += board[2][2];
	return num;
}

std::array<std::array<Cell, 3>, 3> ToNum::toBoard(unsigned int num) {
	std::array<std::array<Cell, 3>, 3> board;
	for (auto i = 8; i >= 0; i--) {
		board[i / 3][i % 3] = (Cell)(num % 3);
		num /= 3;
	}
	return board;
}
