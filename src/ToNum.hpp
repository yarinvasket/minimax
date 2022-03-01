#pragma once

#include <array>

unsigned int intpow(unsigned int base, unsigned int exp) {
	unsigned int out = 1;
	while (exp) {
		if (exp & 1) {
			out *= base;
		}
		base *= base;
		exp >>= 1;
	}

	return out;
}

unsigned int toNum(const Cell (&board)[3][3]) {
	unsigned int num = 0;
	for (auto i = 0; i < 9; i++) {
		num += board[i / 3][i % 3] * intpow(3, i);
	}
	return num;
}

std::array<std::array<byte, 3>, 3> toBoard(unsigned int num) {
	std::array<std::array<byte, 3>, 3> board;
	for (auto i = 0; i < 9; i++) {
		board[i / 3][i % 3] = (Cell)((num / intpow(3, i)) % 3);
	}
	return board;
}
