#pragma once

#include <vector>
#include "shapes/shape.hpp"

struct Context {
    std::vector<Shape::Shape*>& shapes;

    Context(std::vector<Shape::Shape*>&);

    ~Context();
};