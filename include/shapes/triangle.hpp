#pragma once

#include "shape.hpp"

namespace Shape {
    class Triangle : public Shape {
        Dot first_point;
        Dot second_point;
        Dot third_point;
    public:
        Triangle(const std::string, Dot, Dot, Dot);
            
        double get_perimeter() const override;
        
        void display() const override;
        
        void display_with_perimeter() const override;

        void input() override;
    };
}