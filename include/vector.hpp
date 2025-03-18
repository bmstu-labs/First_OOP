#pragma once

#include <iostream>
#include <cmath>

namespace Shapes {
    const double EPSILON = .0001; // Accurancy

    class Vector {
        double x;
        double y;
    public:
        Vector();

        Vector(double, double);
    public:
        double get_x() const;

        double get_y() const;

        double get_length() const;
    public:
        static double get_length(const Vector&, const Vector&);

        static double cos(const Vector&, const Vector&);

        static double angle(const Vector&, const Vector&);

        static bool one_point_check(const Vector&, const Vector&);

        static bool is_line(const Vector&, const Vector&, const Vector&);
    public:
        friend std::istream& operator >> (std::istream& stream, Vector& obj);

        friend std::ostream& operator << (std::ostream& stream, Vector& obj);
    public:
        Vector operator - (const Vector&) const;

        // Vector operator + (const Vector&) const;
    };
}