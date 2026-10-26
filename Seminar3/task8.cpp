#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;

void simulate(double v0, double g, double dt, vector<double>& times, vector<double>& heights)
{
    times.clear();
    heights.clear();

    for (double t = 0.0; t <= 1000.0; t += dt)
    {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);

        if (t > 0.0 && h <= 0.0)
            break;
    }
}

bool fall_time(const vector<double>& times, const vector<double>& heights, double& t_fall)
{
    auto start = heights.begin();
    if (heights.size() > 1 && heights.front() <= 0.0)
        start = heights.begin() + 1;

    auto it = find_if(start, heights.end(), [](double h) {
        return h <= 0.0;
    });

    if (it == heights.end())
        return false;

    size_t idx = distance(heights.begin(), it);
    t_fall = times[idx];
    return true;
}

int main()
{
    const double g = 9.8;
    const double dt = 1.0;
    const double v0_1 = 50.0;
    const double v0_2 = 30.0;

    vector<double> times1;
    vector<double> heights1;
    vector<double> times2;
    vector<double> heights2;

    simulate(v0_1, g, dt, times1, heights1);
    simulate(v0_2, g, dt, times2, heights2);

    if (heights1.empty() || heights2.empty())
    {
        cout << "error: no height data" << endl;
        return 1;
    }

    auto it1 = max_element(heights1.begin(), heights1.end());
    auto it2 = max_element(heights2.begin(), heights2.end());
    size_t idx1 = distance(heights1.begin(), it1);
    size_t idx2 = distance(heights2.begin(), it2);

    double max1 = *it1;
    double max2 = *it2;
    double t_max1 = times1[idx1];
    double t_max2 = times2[idx2];

    double t_fall1 = 0.0;
    double t_fall2 = 0.0;
    bool fell1 = fall_time(times1, heights1, t_fall1);
    bool fell2 = fall_time(times2, heights2, t_fall2);

    cout << fixed << setprecision(2);
    cout << setw(10) << "rocket"
         << setw(14) << "max_height"
         << setw(14) << "time_of_max"
         << setw(14) << "time_of_fall" << endl;

    cout << setw(10) << 1
         << setw(14) << max1
         << setw(14) << t_max1
         << setw(14) << (fell1 ? t_fall1 : -1.0) << endl;

    cout << setw(10) << 2
         << setw(14) << max2
         << setw(14) << t_max2
         << setw(14) << (fell2 ? t_fall2 : -1.0) << endl;

    if (max1 > max2)
        cout << "rocket 1 climbed higher" << endl;
    else if (max2 > max1)
        cout << "rocket 2 climbed higher" << endl;
    else
        cout << "rockets reached the same height" << endl;

    if (!fell1 && !fell2)
        cout << "both rockets are still in the air" << endl;
    else if (!fell1)
        cout << "rocket 1 stayed in the air longer" << endl;
    else if (!fell2)
        cout << "rocket 2 stayed in the air longer" << endl;
    else if (t_fall1 > t_fall2)
        cout << "rocket 1 stayed in the air longer" << endl;
    else if (t_fall2 > t_fall1)
        cout << "rocket 2 stayed in the air longer" << endl;
    else
        cout << "rockets stayed in the air for the same time" << endl;

    return 0;
}
