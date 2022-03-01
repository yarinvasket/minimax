#pragma once

#include <array>
#include "TicTacToe.hpp"
using byte = unsigned char;

constexpr unsigned int intpow(unsigned int base, unsigned int exp) {
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

constexpr unsigned int toNum(const Cell (&board)[3][3]) {
	unsigned int num = 0;
	for (auto i = 0; i < 9; i++) {
		num += board[i / 3][i % 3] * intpow(3, i);
	}
	return num;
}

constexpr byte minimaxValue(TicTacToe &t, std::array<byte, 19683> &lookup) {
	auto idx = toNum(t.m_board);
	if (lookup[idx] < 255) return lookup[idx];

	char c = t.isGameOver();
	if (c) { //Edge cases
		byte val = 1;
		if (c == -1) val = 0;
		else if (c == 1) val = 2;
		lookup[idx] = val;
		return val;
	}

	char max = -1;
	byte maxAction = 0;
	for (auto i = 0; i < 9; i++) {
		if (!t.validateAction(i)) continue;
		TicTacToe stag(t, i);
		char ctag = stag.isGameOver();
		if (ctag) {
			if (ctag == -1) {
				lookup[idx] = 2;
				return 2;
			}
			if (ctag == 1 && max < 0) {
				max = 0;
				maxAction = i;
			}
			if (ctag == 2 && max < 1) {
				max = 1;
				maxAction = i;
			}
			continue;
		}
		byte min = 3;
		byte minAction = 0;
		for (auto j = 0; j < 9; j++) {
			if (!stag.validateAction(j)) continue;
			TicTacToe stagtag(stag, i);
			byte stagtagminimaxval = minimaxValue(t, lookup);
			if (stagtagminimaxval < min) {
				min = stagtagminimaxval;
				minAction = j;
			}
		}

		if (min > max) {
			max = min;
			maxAction = i;
		}
	}

	lookup[idx] = max;
	return max;
}

constexpr std::array<byte, 19683> calculateLookupTable() {
	std::array<byte, 19683> arr{};
	for (auto i = 0; i < 19683; i++) {
		arr[i] = 255;
	}
	for (auto i = 0; i < 19683; i++) {
		Cell board[3][3]{};
		for (auto j = 0; j < 9; j++) {
			board[j / 3][j % 3] = (Cell)((i / intpow(3, j)) % 3);
		}
	//	TicTacToe s(board);
		TicTacToe s = TicTacToe();
		for (auto i = 0; i < 9; i++) {
			s.m_board[i / 3][i % 3] = board[i / 3][i % 3];
		}
		arr[i] = minimaxValue(s, arr);
	}
	return arr;
}
