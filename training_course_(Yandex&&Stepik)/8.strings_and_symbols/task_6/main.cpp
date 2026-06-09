/*   Найдите в данной строке самое длинное слово и выведите его.

Входные данные

Вводится одна строка. Слова в ней отделены одним пробелом.

Выходные данные

Выведите самое длинное слово. Если таких слов несколько, то выводить нужно, которое встречается раньше.

Тестовые данные
№ Теста                       1
Входные данные   Everyone of us has all we need
Выходные данные           Everyone

*/



#include <iostream>
#include <string>
#include <vector>
int main() {
    int ds = 0, ks = 0, sm = 0, max = -1; // длинна слова , кол-во слов , номер самого большого слова в массиве
    std::string c;
    std::getline(std::cin, c);
    c += " ";
    std::vector <int> DS;  // вектор хранящий длины слов
    for (auto s : c) {
        if (s != ' ') ds++;
        else {
            DS.push_back(ds);
            ks++;
            ds = 0;
        }
    }
    for (int l = 0; l < ks; l++) {
        if (DS[l] > max) {
            max = DS[l];
            sm = l;
        }
    }

    for (auto s : c) {
        if (s == ' ') sm--;
        if (sm == 0) std::cout << s;
        if (sm == -1) return 0;
    }
    return 0;
}