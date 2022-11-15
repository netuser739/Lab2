#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>

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
    cout << "Введите количество разбиений: ";
    cin >> n;
    
    cout << "┌" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "┬" "─" << "─" <<
        "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "┬" << "─" << "─" << "─" << "─" << "─" << "─" << "─" <<
        "─" << "─" << "─" << "─" << "┐" << endl;
    cout << "│" << setw(6) << 'x' << "     " << "│" << setw(8) << "F(x)" << "   " << "│" << setw(8) << "G(x)" << "   " << "│" << endl;

    if (n != 0) {
        if (a > b) {
                a = a + b;
                b = a - b;
                a = a - b;
        }
        if (a == b) {
            cout << "├" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "┼" "─" << "─" <<
                "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "┼" << "─" << "─" << "─" << "─" << "─" << "─" << "─" <<
                "─" << "─" << "─" << "─" << "┤" << endl;

            cout << "│" << setw(4) << a << "   " << "│" << setprecision(4) << F(a) << " " << "│" <<
                setprecision(4) << G(a) << " " << "│" << endl;
        }
        else {
            h = round((b - a) / n * 10000) / 10000;

            for (int i = 0; i <= n; i++) {

                xi = round((a + i * h) * 10000) / 10000;
                xl = (11 - LenOfInt(xi)) / 2 + LenOfInt(xi);
                fl = (11 - LenOfInt(F(xi))) / 2 + LenOfInt(F(xi));
                gl = (11 - LenOfInt(G(xi))) / 2 + LenOfInt(G(xi));

                cout << "├" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "┼" << "─" << "─" <<
                    "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "┼" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" <<
                    "─" << "─" << "─" << "┤" << endl;

                cout << "│" << setw(xl) << setprecision(4) << xi << setw(14-xl) << "│" << setw(fl) << setprecision(4) <<
                    F(xi) << setw(14 - fl) << "│" << setw(gl) << setprecision(4) << G(xi) << setw(14 - gl) << "│" << endl;
            }
        }

        cout << "└" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "┴" "─" << "─" <<
            "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "─" << "┴" << "─" << "─" << "─" << "─" << "─" << "─" << "─" <<
            "─" << "─" << "─" << "─" << "┘" << endl;
    }
    else {
        cout << "Ошибка";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu