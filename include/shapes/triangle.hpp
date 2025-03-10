#pragma once

#include "shape.hpp"

namespace Shapes {
    class Triangle : public Shape {
        Dot first_point;
        Dot second_point;
        Dot third_point;
    public:
        Triangle();

        Triangle(const std::string, Dot, Dot, Dot);
    public:
        double get_perimeter() const override;

        std::vector<Dot> get_points() const override;
        
        void display() const override;
        
        void display_with_perimeter() const override;

        // void input() override;
    };
}