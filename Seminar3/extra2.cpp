#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<double> sensor = {1.2, 0.0, 0.5, 0.0, 0.0, 3.0};

    if (sensor.empty())
    {
        cout << "error: no sensor data" << endl;
        return 1;
    }

    int zeros = count(sensor.begin(), sensor.end(), 0.0);
    cout << "zero readings: " << zeros << endl;

    return 0;
}
