#pragma once

#include <iostream>
#include <cmath>

const double EPSILON = .0001;

namespace Shapes {
    class Dot {
        double x;
        double y;
    public:
        Dot();

        Dot(double, double);

        double get_x() const;

        double get_y() const;

        double get_length(Dot&) const;

        bool is_line(Dot&, Dot&) const;

        friend std::istream& operator >> (std::istream& stream, Dot& obj);

        friend std::ostream& operator << (std::ostream& stream, Dot& obj);
    };
}