#pragma once

#include <array>
#include "Cell.hpp"
#include "TicTacToe.hpp"

namespace ToNum {
	constexpr unsigned int toNum(TicTacToe &s);

	constexpr TicTacToe toBoard(unsigned int num);
}
