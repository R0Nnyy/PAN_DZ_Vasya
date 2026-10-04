#include <iostream>
#include <cmath>
using namespace std;

const double g = 9.81;

struct Aircraft
{
    int num;
    double m;
    double T;
    double C_l;
    double C_d;
    double a_y;
    double t;
};

int main()
{
    double p, v, s, h;
    int n;

    cout << "enter air density p: ";
    cin >> p;
    cout << "enter speed v: ";
    cin >> v;
    cout << "enter wing area s: ";
    cin >> s;
    cout << "enter height h: ";
    cin >> h;
    cout << "enter the number of aircraft n: ";
    cin >> n;

    if (p <= 0 || v <= 0 || s <= 0 || n <= 0 || h <= 0)
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

        if (planes[i].m <= 0)
        {
            delete[] planes;
            cout << "error: mass must be positive" << endl;
            return 1;
        }

        cout << "enter thrust T for aircraft " << i + 1 << ": ";
        cin >> planes[i].T;
        cout << "enter lift coefficient C_l for aircraft " << i + 1 << ": ";
        cin >> planes[i].C_l;
        cout << "enter drag coefficient C_d for aircraft " << i + 1 << ": ";
        cin >> planes[i].C_d;

        if (planes[i].C_l <= 0 || planes[i].C_d <= 0)
        {
            delete[] planes;
            cout << "error: coefficients must be positive" << endl;
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        double L = 0.5 * p * v * v * s * planes[i].C_l;
        planes[i].a_y = (L - planes[i].m * g) / planes[i].m;

        if (planes[i].a_y <= 0)
        {
            delete[] planes;
            cout << "error: vertical acceleration must be positive" << endl;
            return 1;
        }
        
        planes[i].t = sqrt(2 * h / planes[i].a_y);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (planes[j].t > planes[j + 1].t)
            {
                Aircraft temp = planes[j];
                planes[j] = planes[j + 1];
                planes[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "aircraft " << planes[i].num << ": a_y = " << planes[i].a_y << ", t = " << planes[i].t << endl;
    }

    delete[] planes;

    return 0;
}
