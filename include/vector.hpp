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
        double get_x() const noexcept;

        double get_y() const noexcept;

        double get_length() const noexcept;
    public:
        static double get_length(const Vector&, const Vector&) noexcept;

        static bool one_point_check(const Vector&, const Vector&) noexcept;

        static bool is_line(const Vector&, const Vector&, const Vector&) noexcept;
    public:
        friend std::istream& operator >> (std::istream& stream, Vector& obj);

        friend std::ostream& operator << (std::ostream& stream, Vector& obj) noexcept;
    public:
        Vector operator - (const Vector&) const noexcept;

        // Vector operator + (const Vector&) const;
    };
}