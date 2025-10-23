#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"

class Figure {
    public:
        Figure(unsigned int numOfPoints = 4);
        ~Figure();
        
        Figure& operator=(const Figure& other);
        Figure& operator=(Figure&& other);
        virtual bool operator==(const Figure& other) const =0;
        
        Point getCenter() const;
        unsigned int getNumOfPoints() const;
        Point* getPoints() const;

        virtual double getArea() const = 0;
        explicit operator double() const { return getArea(); }
        virtual void print(std::ostream& os) const = 0;
        virtual void read(std::istream& is) = 0;

        friend std::ostream&operator<<(std::ostream& os, const Figure& other);
        friend std::istream&operator>>(std::istream& is, Figure& other);

    protected:
        unsigned int numOfPoints;
        Point *points;
};

#endif
