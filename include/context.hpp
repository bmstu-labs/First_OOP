#pragma once

#include <vector>
#include "shapes/shape.hpp"

struct Context {
    std::vector<Shapes::Shape*> shapes;

    Context();

    Context(std::vector<Shapes::Shape*>&);

    ~Context();
};