#pragma once

#include "shape.hpp"
#include "dot.hpp"

#include <numbers>
#include <vector>

namespace Shapes {
    class Circle : public Shape {
        Dot center;
        double radius;
    public:
        Circle();
        
        Circle(const std::string, Dot, double);
    public:
        double get_perimeter() const override;

        double get_radius() const;
        
        std::vector<Dot> get_points() const override;
        
        void accept(const IPrinter *) const override;
    };
}