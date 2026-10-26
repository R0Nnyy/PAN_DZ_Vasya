#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    vector<double> y = {0, 10, 25, 20, 45};

    if (y.size() < 2)
    {
        cout << "error: need at least two positions" << endl;
        return 1;
    }

    vector<double> diff(y.size());
    adjacent_difference(y.begin(), y.end(), diff.begin());

    double path = accumulate(diff.begin() + 1, diff.end(), 0.0, [](double sum, double step) {
        return sum + fabs(step);
    });

    cout << fixed << setprecision(2);
    cout << "path: " << path << endl;

    return 0;
}
