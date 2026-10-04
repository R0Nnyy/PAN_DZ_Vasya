#include <iostream>
using namespace std;

const double g = 9.81;

double get_acc_direct(double m, double L, double D, double T)
{
    return (T - D) / m;
}

double get_acc_vertical(double m, double L, double D, double T)
{
    return (L - m * g) / m;
}

int main()
{
    double m, L, D, T;

    cout << "enter mass m: ";
    cin >> m;
    cout << "enter lift force L: ";
    cin >> L;
    cout << "enter drag force D: ";
    cin >> D;
    cout << "enter thrust force T: ";
    cin >> T;

    
    cout << "acceleration along the flight direction a: "
         << get_acc_direct(m, L, D, T) << endl;
    cout << "vertical acceleration a_y: "
         << get_acc_vertical(m, L, D, T) << endl;

    return 0;
}
