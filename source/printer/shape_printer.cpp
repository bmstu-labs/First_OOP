#include "printer/shape_printer.hpp"

#include <iostream>

void ShapePrinter::print(const Shapes::Shape& shape) const {
    std::cout << "Name: " << shape.get_name() << std::endl;
}

void ShapePrinter::print_with_perimeter(const Shapes::Shape& shape) const {
    std::cout << "Name: " << shape.get_name() << std::endl;
}