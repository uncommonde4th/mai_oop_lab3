#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
    public:
        double x;
        double y;

        Point() = default;
        Point(double x, double y);

        friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

#endif

