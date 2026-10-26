#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Point
{
    double x;
    double y;
    double z;
};

int main()
{
    const double vx = 30.0;
    const double vy = 20.0;
    const double vz = 40.0;
    const double dt = 1.0;
    const double t_max = 5.0;

    vector<double> times;
    vector<Point> traj;
    traj.reserve((int)(t_max / dt) + 1);

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    for (double t = 0.0; t <= t_max; t += dt)
    {
        times.push_back(t);
        traj.push_back({x, y, z});

        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
    }

    cout << fixed << setprecision(2);
    cout << setw(8) << "t"
         << setw(10) << "x"
         << setw(10) << "y"
         << setw(10) << "z" << endl;

    for (size_t i = 0; i < traj.size(); i++)
    {
        cout << setw(8) << times[i]
             << setw(10) << traj[i].x
             << setw(10) << traj[i].y
             << setw(10) << traj[i].z << endl;
    }

    return 0;
}
