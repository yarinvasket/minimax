#pragma once

#include <array>
#include "TicTacToe.hpp"
#include <cmath>
using byte = unsigned char;

constexpr Cell[3][3] &toBoard(const unsigned int n) {
	Cell[3][3] board{};
	for (auto i = 0; i < 9; i++) {
		board[i / 3][i % 3] = (n / pow(3, i)) % 3;
	}
	return board;
}

constexpr unsigned int toNum(const Cell[3][3] &board) {
	unsigned int num = 0;
	for (auto i = 0; i < 9; i++) {
		num += board[i / 3][i % 3] * pow(3, i);
	}
	return num;
}

constexpr byte minimaxValue(TicTacToe &t, const std::array<byte, 19683> &lookup) {
	auto idx = toNum(t.m_board);
	if (lookup[idx] < 255) return lookup[idx];

	char c = t.isGameOver();
	if (c) { //Edge cases
		byte val = 1;
		if (c == -1) val = 0;
		else if (c == 1) val = 2;
		T[idx] = val;
		return val;
	}

	char max = -1;
	byte maxAction = 0;
	auto vec = *(t.possibleActions());
	for (auto a : vec) {
		TicTacToe stag(*t, a);
		char ctag = stag.isGameOver();
		if (ctag) {
			if (ctag == -1) {
				T[idx] = 2;
				return 2;
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
		byte minAction;
		auto vectag = *(stag.possibleActions());
		for (auto atag : vectag) {
			TicTacToe stagtag(stag, atag);
			byte stagtagminimaxval = stagtag.minimaxValue();
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

	T[idx] = max;
	return max;
}

constexpr std::array<byte, 19683> calculateLookupTable() {
	std::array<byte, 19683> arr{};
	for (auto i = 0; i < 19683; i++) {
		arr[i] = 255;
	}
	for (auto i = 0; i < 19683; i++) {
		Cell[3][3] board = toBoard(i);
		TicTacToe s(board);
		arr[i] = minimaxValue(s);
	}
	return arr;
}
