#pragma once

#include "shape.hpp"

namespace Shape {
    class Rectangle : public Shape {
    public:
        Rectangle();
        
        double get_perimeter() const override;
        
        void display() const override;
        
        void display_with_perimeter() const override;
        
        friend std::istream& operator >> (std::istream&, Rectangle&);
    };
}