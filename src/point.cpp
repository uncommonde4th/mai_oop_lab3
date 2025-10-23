#include "../include/point.h"

Point::Point(double x, double y) : x(x), y(y) {}

std::ostream& operator<<(std::ostream&os, const Point& p) {
    os << "( " << p.x << " , " << p.y << " )" << std::endl;
    return os;
}
