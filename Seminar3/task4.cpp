#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;

int main()
{
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    vector<double> velocities;

    for (double t = 0.0; t <= 1000.0; t += dt)
    {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0)
            break;

        velocities.push_back(v0 - g * t);
    }

    if (velocities.empty())
    {
        cout << "error: no velocity data" << endl;
        return 1;
    }

    double sum = accumulate(velocities.begin(), velocities.end(), 0.0);
    double avg = sum / velocities.size();

    cout << fixed << setprecision(2);
    cout << "average speed: " << avg << endl;

    return 0;
}
