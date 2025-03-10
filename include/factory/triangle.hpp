#pragma once

#include "factory/shape.hpp"

class TriangleFactory : public ShapeFactory {
public:
    Shapes::Shape *create_shape() const override;
};