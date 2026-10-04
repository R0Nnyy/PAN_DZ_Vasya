#include <iostream>
#include <cmath>
using namespace std;

const double g = 9.81;

int main()
{
    double m, s, p, v, C_l, h, T_min, T_max, dT;

    cout << "enter mass m: ";
    cin >> m;
    cout << "enter wing area s: ";
    cin >> s;
    cout << "enter air density p: ";
    cin >> p;
    cout << "enter speed v: ";
    cin >> v;
    cout << "enter lift coefficient C_l: ";
    cin >> C_l;
    cout << "enter height h: ";
    cin >> h;
    cout << "enter minimum thrust T_min: ";
    cin >> T_min;
    cout << "enter maximum thrust T_max: ";
    cin >> T_max;
    cout << "enter thrust step dT: ";
    cin >> dT;

    if (m <= 0 || h <= 0 || dT <= 0)
    {
        cout << "error: parameters must be positive" << endl;
        return 1;
    }

    if (T_min > T_max)
    {
        cout << "error: minimum thrust must not exceed maximum thrust" << endl;
        return 1;
    }

    double L = 0.5 * p * v * v * s * C_l;

    double best_T = T_min;
    double best_t = 0;

    for (double T = T_min; T <= T_max; T = T + dT)
    {
        double a_y = (L - m * g) / m;

        if (a_y <= 0)
        {
            cout << "error: vertical acceleration must be positive" << endl;
            return 1;
        }

        double t = sqrt(2 * h / a_y);

        if (T == T_min || t < best_t)
        {
            best_T = T;
            best_t = t;
        }
    }

    cout << "optimal thrust T: " << best_T << endl;
    cout << "time t: " << best_t << endl;

    return 0;
}
