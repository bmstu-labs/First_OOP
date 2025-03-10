#pragma once

#include "printer/shape_printer.hpp"

class CirclePrinter : public ShapePrinter {
public:
    void print(const Shapes::Shape&) const override;

    void print_with_perimeter(const Shapes::Shape&) const override;
};