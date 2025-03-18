#pragma once

#include <iostream>
#include <cmath>

namespace Shapes {
    const double EPSILON = .0001; // Accurancy

    class Dot {
        double x;
        double y;
    public:
        Dot();

        Dot(double, double);
    public:
        double get_x() const;

        double get_y() const;
    public:
        static double get_length(const Dot&, const Dot&);

        static bool one_point_check(const Dot&, const Dot&);

        static bool is_line(const Dot&, const Dot&, const Dot&);
    public:
        friend std::istream& operator >> (std::istream& stream, Dot& obj);

        friend std::ostream& operator << (std::ostream& stream, Dot& obj);
    };
}