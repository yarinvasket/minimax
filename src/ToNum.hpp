#pragma once

#include <array>
#include "Cell.hpp"
#include "TicTacToe.hpp"

namespace ToNum {
	unsigned int toNum(TicTacToe &s);

	TicTacToe toBoard(unsigned int num);
}
