#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    if (v0 <= 0)
    {
        cout << "error: initial speed must be positive" << endl;
        return 1;
    }

    vector<double> times;
    vector<double> velocities;

    for (double t = 0.0; t <= 1000.0; t += dt)
    {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0)
            break;

        times.push_back(t);
        velocities.push_back(v0 - g * t);
    }

    cout << fixed << setprecision(2);
    cout << setw(8) << "t" << setw(12) << "v" << endl;

    for (size_t i = 0; i < times.size(); i++)
        cout << setw(8) << times[i] << setw(12) << velocities[i] << endl;

    cout << "speed changes sign at t: " << v0 / g << endl;

    return 0;
}
