#pragma once

#include "shape.hpp"

namespace Shapes {
    class Circle : public Shape {
        Vector center;
        double radius;
    public:
        Circle();
        
        Circle(const std::string&, Vector, double);
    public:
        double get_perimeter() const override;

        double get_radius() const;
        
        std::vector<Vector> get_points() const override;
        
        void accept(const IPrinter *) const override;
    };
}