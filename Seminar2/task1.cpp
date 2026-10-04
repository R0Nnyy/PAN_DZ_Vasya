#include <iostream>
using namespace std;

int main()
{
    double s, v, p, C_l, L;

    cout << "enter wing area s: ";
    cin >> s;
    cout << "enter flight speed v: ";
    cin >> v;
    cout << "enter air density p: ";
    cin >> p;
    cout << "enter lift coefficient C_l: ";
    cin >> C_l;

    L = 0.5 * s * v * v * p * C_l;
    cout << L << endl;
    
    return 0;
}
