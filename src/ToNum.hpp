#pragma once

#include <array>
#include "Cell.hpp"

namespace ToNum {
	unsigned int intpow(unsigned int base, unsigned int exp);

	unsigned int toNum(const Cell (&board)[3][3]);

	std::array<std::array<Cell, 3>, 3> toBoard(unsigned int num);
}
