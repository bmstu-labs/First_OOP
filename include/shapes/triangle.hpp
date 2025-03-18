#pragma once

#include "shape.hpp"

namespace Shapes {
    class Triangle : public Shape {
        Vector first_point;
        Vector second_point;
        Vector third_point;
    public:
        Triangle(const std::string&, Vector, Vector, Vector);
    public:
        double get_perimeter() const override;

        std::vector<Vector> get_points() const override;

        void accept(const IPrinter *) const override;
    };
}