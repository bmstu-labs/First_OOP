#pragma once

#include "shapes/shape.hpp"

class ShapePrinter {
public:
    virtual void print(Shape::Shape& shape) const = 0;
};