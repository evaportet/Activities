#include "Enemy.h"


int main() {

	//Semilla de rand()

	srand(time(nullptr));


	//6

	Enemy enemies[MAX_ENEMIES];


	//7
	
	int i = 0;
	while (i < MAX_ENEMIES)
	{
		enemies[i] = createRandomEnemy();
		int j = i - 1;
		while (j >= 0)
		{
			if (enemies[i] == enemies[j]) { // operador declarado en el header
				i--;
				break;
			}
			--j;
		}
		
		i++;
	}
	

	/*
	for (int i = 0; i < MAX_ENEMIES; i++) {

		enemies[i] = createRandomEnemy();

		for (int j = 0; j < i; j++) {

			if (equalEnemies(enemies[i], enemies[j])) {

				i--;
			}

		}

	}
	*/

	std::cout << "List of enemies: " << std::endl;

	for(const Enemy &i : enemies){
	
		std::cout << i.name << " is a " << getEnemyTypeString(i.type) << " whose life is " << i.health << std::endl;
	}

	system("pause");

	return 0;

}