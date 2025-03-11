#pragma once

#include "shapes/shapes.hpp"

class PrinterPerim {
public:
    void visit(const Shapes::Shape&) const;
};