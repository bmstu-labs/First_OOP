#pragma once

#include "factory/shape_factory.hpp"
#include "shapes/circle.hpp"

class CircleFactory : public ShapeFactory {
public:
    Shape::Shape *create() override;
};