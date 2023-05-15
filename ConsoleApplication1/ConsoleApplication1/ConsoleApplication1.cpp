#include <iostream>
#include <cmath>
#include <chrono> 

using namespace std;

double function(double x) {
    return x * x - 4 * x + 3;
}

double bisection(double a, double b, double eps) {
    double c;
    do {
        c = (a + b) / 2;
        if (function(c - eps) < function(c + eps)) {
            b = c;
        }
        else {
            a = c;
        }
    } while (fabs(a - b) >= eps);
    return (a + b) / 2;
}

int main() {
    setlocale(0, "");

    double a, b, eps;
    cout << "Введите левый конец отрезка: ";
    if (!(cin >> a)) {
        cout << "Ошибка: некорректный ввод левого конца отрезка." << endl;
        return 1;
    }

    cout << "Введите правый конец отрезка: ";
    if (!(cin >> b)) {
        cout << "Ошибка: некорректный ввод правого конца отрезка." << endl;
        return 1;
    }

    if (a >= b) {
        cout << "Ошибка: левый конец отрезка должен быть меньше правого." << endl;
        return 1;
    }

    cout << "Введите точность: ";
    if (!(cin >> eps)) {
        cout << "Ошибка: некорректный ввод точности." << endl;
        return 1;
    }

    if (eps <= 0) {
        cout << "Ошибка: точность должна быть положительным числом." << endl;
        return 1;
    }

    double x = bisection(a, b, eps);

    cout << "Минимум функции: " << function(x) << endl;
    cout << "Х функции равен: " << x << endl;

    return 0;
}
