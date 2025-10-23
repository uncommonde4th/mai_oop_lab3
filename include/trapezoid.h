#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "point.h"
#include "figure.h"

class Trapezoid: public Figure {
    public:
        Trapezoid();

        double getArea() const override;
        bool operator==(const Figure& other) const override;

        void print(std::ostream& os) const override;
        void read(std::istream& is) override;
};

#endif
