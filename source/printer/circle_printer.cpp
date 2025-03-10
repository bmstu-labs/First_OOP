#include "printer/circle_printer.hpp"

void CirclePrinter::print(const Shapes::Shape& circle) const {
    ShapePrinter::print(circle);
    std::cout << "Center: " << circle.get_points().at(0) << std::endl;
    std::cout << "Radius: " << "NaN" << std::endl;
}

void CirclePrinter::print_with_perimeter(const Shapes::Shape& circle) const {
    ShapePrinter::print(circle);
    std::cout << "Center: " << circle.get_points().at(0) << std::endl;
    std::cout << "Perimeter: " << circle.get_perimeter() << std::endl;
}