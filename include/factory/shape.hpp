#pragma once

#include "shapes/shape.hpp"

class ShapeFactory {
public:
    virtual Shapes::Shape *create_shape() const = 0;
    
    virtual ~ShapeFactory() = default;
};