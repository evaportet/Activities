#include <string>
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

#include "Player.h"

int Player::GetChargerSize()
{
	return chargerSize;
}

int Player::GetPosition()
{
	return position;
}

void Player::SetPosition(int p)
{
	position = p;
}

Player::Player(const std::string& _name, const int& _position) {
	score = 0;
	name = _name;
	position = _position;
	chargerSize = 50;

	int i{ 0 };

	while (i < chargerSize)
	{
		gun.push_back(GetRandomTypeBall());

		if (i >= 1) {
			if (gun[i] == gun[i - 1]) {
				i--;
			}
			else
			{
				i++;
			}
		}
		
	}
}

Ball Player::GetRandomTypeBall() {
	int temp = rand() % 5;
	switch (temp)
	{
	case 0:
		return Ball::BLUE;
		break;
	case 1:
		return Ball::GREEN;
		break;
	case 2:
		return Ball::ORANGE;
		break;
	case 3:
		return Ball::PURPLE;
		break;
	case 4:
		return Ball::WHITE;
		break;
	default:
		return Ball::WHITE;
		break;
	}
}

Ball Player::shoot() {

	Ball balltoReturn{ gun[0] };
	gun.erase(gun.begin());
	chargerSize--;

	return balltoReturn;
}

Ball Player::getFirstBall() {
	return{ gun[0] };
}

void Player::print(const int& _panelSize, HANDLE hConsole) {
	for (int i = 0; i < _panelSize; i++) {
		if (i == position) {
			std::cout << SetConsoleTextAttribute(hConsole, 238) << " ";
		}
		else {
			std::cout << SetConsoleTextAttribute(hConsole, 0) << " ";
		}
	}
}

void Player::gunPrint(HANDLE hConsole) {
	for (int i = 0; i < chargerSize; i++) {
		std::cout << SetConsoleTextAttribute(hConsole, static_cast<int>(gun[i])) << " ";
	}
	std::cout << SetConsoleTextAttribute(hConsole, 0);
}