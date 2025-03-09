#pragma once

#include "printer/shape_printer.hpp"

class CirclePrinter : public ShapePrinter {
public:
    void print(Shape::Shape& shape) const override {
        ShapePrinter::print(shape);
        // Should be input 
    }
};