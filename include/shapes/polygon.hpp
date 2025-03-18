#pragma once

#include <vector>
#include "shapes/shape.hpp"

namespace Shapes {
    class Polygon : public Shape {
        std::vector<Vector> points;
    public:
        Polygon(const std::string&, std::vector<Vector>);
    public:
        double get_perimeter() const override;

        std::vector<Vector> get_points() const override;

        void accept(const IPrinter *) const override;
    };
}