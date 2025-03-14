#include "printer/printer_perim.hpp"

void PrinterPerim::visit_circle(const Shapes::Circle& shape) const {
    std::cout << "Name: " << shape.get_name() << std::endl;
    std::cout << "Perimeter: " << shape.get_perimeter() << std::endl;
}

void PrinterPerim::visit_triangle(const Shapes::Triangle& shape) const {
    std::cout << "Name: " << shape.get_name() << std::endl;
    std::cout << "Perimeter: " << shape.get_perimeter() << std::endl;
}

void PrinterPerim::visit_rectangle(const Shapes::Rectangle& shape) const {
    std::cout << "Name: " << shape.get_name() << std::endl;
    std::cout << "Perimeter: " << shape.get_perimeter() << std::endl;
}

void PrinterPerim::visit_polyangle(const Shapes::Polyangle& shape) const {
    std::cout << "Name: " << shape.get_name() << std::endl;
    std::cout << "Perimeter: " << shape.get_perimeter() << std::endl;
}