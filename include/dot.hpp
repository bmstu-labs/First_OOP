#pragma once

#include <iostream>
#include <cmath>

#include "exceptions/input_error.hpp"

namespace Shape {

    const double EPSILON = .0001;

    class Dot {
        double x;
        double y;
    public:
        Dot();

        double get_x() const;

        double get_y() const;

        double get_length(Dot&) const;

        bool is_line(Dot&, Dot&) const;

        friend std::istream& operator >> (std::istream& stream, Dot& obj);

        friend std::ostream& operator << (std::ostream& stream, Dot& obj);
    };
}