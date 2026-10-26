#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    vector<double> measured;

    for (double t = 0.0; t <= 1000.0; t += dt)
    {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0)
            break;

        measured.push_back(h);
    }

    if (measured.size() > 2)
        measured[2] += 5.0;
    if (measured.size() > 5)
        measured[5] -= 4.0;

    vector<double> smoothed(measured.size());

    if (!measured.empty())
    {
        smoothed[0] = measured[0];
        smoothed[measured.size() - 1] = measured[measured.size() - 1];
    }

    for (size_t i = 1; i + 1 < measured.size(); i++)
        smoothed[i] = (measured[i - 1] + measured[i] + measured[i + 1]) / 3.0;

    cout << fixed << setprecision(2);
    cout << setw(12) << "measured" << setw(12) << "smoothed" << endl;

    for (size_t i = 0; i < measured.size(); i++)
        cout << setw(12) << measured[i] << setw(12) << smoothed[i] << endl;

    return 0;
}
