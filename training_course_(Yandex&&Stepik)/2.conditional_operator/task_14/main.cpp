/* Есть две коробки, первая размером A1×B1×C1, вторая размером A2×B2×C2. Определите, можно ли разместить одну из этих коробок внутри другой, при условии, что поворачивать коробки можно только на 90 градусов вокруг ребер.

Формат входных данных
Программа получает на вход числа A1, B1, C1, A2, B2, C2.
Формат выходных данных
Программа должна вывести одну из следующих строчек:
Boxes are equal, если коробки одинаковые,
The first box is smaller than the second one, если первая коробка может быть положена во вторую,
The first box is larger than the second one, если вторая коробка может быть положена в первую,
Boxes are incomparable, во всех остальных случаях.
Тестовые данные
№ Теста                    1                           2
Входные данные   1 , 2 , 3 , 3 , 2 , 1   :   2 , 2 , 3 , 3 , 2 , 1
Выходные данные     Boxes are equal          the first box is larger than the second one
*/


#include <iostream>
using namespace std;

int main() {
    int A1 = 0, B1 = 0, C1 = 0, A2 = 0, B2 = 0, C2 = 0;
    cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2;

    if (A1 > B1) swap(A1, B1);
    if (A1 > C1) swap(A1, C1);
    if (B1 > C1) swap(B1, C1);

    if (A2 > B2) swap(A2, B2);
    if (A2 > C2) swap(A2, C2);
    if (B2 > C2) swap(B2, C2);

    if (A1 == A2 && B1 == B2 && C1 == C2) {
        cout << "Boxes are equal";
    }
    else if (A1 <= A2 && B1 <= B2 && C1 <= C2) {
        cout << "The first box is smaller than the second one";
    }
    else if (A1 >= A2 && B1 >= B2 && C1 >= C2) {
        cout << "The first box is larger than the second one";
    }
    else {
        cout << "Boxes are incomparable";
    }

    return 0;
}