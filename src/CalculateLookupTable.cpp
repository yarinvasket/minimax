#include "CalculateLookupTable.hpp"
#include "TicTacToe.hpp"
#include "ToNum.hpp"

constexpr std::array<byte, 19683> CalculateLookupTable::calculateLookupTable() {
	std::array<byte, 19683> T{};
	for (unsigned int i = 0; i < 19683; i++) {
		T[i] = 255;
	}
	for (unsigned int i = 0; i < 19683; i++) {
		TicTacToe t(ToNum::toBoard(i));
		t.minimaxValue(T);
	}

	return T;
}
