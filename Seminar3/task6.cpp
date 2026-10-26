#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    vector<double> heights;

    for (double t = 0.0; t <= 1000.0; t += dt)
    {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0)
            break;

        heights.push_back(h);
    }

    auto new_end = remove_if(heights.begin(), heights.end(), [](double h) {
        return h < 10.0;
    });
    heights.erase(new_end, heights.end());

    if (heights.empty())
    {
        cout << "error: no heights left" << endl;
        return 1;
    }

    cout << fixed << setprecision(2);
    for (size_t i = 0; i < heights.size(); i++)
        cout << heights[i] << endl;

    return 0;
}
