#include "../include/figure.h"

Figure::Figure(unsigned int pointsNum) : numOfPoints(pointsNum) {
    numOfPoints = 0;
    points = new Point[numOfPoints];
}

Figure::~Figure() {
    delete[] points;
    numOfPoints = 0;
}

Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        delete[] points;
        numOfPoints = other.numOfPoints;
        if (other.numOfPoints > 0) {
            points = new Point[numOfPoints];
            for (unsigned int i = 0; i < numOfPoints; i++) {
                points[i] = other.points[i];
            }
        }
    }

    return *this;
}

Figure& Figure::operator=(Figure&& other) {
    if (this != &other) {
        delete[] points;
        numOfPoints = other.numOfPoints;
        points = other.points;

        other.numOfPoints = 0;
        other.points = nullptr;
    }

    return *this;
}

Point Figure::getCenter() const {
    double xc = 0, yc = 0;
    for (unsigned int i = 0; i < numOfPoints; i++) {
        xc += points[i].x;
        yc += points[i].y;
    }
    xc /= numOfPoints;
    yc /= numOfPoints;

    return Point(xc, yc);
}

unsigned int Figure::getNumOfPoints() const {
    return numOfPoints;
}

Point* Figure::getPoints() const {
    return points;
}

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    figure.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.read(is);
    return is;
}
