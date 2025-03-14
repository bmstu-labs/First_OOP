#pragma once

#include <vector>
#include "shapes/shape.hpp"

namespace Shapes {
    class Polyangle : public Shape {
        std::vector<Dot> points;
    public:
        Polyangle(const std::string, std::vector<Dot>);
    public:
        double get_perimeter() const override;

        std::vector<Dot> get_points() const override;

        void accept(const Printer&) const override;

        void accept(const PrinterPerim&) const override;
    };
}