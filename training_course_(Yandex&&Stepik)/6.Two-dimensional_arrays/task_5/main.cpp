/*   Дано число n, не превосходящее 10, и массив размером n × n. Проверьте, является ли этот массив симметричным относительно главной диагонали. Выведите слово “YES”, если массив симметричный, и слово “NO” в противном случае.

Тестовые данные
№ Теста                1
Входные данные         3
                     0 1 2
                     1 2 3
                     2 3 4
Выходные данные       YES
*/



#include <iostream>
#include <vector>
int main() {
    int n = 0, Not = 0;
    std::cin >> n;
    std::vector <std::vector <int>> Matrix(n, std::vector <int>(n));
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n; l++) {
            std::cin >> Matrix[i][l];
        }
    }

    /*for ( int i = 0 ; i < n ; i++){
        int r = 0;
        r = n - i;
        for( int l = 0 ; l < n ; l++){
            if( i == l ){
                for ( int j = i ; j < r ; j++){
                    if( Matrix[i + 1][l] != Matrix[i][l + 1] ){
                        Not++;
                    }
                }
            }
        }
    } */ //тут я пытался придумать алгоритм , но потом додумался до решения проще , а это забыл удалить
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n; l++) {
            if (Matrix[i][l] != Matrix[l][i]) {
                Not++;
            }
        }
    }
    if (Not == 0) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    return 0;
}