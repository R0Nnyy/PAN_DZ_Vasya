#include <iostream>
using namespace std;

double get_drag_force(double s, double v, double p, double C_d)
{
    return 0.5 * s * v * v * p * C_d;
}

int main()
{
    double s, v, p, C_d, L;

    cout << "enter wing area s: ";
    cin >> s;
    cout << "enter flight speed v: ";
    cin >> v;
    cout << "enter air density p: ";
    cin >> p;
    cout << "enter drag coefficient C_d: ";
    cin >> C_d;

    L = get_drag_force(s, v, p, C_d);
    cout << L << endl;
    
    return 0;
}
