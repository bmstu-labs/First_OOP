#pragma once

#include "factory/shape.hpp"

class RectangleFactory : public ShapeFactory {
public:
    Shapes::Shape *create_shape() const override;
};