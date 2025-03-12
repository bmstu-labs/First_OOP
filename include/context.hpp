#pragma once

#include <vector>
#include "shapes/shape.hpp"

class Context {
public:
    std::vector<Shapes::Shape*> shapes;

    Context();

    Context(std::vector<Shapes::Shape*>&);

    ~Context();
};