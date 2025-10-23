#include "../include/figure.h"

Figure::Figure(unsigned int pointsNum) : numOfPoints(pointsNum) {
    numOfPoints = 0;
    points = new Point[numOfPoints];
}

Figure::~Figure() {
    delete[] points;
    numOfPoints = 0;
}

