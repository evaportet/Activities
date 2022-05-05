#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>

#include "Types.h"

class Player {

	std::string name;
	int position;
	int chargerSize;
	int score;	

	std::vector<Ball> gun;

public:

	Player(const std::string& _name, const int& _position);
	Ball GetRandomTypeBall();
	Ball shoot();
	Ball getFirstBall();
	void print(const int& _panelSize, HANDLE hConsole);
	void gunPrint(HANDLE hConsole);
	int GetChargerSize();
	int GetPosition();
	void SetPosition(int p);

};