#ifndef PENTAGON_H
#define PENTAGON_H

#include "point.h"
#include "figure.h"

class Pentagon : public Figure {
    public:
        Pentagon();

        double getArea() const override;
        bool operator==(const Figure& other) const override;

        void print(std::ostream& os) const override;
        void read(std::istream& is) override;
};

#endif
