#pragma once

struct Board
{
	enum class Types {
		PIEDRA = 'X',
		MONEDA = '$',
		CLEAR = ' ',
		PLAYER = 'P'
	};

	int currentCoins{ 0 };

	Types** board;
	int numRows;
	int numColumns;


	void initializeBoard(Player& p1) {		

		std::cout << "Escribe el numero de filas que quieres que tenga tu tablero : " << std::endl;
		std::cin >> numRows;
		std::cout << "Escribe el numero de columnas que quieres que tenga tu tablero: " << std::endl;
		std::cin >> numColumns;

		std::cout << "GAME" << std::endl;
		std::cout << std::endl;

		std::cout << std::endl;
		std::cout << "SCORE: " << p1.score << std::endl;
		std::cout << std::endl;

		int maxBox{ numRows * numColumns };

		board = new Types * [numRows];
		for (int i = 0; i < numRows; i++) {
			board[i] = new Types[numColumns];
		}

		int currentPiedras{ 0 };		

		int maxPiedras{ (20 * maxBox) / 100 }; //20%
		int maxMonedas{ (30 * maxBox) / 100 }; //30%

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numColumns; j++) {
				switch (getRandomTypeCell())
				{
				case Types::CLEAR:
					board[i][j] = Types::CLEAR;
					break;
				case Types::PIEDRA:
					if (currentPiedras < maxPiedras) {
						board[i][j] = Types::PIEDRA;
						currentPiedras++;
					}
					else {
						board[i][j] = Types::CLEAR;
					}
					break;
				case Types::MONEDA:
					if (currentCoins < maxMonedas) {
						board[i][j] = Types::MONEDA;
						currentCoins++;
					}
					else {
						board[i][j] = Types::CLEAR;
					}
					break;
				default:
					board[i][j] = Types::CLEAR;
					break;
				}
			}
		}

		/*
		for (int i = 0; i < nColumns; i++) {
			for (int j = 0; j < nRows; j++) {
				board[j][i] = static_cast<Types>(rand() % Types::COUNT);
				if (board[j][i] == Types::PIEDRA) {
					currentPiedras++;
				}
				else if (board[j][i] == Types::MONEDA) {
					currentCoins++;
				}
				if (board[j][i] == Types::PIEDRA && currentPiedras > maxPiedras || board[j][i] == Types::MONEDA && currentCoins > maxMonedas) {
					j--;
				}
			}
		}
		*/
		/*
		int i = 0;
		while (i < nColumns)
		{
			int j = 0;

			while (j < nRows)
			{
				board[i][j] = static_cast<Types>(rand() % Types::COUNT);
				if (board[i][j] == Types::PIEDRA) {
					currentPiedras++;
				}
				else if (board[i][j] == Types::MONEDA) {
					currentCoins++;
				}

				if (board[i][j] == Types::PIEDRA && currentPiedras > maxPiedras || board[i][j] == Types::MONEDA && currentCoins > maxMonedas) {
					--j;
					break;
				}
				
				++j;
			}

			++i;
		}
		*/
		p1.score = { 0 };
		p1.pos.row = { rand() % numRows };
		p1.pos.column = { rand() % numColumns };

		board[p1.pos.row][p1.pos.column] = Types::PLAYER;

	}

	Types getRandomTypeCell() {
		int rnd = rand() % 100;

		if (rnd < 20) return Types::PIEDRA;
		else if (rnd < 50) return Types::MONEDA;
		return Types::CLEAR;
	}

	bool checkMovement(const Player& player, const Movement& m) {
		switch (m)
		{
		case Movement::UP:
			if (player.pos.row == 0 || board[player.pos.row - 1][player.pos.column] == Types::PIEDRA) {
				return false;
			}
			else {
				return true;
			}
		case Movement::DOWN:
			if (player.pos.row == numRows - 1 || board[player.pos.row + 1][player.pos.column] == Types::PIEDRA) {
				return false;
			}
			else {
				return true;
			}
		case Movement::LEFT:
			if (player.pos.column == 0 || board[player.pos.row][player.pos.column - 1] == Types::PIEDRA) {
				return false;
			}
			else {
				return true;
			}
		case Movement::RIGHT:
			if (player.pos.column == numColumns - 1 || board[player.pos.row][player.pos.column + 1] == Types::PIEDRA) {
				return false;
			}
			else {
				return true;
			}
		default:
			break;
		}
		/*
		return (player.pos.row == 0 && m != Movement::UP ||
			player.pos.row == numRows - 1 && m != Movement::DOWN ||
			player.pos.column == 0 && m != Movement::LEFT ||
			player.pos.column == numColumns - 1 && m != Movement::RIGHT ||
			board[player.pos.row - 1][player.pos.column] == Types::PIEDRA && m != Movement::UP ||
			board[player.pos.row + 1][player.pos.column] == Types::PIEDRA && m != Movement::DOWN ||
			board[player.pos.row][player.pos.column - 1] == Types::PIEDRA && m != Movement::LEFT ||
			board[player.pos.row][player.pos.column + 1] == Types::PIEDRA && m != Movement::RIGHT);
			*/
	}

	bool existsCoin(const Player& p, const Movement& m) {

		switch (m)
		{
		case Movement::UP:
			if (board[p.pos.row - 1][p.pos.column] == Types::MONEDA) {
				board[p.pos.row - 1][p.pos.column] == Types::CLEAR;
				return true;
			}
			else {
				return false;
			}
		case Movement::DOWN:
			if (board[p.pos.row + 1][p.pos.column] == Types::MONEDA) {
				board[p.pos.row + 1][p.pos.column] == Types::CLEAR;
				return true;
			}
			else {
				return false;
			}
		case Movement::LEFT:
			if (board[p.pos.row][p.pos.column - 1] == Types::MONEDA) {
				board[p.pos.row][p.pos.column - 1] == Types::CLEAR;
				return true;
			}
			else {
				return false;
			}
		case Movement::RIGHT:
			if (board[p.pos.row][p.pos.column + 1] == Types::MONEDA) {
				board[p.pos.row][p.pos.column + 1] == Types::CLEAR;
				return true;
			}
			else {
				return false;
			}
		default:
			break;
		}

		/*
		return (board[p.pos.row - 1][p.pos.column] == Types::MONEDA && m == Movement::UP ||
			board[p.pos.row + 1][p.pos.column] == Types::MONEDA && m == Movement::DOWN ||
			board[p.pos.row][p.pos.column - 1] == Types::MONEDA && m == Movement::LEFT ||
			board[p.pos.row][p.pos.column + 1] == Types::MONEDA && m == Movement::RIGHT);
			*/
	}

	void movePlayer(Player& p, const Movement& m) {
		if (checkMovement(p, m)) {
			board[p.pos.row][p.pos.column] = Types::CLEAR;
			switch (m)
			{
			case Movement::LEFT:
				p.pos.column--;
				break;
			case Movement::RIGHT:
				p.pos.column++;
				break;
			case Movement::UP:
				p.pos.row--;
				break;
			case Movement::DOWN:
				p.pos.row++;
				break;
			default:
				break;
			}
			p.setPos(p.pos);
			board[p.pos.row][p.pos.column] = Types::PLAYER;
		}
	}

	bool gameOver() {
		return (currentCoins <= 0);
	}

	void printBoard() {

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numColumns; j++) {
				std::cout << static_cast<char>(board[i][j]);
				std::cout << ' ';
				if (j == numColumns - 1) {
					std::cout << std::endl;
				}
			}
		}
	}
};

