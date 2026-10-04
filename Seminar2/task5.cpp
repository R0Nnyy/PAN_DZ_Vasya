#include <iostream>
#include <cmath>
using namespace std;

const int ROWS = 3;
const int COLS = 5;
const double g = 9.81;
int main()
{
    double p, v, h, m, s, C_l, C_d;
    double param[ROWS][COLS];
    double *ptr = &param[0][0];

    cout << "Enter constant parameters (these will be the same for all aircraft):" << endl;
    cout << "air density p: ";
    cin >> p;
    cout << "speed v: ";
    cin >> v;
    cout << "height h: ";
    cin >> h;

    cout << "Now enter the following 5 parameters for each aircraft:" << endl;
    cout << "(mass m, wing area s, thrust T, drag coefficient C_d, lift coefficient C_l)" << endl;
    
    
    for (int i = 0; i < ROWS*COLS; i++)
    {
        cout << "enter " << i + 1 << " of " << ROWS*COLS << " parameters: ";
        cin >> *(ptr + i);
    }

    double L1 = 0.5 * p * v * v * (*(ptr + 1)) * (*(ptr + 4));
    double L2 = 0.5 * p * v * v * (*(ptr + 6)) * (*(ptr + 9));
    double L3 = 0.5 * p * v * v * (*(ptr + 11)) * (*(ptr + 14));

    double D1 = 0.5 * p * v * v * (*(ptr + 1)) * (*(ptr + 3));
    double D2 = 0.5 * p * v * v * (*(ptr + 6)) * (*(ptr + 8));
    double D3 = 0.5 * p * v * v * (*(ptr + 11)) * (*(ptr + 13));

    double a_y1 = (L1 - (*(ptr + 0)) * g) / (*(ptr + 0));
    double a_y2 = (L2 - (*(ptr + 5)) * g) / (*(ptr + 5));
    double a_y3 = (L3 - (*(ptr + 10)) * g) / (*(ptr + 10));

    cout << "L1: " << L1 << ", L2: " << L2 << ", L3: " << L3 << endl;
    cout << "D1: " << D1 << ", D2: " << D2 << ", D3: " << D3 << endl;
    cout << "a_y1: " << a_y1 << ", a_y2: " << a_y2 << ", a_y3: " << a_y3 << endl;

    if (h <= 0 || a_y1 <= 0 || a_y2 <= 0 || a_y3 <= 0)
    {
        cout << "error: height and vertical accelerations must be positive" << endl;
        return 1;
    }

    double t1 = sqrt(2 * h / a_y1);
    double t2 = sqrt(2 * h / a_y2);
    double t3 = sqrt(2 * h / a_y3);

    cout << "t1: " << t1 << ", t2: " << t2 << ", t3: " << t3 << endl;

    if (t1 <= t2 && t1 <= t3)
        cout << "aircraft 1 reaches height h faster" << endl;
    else if (t2 <= t3)
        cout << "aircraft 2 reaches height h faster" << endl;
    else
        cout << "aircraft 3 reaches height h faster" << endl;

    return 0;
}
