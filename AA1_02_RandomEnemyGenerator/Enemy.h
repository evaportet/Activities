#pragma once
#include <iostream>
#include <ctime>
#include <string>

const int MAX_ENEMIES{ 5 };

//1

enum class EnemyType {
	ZOMBIE,
	VAMPIRE,
	GHOST,
	WITCH
};

std::string getEnemyTypeString(EnemyType type) {

	switch (type)
	{
	case EnemyType::ZOMBIE:
		return "zombie";
	case EnemyType::VAMPIRE:
		return "vampire";
	case EnemyType::GHOST:
		return "ghost";
	case EnemyType::WITCH:
		return "witch";
	default:
		return "";
	}

	/*
	if (e == EnemyType::ZOMBIE) {
		return "ZOMBIE";
	}
	else if (e == EnemyType::VAMPIRE) {
		return "VAMPIRE";
	}
	else if (e == EnemyType::GHOST) {
		return "GHOST";
	}
	else if (e == EnemyType::WITCH) {
		return "WITCH";
	}
	else {
		return "Enemy name not found!!!";
	}
	*/
}

struct Enemy
{
	EnemyType type;
	std::string name;
	int health;
};

bool equalEnemies(Enemy e1, Enemy e2) {
	
	return (e1.name == e2.name && e1.type == e2.type);
	
	/*
	if (a.name == b.name && a.type == b.type) {
		return true;
	}
	else {
		return false;
	}
	*/
}


//SOBRECARGA DE OPERADORES
bool operator== (const Enemy &e1, const Enemy &e2) {
	return e1.name == e2.name && e1.type == e2.type;
}

Enemy createRandomEnemy() {

	//Creamos el array con los posibles nombres de enemigos
	const std::string NAMES[MAX_ENEMIES]{ "Eva", "Jan", "Tona", "Jandro", "Aniol" };

	//Función del random
	//srand(time(nullptr));
	return { static_cast<EnemyType> (rand() % 4), NAMES[rand() % MAX_ENEMIES], rand() % 100 + 1 };
}


