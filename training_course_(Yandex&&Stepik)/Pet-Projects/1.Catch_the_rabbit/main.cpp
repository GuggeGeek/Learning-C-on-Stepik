#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(0));
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	

	while (true) {
		std::cout << "Добро пожаловать в игру {Поймай кролика} " << std::endl << " Суть игры: Вы выбираете игровое поле y на x клеток. Вы выбираете координаты клетки (y , x ) и если вы нажали на клетку где кролика нет , то игра пподскажет вам направление. Игра продолжается до тех пор , пока вы не выберете клетку с {Кроликом}";
		std::cout << std::endl << "Выберите пожалуйста размер поля ( укажите цифру варианта ( 1 или 2 или 3 ))" << std::endl << "1. 10х10" << std::endl << "2. 30х30" << std::endl << "3. 50х50" << std::endl;
		
		int P = 0; // Р это вариант поля
		int x = 0, y = 0 , x2 = 0 , y2 = 0; // Координаты кролика , x2 y2 координаты удара по кролику
		
		std::cin >> P;
		
		if (P != 1 && P != 2 && P != 3) {
			std::cout << "Пожалуйста выберите ЦИФРУ варианта поля " << std::endl;
			continue;
		}
		
		std::vector <std::vector <int>> Matrix;

		if (P == 1) {
			P = 10;
			for (int i = 0; i < P; i++) {
				std::vector <int> row( P , 0 ); //Row имя массива , а P количество ячеек , 0 - это значение каждой ячейки
				Matrix.push_back(row);
			}
			x = std::rand() % 10;
			y = std::rand() % 10;
			for (int i = P - 1; i >= 0; i--) {
				for (int l = 0; l < P; l++) {
					if ( Matrix [i][l] == 0 ) {
						std::cout << ".";
					}
				}
				std::cout << std::endl;
			}
		}
		else if (P == 2) {
			P = 30;
			for (int i = 0; i < P; i++) {
				std::vector <int> row(P, 0); //Row имя массива , а P количество ячеек , 0 - это значение каждой ячейки
				Matrix.push_back(row);
			}
			x = std::rand() % 30;
			y = std::rand() % 30;
			for (int i = P - 1; i >= 0; i--) {
				for (int l = 0; l < P; l++) {
					if (Matrix[i][l] == 0) {
						std::cout << ".";
					}
				}
				std::cout << std::endl;
			}
			
		}
		else if (P == 3) {
			P = 50;
			for (int i = 0; i < P; i++) {
				std::vector <int> row(P, 0); //Row имя массива , а P количество ячеек , 0 - это значение каждой ячейки
				Matrix.push_back(row);
			}
			x = std::rand() % 50;
			y = std::rand() % 50;
			for (int i = P - 1; i >= 0; i--) {
				for (int l = 0; l < P; l++) {
					if (Matrix[i][l] == 0) {
						std::cout << ".";
					}
				}
				std::cout << std::endl;
			}
		}
		
		
		while (true) {
			std::cout << "Пожалуйста выберите ту клетку , в которой по вашему мнению прячется кролик , формат: ( x y ) 2 числа через пробел ,  !!! подсчет клеточек начинается с 0 !!!" << std::endl;
			// Игрок вводит сначала x (горизонталь/столбец), потом y (вертикаль/строка)
			// В матрице: строка=x, столбец=y, поэтому свапаем ввод
			int vvod_x, vvod_y;
			std::cin >> vvod_x >> vvod_y;
			x2 = vvod_y; // строка матрицы
			y2 = vvod_x; // столбец матрицы
			if (vvod_x >= P || vvod_y >= P || vvod_x < 0 || vvod_y < 0) {
				std::cout << "Хммм... похоже , что такой клетки нет на карте" << std::endl;
				continue;
			}
			
			if ( x == x2 && y == y2 ) {
				std::cout << "Кролик в шляпе!" << std::endl;
				Matrix[x][y] = 2;
				for (int i = P - 1; i >= 0; i--) {
					for (int l = 0; l < P; l++) {
						if (Matrix[i][l] == 0) {
							std::cout << ".";
						}
						if (Matrix[i][l] == 1) {
							std::cout << "*";
						}
						if (Matrix[i][l] == 2) {
							std::cout << " & ";
						}
					}
					std::cout << std::endl;
				}
				break;
			}
			
			// x2 это строка: большая строка = выше на экране (рисуем i=P-1..0)
			if (x2 != x) {
				if (x2 > x) {
					std::cout << "Ниже!" << std::endl;
				}
				else {
					std::cout << "Выше!" << std::endl;
				}
			}

			// y2 это столбец: большой столбец = правее на экране
			if (y2 != y) {
				if ( y2 > y ) {
					std::cout << "Левее!" << std::endl;
				}
				else {
					std::cout << "Правее!" << std::endl;
				}
			}
			Matrix[x2][y2] = 1;
			for (int i = P - 1; i >= 0; i--) {
				for (int l = 0; l < P; l++) {
					if (Matrix[i][l] == 0) {
						std::cout << ".";
					}
					if (Matrix[i][l] == 1) {
						std::cout << "*";
					}
				}
				std::cout << std::endl;
			}

		}
		std::cout << "Ещё разок? " << std::endl << "1 - Да" << std::endl << "2 - Нет";
		int Ag = 0;
		std::cin >> Ag;
		if ( Ag == 2 ) {
			return 0;
		}
	}
	return 0;
}