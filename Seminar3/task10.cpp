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

class Rocket
{
public:
    Rocket(double mass, double vx, double vy, double vz)
        : mass(mass), vx(vx), vy(vy), vz(vz), x(0.0), y(0.0), z(0.0)
    {
    }

    void changeVelocity(double new_vx, double new_vy, double new_vz)
    {
        vx = new_vx;
        vy = new_vy;
        vz = new_vz;
    }

    void updatePosition(double dt)
    {
        const double g = 9.8;

        vz -= g * dt;
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;

        if (z < 0.0)
        {
            z = 0.0;
            vz = 0.0;
        }
    }

    Point getPosition() const
    {
        Point p;
        p.x = x;
        p.y = y;
        p.z = z;
        return p;
    }

    double getMass() const
    {
        return mass;
    }

private:
    double mass;
    double vx;
    double vy;
    double vz;
    double x;
    double y;
    double z;
};

int main()
{
    const double dt = 1.0;
    const double flight_time = 10.0;

    vector<Rocket> squad;
    squad.reserve(5);
    squad.emplace_back(1000, 10, 0, 50);
    squad.emplace_back(900, 15, -5, 40);
    squad.emplace_back(800, 5, 5, 60);
    squad.emplace_back(1200, 0, 10, 30);
    squad.emplace_back(700, 20, 2, 45);

    vector<vector<Point>> trajectories(squad.size());

    for (double t = 0.0; t < flight_time; t += dt)
    {
        for (size_t i = 0; i < squad.size(); i++)
        {
            trajectories[i].push_back(squad[i].getPosition());
            squad[i].updatePosition(dt);
        }
    }

    cout << fixed << setprecision(2);
    cout << setw(8) << "rocket"
         << setw(10) << "mass"
         << setw(10) << "x"
         << setw(10) << "y"
         << setw(10) << "z" << endl;

    for (size_t i = 0; i < squad.size(); i++)
    {
        Point p = squad[i].getPosition();
        cout << setw(8) << i + 1
             << setw(10) << squad[i].getMass()
             << setw(10) << p.x
             << setw(10) << p.y
             << setw(10) << p.z << endl;
    }

    return 0;
}
