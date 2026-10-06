/******************************
* Автор:   Чупин Артем        *
* Задание: Циклы с ветвлением *
* Вариант: 34                 *
******************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const double PI = 3.14159265358979323846;
    double n1 = 1.5; // Показатель преломления 
    double n2 = 1.0; // Показатель преломления с воздухом
    double alpha; // Угол падения
    double beta; // Угол преломления
    double R; // Отраженная
    double T; // Световая мощность
    double psi; // Угол падения в градусах
    double psiC; // Критический угол полного внутреннего отражения
    double rs, rp; // Направления поляризации
    int count; // сколько углов будет введено
    
    cout << "Enter the number of angles: ";
    cin >> count;

    psiC = asin(n2 / n1);

    for (int number = 0; number < count; ++number) {
        cout << endl << "Enter angle " << number+1 << ": ";
        cin >> alpha;

        psi = (PI * alpha) / 180;

        if (psi < psiC) {
            beta = asin((n1 / n2) * sin(psi));
            rs = (n1 * cos(psi) - n2 * cos(beta)) / (n1 * cos(psi) + n2 * cos(beta));
            rp = (n2 * cos(psi) - n1 * cos(beta)) / (n2 * cos(psi) + n1 * cos(beta));
            R = (pow(rs, 2) + pow(rp, 2)) / 2;
            T = 1 - R;
        } else {
            R = 1.0;
            T = 0.0;
        }

        cout << endl << "alpha\tR,%\tT,%" << endl
             << alpha << "\t"
             << R * 100 << "\t"
             << T * 100 << endl;
    }
    return 0;
}