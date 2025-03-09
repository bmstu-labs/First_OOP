#pragma once

#include "shapes/shape.hpp"

class ShapeFactory {
public:
    virtual Shape::Shape *create() = 0;
};