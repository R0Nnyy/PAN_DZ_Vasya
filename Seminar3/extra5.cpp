#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<double> x = {3, 1, 2, 2, 3, 1};

    sort(x.begin(), x.end());
    auto last = unique(x.begin(), x.end());
    x.erase(last, x.end());

    for (size_t i = 0; i < x.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << x[i];
    }
    cout << endl;

    return 0;
}
