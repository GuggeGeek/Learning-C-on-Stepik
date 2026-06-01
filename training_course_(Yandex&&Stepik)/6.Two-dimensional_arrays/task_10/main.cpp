/*   По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m “змейкой”, как показано в примере.

Формат входных данных
Вводятся два числа n и m, каждое из которых не превышает 30.
Формат выходных данных
Выведите полученный массив, отводя на вывод каждого элемента ровно 4 символа.

Тестовые данные
№ Теста                     1
Входные данные             3 5
Выходные данные     1   2   3   4   5
                    10   9   8   7   6
                    11  12  13  14  15
*/


#include <iostream>
#include <vector>
int main() {
    int n = 0, m = 0, r = 1;// n = строчки   m = столбики 
    std::cin >> n >> m;
    std::vector <std::vector <int>> Matrix;
    for (int l = 0; l < n; l++) {
        std::vector <int> Help;
        if (l % 2 == 0) {
            for (int j = 0; j < m; j++) {
                Help.push_back(r);
                if (j != m - 1) {
                    r++;
                }
            }
        }
        else {
            for (int j = 0; j < m; j++) {
                Help.push_back(r);
                r--;
            }
        }
        Matrix.push_back(Help);
        if (l % 2 == 0) {
            r = r + m;
        }
        else {
            r = r + m + 1;
        }
    }

    for (int l = 0; l < n; l++) {
        for (int j = 0; j < m; j++) {
            if (Matrix[l][j] / 10 >= 1) {
                std::cout << Matrix[l][j] << "  ";
            }
            else {
                std::cout << " " << Matrix[l][j] << "  ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}