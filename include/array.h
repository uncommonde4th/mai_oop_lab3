#ifndef ARRAY_H
#define ARRAY_H

#include "figure.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"


class Array {
    public:
        Array(unsigned int arraySize = 5);
        ~Array();

        void addFigure(Figure *figure);
        //figuresPrint();
        double areaOfAllFigures() const;
        void deleteFigure(unsigned int index);

        unsigned int getSize() const;
        unsigned int getMaxNum() const;

    private:
        Figure **figures;
        unsigned int numOfFigures;
        unsigned int maxNum;
};

#endif

