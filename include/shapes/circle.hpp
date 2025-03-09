#pragma once

#include <numbers>

#include "shape.hpp"

namespace Shape {
    class Circle : public Shape {
        Dot center;
        double radius;
    public:
        Circle(const std::string, Dot, double);

        double get_perimeter() const override;
        
        // std::vector<Dot> get_points(); 

        void display() const override;

        void display_with_perimeter() const override;

        void input() override;
    };
}