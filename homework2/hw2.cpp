#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double get_t(double x0, double x, double vx,int dir)
{
    return (x - x0)/(dir*vx);
}

double get_vy(double vy0, double t)
{
    return vy0 - 9.81*t;
}

double get_height(double h0, double vy, double t)
{
    return h0 + vy*t - 9.81/2 * pow(t, 2);
}
