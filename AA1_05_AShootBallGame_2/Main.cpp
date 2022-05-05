#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

#include "Types.h"
#include "Player.h"
#include "Panel.h"
#include "Inputs.h"

int main() {

	srand(time(nullptr));

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	Panel panel;
	Player player("EVA", rand()% panel.GetSize());
	Input input;	

	bool mapKeys[static_cast<int>(Keys::COUNT)] = { false };

	SetConsoleTextAttribute(hConsole, 15);


	while (!mapKeys[3] && player.GetChargerSize() > 0) {
		
		//input
		input.Update();
		mapKeys[0] = input.Keyboard[static_cast<int>(Keys::LEFT)];
		mapKeys[1] = input.Keyboard[static_cast<int>(Keys::RIGHT)];
		mapKeys[2] = input.Keyboard[static_cast<int>(Keys::FIRE)];
		mapKeys[3] = input.Keyboard[static_cast<int>(Keys::ESC)];

		//update
		if (mapKeys[0]) {
			if (player.GetPosition() != 0) {
				player.SetPosition(player.GetPosition() - 1);
			}
		}

		if (mapKeys[1]) {
			if (player.GetPosition() != panel.GetSize() - 1) {
				player.SetPosition(player.GetPosition() + 1);
			}
		}

		if (panel.verifier(player.GetPosition()) != -1) {   //se puede hacer de manera mucho mas eficiente
			panel.deleteThree(panel.verifier(player.GetPosition()));
			panel.insertThree();
		}

		if (mapKeys[2]) {
			panel.insert(player.GetPosition(), player.shoot());	
		}	

		//print

		panel.print(hConsole);
		std::cout << std::endl;
		player.print(panel.GetSize(), hConsole);

		std::cout << std::endl;
		std::cout << std::endl;

		player.gunPrint(hConsole);

		system("cls");
	}

	std::cout << SetConsoleTextAttribute(hConsole, 15);
	std::cout << std::endl;
	std::cout << "                               (0 0) " << std::endl;
	std::cout << "                       ---oOO-- (_) ----oOO---" << std::endl;
	std::cout << "                     |-------------------------|" << std::endl;
	std::cout << "                     | GAME OVEEEEEEEEEEER!!!! |" << std::endl;
	std::cout << "                     |-------------------------|" << std::endl;
	std::cout << "                        -------------------" << std::endl;
	std::cout << "                              |__|__|" << std::endl;
	std::cout << "                               || ||" << std::endl;
	std::cout << "                              ooO Ooo" << std::endl;
	std::cout << std::endl;

	system("pause");
	return { 0 };
}