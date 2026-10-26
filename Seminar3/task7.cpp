#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;

int main()
{
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    vector<double> times;
    vector<double> heights;

    for (double t = 0.0; t <= 1000.0; t += dt)
    {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);

        if (t > 0.0 && h <= 0.0)
            break;
    }

    auto start = heights.begin();
    if (heights.size() > 1 && heights.front() <= 0.0)
        start = heights.begin() + 1;

    auto it = find_if(start, heights.end(), [](double h) {
        return h <= 0.0;
    });

    cout << fixed << setprecision(2);

    if (it == heights.end())
    {
        cout << "no fall in the time range" << endl;

        return 0;
    }

    size_t idx = distance(heights.begin(), it);
    cout << "fall time: " << times[idx] << endl;
    cout << "height: " << heights[idx] << endl;

    return 0;
}
