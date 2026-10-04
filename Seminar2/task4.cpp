#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a_y, h;

    cout << "enter vertical acceleration a_y: ";
    cin >> a_y;
    cout << "enter height h: ";
    cin >> h;

    if (a_y <= 0 || h <= 0)
    {
        cout << "error: vertical acceleration and height must be positive" << endl;
        return 1;
    }

    cout << "time t: " << sqrt(2 * h / a_y) << endl;

    return 0;
}
