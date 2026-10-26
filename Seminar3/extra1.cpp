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
        if (h < 0)
            break;

        times.push_back(t);
        heights.push_back(h);
    }

    if (heights.empty())
    {
        cout << "error: no height data" << endl;
        return 1;
    }

    auto it = max_element(heights.begin(), heights.end());
    size_t idx = distance(heights.begin(), it);

    cout << fixed << setprecision(2);
    cout << "max height: " << *it << endl;
    cout << "time: " << times[idx] << endl;

    return 0;
}
