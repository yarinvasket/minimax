#pragma once

#include <array>
#include "TicTacToe.hpp"

namespace CalculateLookupTable {
	constexpr std::array<byte, 19683> calculateLookupTable();
}
