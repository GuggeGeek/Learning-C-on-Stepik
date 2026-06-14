/*   Выведите значение наименьшего нечетного элемента списка, а если в списке нет нечетных элементов - выведите число 0.

Формат входных данных

В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
Формат выходных данных
Выведите ответ на задачу.
Тестовые данные
№ Теста                      1					  2

Входные данные               5					  5
					     0 1 2 3 4	         2 4 6 8 10

Выходные данные              1		              0
*/


#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector <int> a;
    for (int l = 0; l < n; l++) {
        int temp = 0;
        std::cin >> temp;
        if (temp % 2 == 1 || temp % 2 == -1) {
            a.push_back(temp);
        }
    }
    if (a.empty()) {
        std::cout << 0;
        return 0;
    }
    else {
        std::sort(a.begin(), a.end());
        std::cout << a[0];
    }
    return 0;
}