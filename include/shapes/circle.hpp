#pragma once

#include <numbers>

#include "shape.hpp"

namespace Shape {
    class Circle : public Shape {
        double radius;
    public:
        Circle();

        double get_perimeter() const override;

        void display() const override;

        void display_with_perimeter() const override;

        void input() override;
    };
}