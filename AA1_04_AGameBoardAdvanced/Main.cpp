#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "Constants.h"
#include "Types.h"
#include "Player.h"
#include "Board.h"

int main() {

	srand(time(NULL));

	Board b;
	Player p1;
	char movementInput;
	Movement m;

	//Pide filas y columnas

	b.initializeBoard(p1);
	b.printBoard();

	while (!b.gameOver()) {

		//INPUT

		std::cin >> movementInput;
		switch (movementInput) {

		case 'w':
		case 'W':
			m = Movement::UP;
			break;
		case 'a':
		case 'A':
			m = Movement::LEFT;
			break;
		case 's':
		case 'S':
			m = Movement::DOWN;
			break;
		case 'd':
		case 'D':
			m = Movement::RIGHT;
			break;
		case 'x':
		case 'X':
			break;
		default:
			break;
		}

		//UPDATE

		if (b.checkMovement(p1, m)) {
			if (b.existsCoin(p1, m)) {
				b.currentCoins--;
				p1.addScore(1);
			}
		}

		b.movePlayer(p1, m);

		//PRINT

		system("CLS");
		std::cout << "GAME" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "SCORE: " << p1.score << std::endl;
		std::cout << std::endl;
		b.printBoard();		

	}

	std::cout << std::endl;
	std::cout << "GAME OVER !!!" << std::endl;


	system("pause");

}