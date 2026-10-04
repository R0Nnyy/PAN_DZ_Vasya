#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double s, C_l;
    int n;

    cout << "enter wing area s: ";
    cin >> s;
    cout << "enter lift coefficient C_l: ";
    cin >> C_l;
    cout << "enter number of steps: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "error: number of steps must be positive" << endl;
        return 1;
    }

    double* v = new double[n];
    double* p = new double[n];

    for (int i = 0; i < n; i++)
    {
        cout << "enter speed V[" << i << "]: ";
        cin >> v[i];
        cout << "enter air density rho[" << i << "]: ";
        cin >> p[i];
    }

    cout << left;
    cout << "| " << setw(4) << "Step"
         << " | " << setw(5) << "Speed"
         << " | " << setw(7) << "Density"
         << " | " << setw(10) << "Lift force"
         << " |" << endl;

    for (int i = 0; i < n; i++)
    {
        double L = 0.5 * p[i] * v[i] * v[i] * s * C_l;
        cout << "| " << setw(4) << i + 1
             << " | " << setw(5) << v[i]
             << " | " << setw(7) << p[i]
             << " | " << setw(10) << L
             << " |" << endl;
    }

    delete[] v;
    delete[] p;
    
    return 0;
}
