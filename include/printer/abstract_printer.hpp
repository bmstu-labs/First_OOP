#pragma once

#include "shapes/shapes.hpp"

class BasePrinter {
public:
    virtual void visit_circle(const Shapes::Circle&) const = 0;

    virtual void visit_triangle(const Shapes::Triangle&) const = 0;

    virtual void visit_rectangle(const Shapes::Rectangle&) const = 0;
};