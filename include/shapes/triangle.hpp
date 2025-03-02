#pragma once

#include "shape.hpp"

namespace Shape {
    class Triangle : public Shape {
    public:
        Triangle();
            
        double get_perimeter() const override;
        
        void display() const override;
        
        void display_with_perimeter() const override;

        void input() override;
    };
}