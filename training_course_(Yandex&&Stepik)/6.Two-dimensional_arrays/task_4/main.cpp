/*  Дан двумерный массив и два числа: i и j. Поменяйте в массиве столбцы с номерами i и j
Формат входных данных
Программа получает на вход размеры массива n и m, не превосходящие 100, затем элементы массива, затем числа i и j.
Формат выходных данных
Выведите результат.

Тестовые данные 
№ Теста                  1                       
Входные данные          3 4                 
                    11 12 13 14             
                    21 22 23 24             
                    31 32 33 34
                        0 1

                   Выходные данные          
                    12 11 13 14
                    22 21 23 24
                    32 31 33 34
*/




#include <iostream>
#include <vector>
int main() {
    int y = 0, x = 0, n = 0, p = 0;//x=столбики   y=строчки   n=первый столбик   p= второй столбик
    std::cin >> y >> x;
    std::vector <std::vector<int>> Matrix(y, std::vector <int>(x));

    for (int i = 0; i < y; i++) {
        for (int l = 0; l < x; l++) {
            std::cin >> Matrix[i][l];
        }
    }
    std::cin >> n >> p;
    for (int i = 0; i < y; i++) {
        for (int l = 0; l < x; l++) {
            if (l == n) {
                std::swap(Matrix[i][l], Matrix[i][p]);
            }
        }
    }
    for (int i = 0; i < y; i++) {
        for (int l = 0; l < x; l++) {
            std::cout << Matrix[i][l] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}