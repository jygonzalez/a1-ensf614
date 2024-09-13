using namespace std;

#ifndef POINT_H
#define POINT_H

// TODO: Add documentation
class Point
{
private:
    double x; // x coordinate of a location on Cartisian Plain
    double y; // y coordinate of a location on Cartisian Plain
public:
    Point(double a = 0, double b = 0) : x(a), y(b) {}
    double get_x() { return x; }
    double get_y() { return y; }
    void set_x(double a) { x = a; };
    void set_y(double a) { y = a; };
};

#endif