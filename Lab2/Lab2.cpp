#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

float G(float x) {
    return round((x - 1) * (x - 1) * (x - 1) * 10000) / 10000;
}

float F(float x) {
    return round(sin(x) * cos(x) * 10000) / 10000;
}

int LenOfInt(float x) {
    ostringstream ost;
    ost << x;

    return ost.str().size();
}

int main()
{
    float a, b, xi, h;
    int n, fl, gl, xl;

    system("color 02");

    cout << "Введите начало интервала: ";
    cin >> a;
    cout << "Введите конец интервала: ";
    cin >> b;

    if (a > b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    if (a == b) {
        n = 0;
        h = 0;
    }
    else {
        cout << "Введите количество разбиений: ";
        cin >> n;

        if (n <= 0) {
            cout << "N должна быть больше 0; ошибка...";
            return 0;
        }

        h = round((b - a) / n * 10000) / 10000;
    }

    cout << "┌───────────┬───────────┬───────────┐" << endl;
    cout << "│" << setw(6) << 'x' << "     " << "│" << setw(8) << "F(x)" << "   " << "│" << setw(8) << "G(x)" << "   " << "│" << endl;

    for (int i = 0; i <= n; i++) {

        xi = round((a + i * h) * 10000) / 10000;
        xl = (11 - LenOfInt(xi)) / 2 + LenOfInt(xi);
        fl = (11 - LenOfInt(F(xi))) / 2 + LenOfInt(F(xi));
        gl = (11 - LenOfInt(G(xi))) / 2 + LenOfInt(G(xi));

        cout << "├───────────┼───────────┼───────────┤" << endl;

        cout << "│" << setw(xl) << setprecision(4) << xi << setw(14 - xl) << "│" << setw(fl) << setprecision(4) <<
            F(xi) << setw(14 - fl) << "│" << setw(gl) << setprecision(4) << G(xi) << setw(14 - gl) << "│" << endl;

    }
    cout << "└───────────┴───────────┴───────────┘" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu