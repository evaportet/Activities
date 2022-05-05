#pragma once

struct Player
{
	int score{0};
	position pos;

	void addScore(int point) {
		score += point;
	}

	void setPos(const position &p) {
		pos = p;
	}

	void print() {
		std::cout << "Player score is: " << score;
	}
};