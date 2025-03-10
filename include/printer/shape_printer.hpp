#pragma once

#include "shapes/shape.hpp"

class ShapePrinter {
public:
    virtual void print(const Shapes::Shape&) const = 0;

    virtual void print_with_perimeter(const Shapes::Shape&) const = 0;
};