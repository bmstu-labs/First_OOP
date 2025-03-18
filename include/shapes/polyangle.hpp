#pragma once

#include <vector>
#include "shapes/shape.hpp"

namespace Shapes {
    class Polyangle : public Shape {
        std::vector<Vector> points;
    public:
        Polyangle(const std::string&, std::vector<Vector>);
    public:
        double get_perimeter() const override;

        std::vector<Vector> get_points() const override;

        void accept(const IPrinter *) const override;
    };
}