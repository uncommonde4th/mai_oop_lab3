#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "point.h"
#include "figure.h"

class Rhombus : public Figure {
    public:
        Rhombus();

        double getArea() const override;
        bool operator==(const Figure& other) const override;

        void print(std::ostream&) const override;
        void read(std::istream&) override;
};

#endif
