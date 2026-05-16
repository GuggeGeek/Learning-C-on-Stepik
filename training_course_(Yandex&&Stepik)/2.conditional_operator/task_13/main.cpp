/* Дано три числа. Упорядочите их в порядке неубывания.

Формат входных данных
Вводятся три числа.
Формат выходных данных
Выведите ответ на задачу.
Тестовые данные
№ Теста              1
Входные данные   1 , 2 , 1
Выходные данные  1 , 1 , 2
*/



#include <iostream>
using namespace std;

int main() {
    int x = 0, y = 0, z = 0;
    cin >> x >> y >> z;

    if (x <= y && x <= z) {
        if (y <= z) {
            cout << x << " " << y << " " << z;
        }
        else {
            cout << x << " " << z << " " << y;
        }
    }
    else if (y <= x && y <= z) {
        if (x <= z) {
            cout << y << " " << x << " " << z;
        }
        else {
            cout << y << " " << z << " " << x;
        }
    }
    else {
        int ansMin = min(x, y);
        int ansMax = max(x, y);
        cout << z << " " << ansMin << " " << ansMax;
    }
    return 0;
}