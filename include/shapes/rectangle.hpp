#pragma once

#include "shape.hpp"

namespace Shapes {
    class Rectangle : public Shape {
        Vector left_bottom_corner;
        Vector right_upper_corner;
    public:
        Rectangle(const std::string&, Vector, Vector);
    public:
        double get_perimeter() const override;

        std::vector<Vector> get_points() const override;

        void accept(const IPrinter *) const override;
    };
}