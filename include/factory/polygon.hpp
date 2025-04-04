#pragma once

#include "factory/shape.hpp"

class PolygonFactory : public ShapeFactory {
public:
    Shapes::Shape *create_shape() const override;
};