#include "../include/array.h"

Array::Array(unsigned int arraySize) : numOfFigures(0), maxNum(arraySize) {
    figures = new Figure*[maxNum];
    for (unsigned int i = 0; i < maxNum; i++) {
        figures[i] = nullptr;
    }
}

Array::~Array() {
    delete[] figures;
}

void Array::addFigure(Figure *figure) {
    if (numOfFigures < maxNum) {
        figures[numOfFigures++] = figure;
    } else {
        throw std::overflow_error("Переполнение массива с фигурами");
    }
}

void Array::printAll() const {
    for (unsigned int i = 0; i < numOfFigures; i++) {
        std::cout << "Фигура " << i << ": ";
        figures[i]->print(std::cout);
        std::cout << std::endl;
        
        Point center = figures[i]->getCenter();
        std::cout << "Центр: (" << center.x << ", " << center.y << ")" << std::endl;
        
        double area = figures[i]->getArea();
        std::cout << "Площадь: " << area << std::endl;
    }
}

double Array::areaOfAllFigures() const {
    double area = 0;
    for (unsigned int i = 0; i < numOfFigures; i++) {
        area += static_cast<double>(*figures[i]);
    }

    return area;
}

void Array::deleteFigure(unsigned int index) {
    if (index < numOfFigures) {
        for (unsigned int i = index; i < numOfFigures - 1; i++) {
            figures[i] = figures[i + 1];
        }

        figures[--numOfFigures] = nullptr;
    }
}

unsigned int Array::getSize() const {
    return numOfFigures;
}

unsigned int Array::getMaxNum() const {
    return maxNum;
}

