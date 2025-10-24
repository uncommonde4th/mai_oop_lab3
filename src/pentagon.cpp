#include <cmath>
#include "../include/pentagon.h"

Pentagon::Pentagon() {
    numOfPoints = 5;
    points = new Point[numOfPoints]();
}

double Pentagon::getArea() const {
    double area = 0.0;
    for (unsigned int i = 0; i < numOfPoints; i++) {
        unsigned int j = (i + 1) % numOfPoints;
        area += points[i].x * points[j].y - points[j].x * points[i].y;
    }
    return std::abs(area) / 2.0;
}

bool Pentagon::operator==(const Figure& other) const {
    if (other.getNumOfPoints() != numOfPoints) { 
        return false; 
    }

    Point* oPoints = other.getPoints();
    
    double side1 = std::sqrt(std::pow((points[1].x - points[0].x), 2) + std::pow((points[1].y - points[0].y), 2));
    double side2 = std::sqrt(std::pow((points[2].x - points[1].x), 2) + std::pow((points[2].y - points[1].y), 2));
    double side3 = std::sqrt(std::pow((points[3].x - points[2].x), 2) + std::pow((points[3].y - points[2].y), 2));
    double side4 = std::sqrt(std::pow((points[4].x - points[3].x), 2) + std::pow((points[4].y - points[3].y), 2));
    double side5 = std::sqrt(std::pow((points[0].x - points[4].x), 2) + std::pow((points[0].y - points[4].y), 2));
    
    double other_side1 = std::sqrt(std::pow((oPoints[1].x - oPoints[0].x), 2) + std::pow((oPoints[1].y - oPoints[0].y), 2));
    double other_side2 = std::sqrt(std::pow((oPoints[2].x - oPoints[1].x), 2) + std::pow((oPoints[2].y - oPoints[1].y), 2));
    double other_side3 = std::sqrt(std::pow((oPoints[3].x - oPoints[2].x), 2) + std::pow((oPoints[3].y - oPoints[2].y), 2));
    double other_side4 = std::sqrt(std::pow((oPoints[4].x - oPoints[3].x), 2) + std::pow((oPoints[4].y - oPoints[3].y), 2));
    double other_side5 = std::sqrt(std::pow((oPoints[0].x - oPoints[4].x), 2) + std::pow((oPoints[0].y - oPoints[4].y), 2));

    return (side1 == other_side1) && (side2 == other_side2) && (side3 == other_side3) && 
           (side4 == other_side4) && (side5 == other_side5);
}

void Pentagon::print(std::ostream& os) const {
    os << "Пятиугольник: {";
    for (unsigned int i = 0; i < numOfPoints; i++) {
        os << " (" << points[i].x << ", " << points[i].y << ")";
    }
    os << " }";
}

void Pentagon::read(std::istream& is) {
    delete[] points;

    numOfPoints = 5;
    points = new Point[numOfPoints]();

    for (unsigned int i = 0; i < numOfPoints; i++) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Неверный ввод");
        }
        points[i] = Point(x, y);
    }
}
