#include <cmath>
#include "rhombus.h"


Rhombus::Rhombus() {
    numOfPoints = 4;
    points = new Point[numOfPoints]();
}

double Rhombus::getArea() const {
    double d1 = std::sqrt(std::pow((points[2].x - points[0].x), 2) + std::pow((points[2].y - points[0].y), 2));
    double d2 = std::sqrt(std::pow((points[3].x - points[1].x), 2) + std::pow((points[3].y - points[1].y), 2));
    double s = d1 * d2 / 2;

    return s;
}

bool Rhombus::operator==(const Figure& other) const {

