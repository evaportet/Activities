#pragma once

enum class Movement {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	COUNT
};

struct position
{
	int row;
	int column;
};