#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>

#include "Types.h"

class Panel {

	std::vector<Ball> panel;

public:

	Panel();
	void insert(const int& position, const Ball& ball);
	int verifier(const int& position);
	void deleteThree(const int& position);
	void insertThree();
	Ball GetRandomTypeBall();
	void print(HANDLE hConsole);
	int GetSize();

};