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
        
        std::vector<Dot> get_points() const override; 

        void display() const override;

        void display_with_perimeter() const override;

        // void input() override;
    };
}