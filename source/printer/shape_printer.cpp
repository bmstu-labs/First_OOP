#include "printer/shape_printer.hpp"

#include <iostream>

void ShapePrinter::print(Shape::Shape& shape) const {
    std::cout << "Name: " << shape.get_name() << std::endl;
}