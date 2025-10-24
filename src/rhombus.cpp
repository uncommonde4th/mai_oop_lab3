#include <cmath>
#include "../include/rhombus.h"


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
    if (other.getNumOfPoints() != numOfPoints) {
        return false;
    }

    Point *oPoints = other.getPoints();

    double d1 = std::sqrt(std::pow((points[2].x - points[0].x), 2) + std::pow((points[2].y - points[0].y), 2));
    double d2 = std::sqrt(std::pow((points[3].x - points[1].x), 2) + std::pow((points[3].y - points[1].y), 2));

    double other_d1 = std::sqrt(std::pow((oPoints[2].x - oPoints[0].x), 2) + std::pow((oPoints[2].y - oPoints[0].y), 2));
    double other_d2 = std::sqrt(std::pow((oPoints[3].x - oPoints[1].x), 2) + std::pow((oPoints[3].y - oPoints[1].y), 2));
    
    return (d1 == other_d1) && (d2 == other_d2);
}


void Rhombus::print(std::ostream& os) const {
    os << "Ромб: {";
    for (unsigned int i = 0; i < numOfPoints; i++) {
        os << " (" << points[i].x << ", " << points[i].y << ")";
    }
    os << " }";
}

void Rhombus::read(std::istream& is) {
    delete[] points;

    numOfPoints = 4;
    points = new Point[numOfPoints]();

    for (unsigned int i = 0; i < numOfPoints; i++) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Неверный ввод");
        }
        points[i] = Point(x, y);
    }
}


