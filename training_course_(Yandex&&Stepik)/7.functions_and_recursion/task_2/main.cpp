/*   Даны четыре действительных числа: x1, y1, x2, y2. Напишите функцию distance(x1, y1, x2, y2), вычисляющую расстояние между точкой (x1. y1) и (x2, y2). Считайте четыре действительных числа и выведите результат работы этой функции.

Формат входных данных
Вводятся четыре действительных числа.
Формат выходных данных
Выведите ответ на задачу.
Тестовые данные
№ Теста              1

Входные данные       0
                     0
                     1
                     1

Выходные данные   1.41421
*/



#include <iostream>
#include <cmath>
#include <iomanip>
double distance(double x1, double x2, double y1, double y2) {
    return std::sqrt(std::pow(std::abs(x1 - x2), 2) + std::pow(std::abs(y1 - y2), 2));
}

int main() {
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    std::cin >> x1 >> y1 >> x2 >> y2;
    double interval = distance(x1, x2, y1, y2);
    std::cout << interval;
    return 0;
}