#include "printer/printer.hpp"
#include "shapes/shapes.hpp"

void Printer::visit_circle(const Shapes::Circle& circle) const {
    std::cout << "Name: " << circle.get_name() << std::endl;

    std::cout << "Center: " << circle.get_points().at(0) << std::endl;
    std::cout << "Radius: " << circle.get_radius() << std::endl;
}

void Printer::visit_triangle(const Shapes::Triangle& triangle) const {
    std::cout << "Name: " << triangle.get_name() << std::endl;

    std::cout << "Points: ";
    for (Shapes::Dot point : triangle.get_points()) {
        std::cout << point << std::endl;
    }
}

void Printer::visit_rectangle(const Shapes::Rectangle& rectangle) const {
    std::cout << "Name: " << rectangle.get_name() << std::endl;

    std::cout << "Points: ";
    for (Shapes::Dot point : rectangle.get_points()) {
        std::cout << point << " ";
    }
}