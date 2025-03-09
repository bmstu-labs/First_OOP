#pragma once

#include "shape.hpp"

namespace Shape {
    class Rectangle : public Shape {
        Dot left_bottom_corner;
        Dot right_upper_corner;
    public:
        Rectangle(const std::string, Dot, Dot);
        
        double get_perimeter() const override;
        
        void display() const override;
        
        void display_with_perimeter() const override;

        void input() override;
    };
}