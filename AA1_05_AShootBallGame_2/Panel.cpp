#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

#include "Panel.h"

int Panel::GetSize()
{
	return panel.size();
}

Panel::Panel() {

	std::cout << "Introduce your size panel: ";
	int size;
	std::cin >> size;
	panel.resize(size);

	panel.at(0) = GetRandomTypeBall();

	int i{ 1 };

	while (i < size)
	{
		panel.at(i) = GetRandomTypeBall();

			if (panel.at(i) == panel.at(i - 1)) {
				i--;
			}
			else
			{
				i++;
			}		
	}
}

void Panel::insert(const int& position, const Ball& ball) {

	panel.insert(panel.begin() + position, ball);

}

int Panel::verifier(const int& position) {
	if (panel[position] == panel[position + 1] && panel[position] == panel[position + 2]) {
		return position;
	}
	else if (panel[position] == panel[position + 1] && panel[position] == panel[position - 1]) {
		return position - 1;
	}
	else if (panel[position] == panel[position - 1] && panel[position] == panel[position - 2]) {
		return position - 2;
	}
	else {
		return { -1 };
	}
}

void Panel::deleteThree(const int& position) {

	panel.erase(panel.begin() + position, panel.begin() + position + 3);

}

void Panel::insertThree() {

	int i{ 0 };

	while (i < 3)
	{
		panel.push_back(GetRandomTypeBall());

		if (i >= 1) {
			if (panel[i] == panel[i - 1]) {
				panel.erase(panel.end());
				i--;
			}
			else
			{
				i++;
			}
		}
	}
}

Ball Panel::GetRandomTypeBall() {
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

void Panel::print(HANDLE hConsole) {
	for (int i = 0; i < panel.size(); i++) {
		std::cout << SetConsoleTextAttribute(hConsole, static_cast<int>(panel[i])) << " ";
	}
	std::cout << SetConsoleTextAttribute(hConsole, 0);
}