#include <iostream>
using namespace std;

const double g = 9.81;

double get_acc_vertical(double m, double L)
{
    return (L - m * g) / m;
}

int main()
{
    double m, L, a_y;

    cout << "enter mass m: ";
    cin >> m;
    cout << "enter lift force L: ";
    cin >> L;

    if (m <= 0)
    {
        cout << "error: mass must be positive" << endl;
        return 1;
    }

    a_y = get_acc_vertical(m, L);

    if (a_y > 0.5)
        cout << "climb" << endl;
    else if (a_y >= 0)
        cout << "level flight" << endl;
    else
        cout << "decrease" << endl;

    return 0;
}
