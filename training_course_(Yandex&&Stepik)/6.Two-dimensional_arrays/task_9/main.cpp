/*   Дан прямоугольный массив размером n×m. Поверните его на 90 градусов по часовой стрелке, записав результат в новый массив размером m×n.

Формат входных данных
Вводятся два числа n и m, не превосходящие 100, затем массив размером n×m.
Формат выходных данных
Выведите получившийся массив. Числа при выводе разделяйте одним пробелом.

Тестовые данные
№ Теста                 1
Входные данные         3 4
                   11 12 13 14
                   21 22 23 24
                   31 32 33 34

Выходные данные      31 21 11 
                     32 22 12 
                     33 23 13 
                     34 24 14
*/



#include <iostream>
#include <vector>
int main() {
    int n = 0, m = 0;
    std::cin >> n >> m; // n строки ,  m столбики
    std::vector<std::vector <int>> Matrix(n, std::vector <int>(m));
    for (int l = 0; l < n; l++) {
        for (int j = 0; j < m; j++) {
            std::cin >> Matrix[l][j];
        }
    }

    std::vector <std::vector <int>> Matrix2;
    for (int j = 0; j < m; j++) {
        std::vector <int> Help;
        for (int l = n - 1; l >= 0; l--) {
            Help.push_back(Matrix[l][j]);
        }
        Matrix2.push_back(Help);
    }

    for (int l = 0; l < m; l++) {
        for (int j = 0; j < n; j++) {
            std::cout << Matrix2[l][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}