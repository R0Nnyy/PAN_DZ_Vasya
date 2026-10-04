#include <iostream>
using namespace std;

struct Aircraft
{
    int num;
    double m;
    double s;
    double T;
    double C_d;
    double C_l;
    double L;
    double D;
    double a;
};

int main()
{
    double p, v;
    int n;

    cout << "enter air density p: ";
    cin >> p;
    cout << "enter speed v: ";
    cin >> v;
    cout << "enter number of aircraft n: ";
    cin >> n;

    if (p <= 0 || v <= 0 || n <= 0)
    {
        cout << "error: parameters must be positive" << endl;
        return 1;
    }

    Aircraft* planes = new Aircraft[n];

    for (int i = 0; i < n; i++)
    {
        planes[i].num = i + 1;
        cout << "enter mass m for aircraft " << i + 1 << ": ";
        cin >> planes[i].m;
        cout << "enter wing area s for aircraft " << i + 1 << ": ";
        cin >> planes[i].s;
        cout << "enter thrust T for aircraft " << i + 1 << ": ";
        cin >> planes[i].T;
        cout << "enter drag coefficient C_d for aircraft " << i + 1 << ": ";
        cin >> planes[i].C_d;
        cout << "enter lift coefficient C_l for aircraft " << i + 1 << ": ";
        cin >> planes[i].C_l;

        if (planes[i].m <= 0 || planes[i].s <= 0 || planes[i].C_d <= 0 || planes[i].C_l <= 0)
        {
            delete[] planes;
            cout << "error: mass, wing area and coefficients must be positive" << endl;
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        planes[i].L = 0.5 * p * v * v * planes[i].s * planes[i].C_l;
        planes[i].D = 0.5 * p * v * v * planes[i].s * planes[i].C_d;
        planes[i].a = (planes[i].T - planes[i].D) / planes[i].m;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "aircraft " << planes[i].num << ": L = " << planes[i].L << ", D = " << planes[i].D << ", a = " << planes[i].a << endl;
    }

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        if (planes[i].a > planes[best].a)
            best = i;
    }

    cout << "aircraft " << planes[best].num << " has the greatest acceleration" << endl;

    delete[] planes;

    return 0;
}
