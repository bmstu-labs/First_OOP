#pragma once

#include "shape.hpp"

namespace Shapes {
    class Rectangle : public Shape {
        Dot left_bottom_corner;
        Dot right_upper_corner;
    public:
        Rectangle();
        
        Rectangle(const std::string, Dot, Dot);
    public:
        double get_perimeter() const override;

        std::vector<Dot> get_points() const override;
        
        void display() const override;
        
        void display_with_perimeter() const override;

        // void input() override;
    };
}