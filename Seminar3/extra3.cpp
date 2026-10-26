#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    vector<double> temperature = {20, -150, 80, 250, 100, -101, 190};

    auto new_end = remove_if(temperature.begin(), temperature.end(), [](double t) {
        return t < -100.0 || t > 200.0;
    });
    temperature.erase(new_end, temperature.end());

    if (temperature.empty())
    {
        cout << "error: no temperature data left" << endl;
        return 1;
    }

    cout << fixed << setprecision(2);
    for (size_t i = 0; i < temperature.size(); i++)
        cout << temperature[i] << endl;

    return 0;
}
