#include <cmath>
#include "../include/trapezoid.h"


Trapezoid::Trapezoid() {
    numOfPoints = 4;
    points = new Point[numOfPoints]();
}

double Trapezoid::getArea() const {
    double a = std::sqrt(std::pow((points[1].x - points[0].x), 2) + std::pow((points[1].y - points[0].y), 2));
    double b = std::sqrt(std::pow((points[2].x - points[3].x), 2) + std::pow((points[2].y - points[3].y), 2));
    double h = std::abs(points[0].y - points[2].y);
    double s = ((a + b) * h) / 2;

    return s;
}

bool Trapezoid::operator==(const Figure& other) const {
    if (other.getNumOfPoints() != numOfPoints) { return false; }

    Point* oPoints = other.getPoints();
    double a = std::sqrt(std::pow((points[1].x - points[0].x), 2) + std::pow((points[1].y - points[0].y), 2));
    double b = std::sqrt(std::pow((points[2].x - points[3].x), 2) + std::pow((points[2].y - points[3].y), 2));
    double h = std::abs(points[0].y - points[2].y);

    double othera = std::sqrt(std::pow((oPoints[1].x - oPoints[0].x), 2) + std::pow((oPoints[1].y - oPoints[0].y), 2));
    double otherb = std::sqrt(std::pow((oPoints[2].x - oPoints[3].x), 2) + std::pow((oPoints[2].y - oPoints[3].y), 2));
    double otherh = std::abs(oPoints[0].y - oPoints[2].y);

    return (a == othera) && (b == otherb) && (h == otherh);
}

void Trapezoid::print(std::ostream& os) const {
    os << "Трапеция: {";
    for (unsigned int i = 0; i < numOfPoints; i++) {
        os << " (" << points[i].x << ", " << points[i].y << ")";
    }
    os << " }";
}

void Trapezoid::read(std::istream& is) {
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



