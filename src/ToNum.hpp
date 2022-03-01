#pragma once

#include <array>
#include "Cell.hpp"
#include "TicTacToe.hpp"

namespace ToNum {
	unsigned int toNum(const Cell (&board)[3][3]);

	std::array<std::array<Cell, 3>, 3> toBoard(unsigned int num);
}
