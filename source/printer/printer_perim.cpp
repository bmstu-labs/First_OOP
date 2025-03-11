#include "printer/printer_perim.hpp"

void PrinterPerim::visit(const Shapes::Shape& shape) const {
    std::cout << "Name: " << shape.get_name() << std::endl;
    std::cout << "Perimeter: " << shape.get_perimeter() << std::endl;
}