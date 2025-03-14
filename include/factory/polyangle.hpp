#pragma once

#include "factory/shape.hpp"

class PolyangleFactory : public ShapeFactory {
public:
    Shapes::Shape *create_shape() const override;
};