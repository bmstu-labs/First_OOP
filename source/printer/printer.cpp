#include "printer/printer.hpp"
#include "shapes/shapes.hpp"

void Printer::visit_default (const Shapes::Shape& shape) const {
    std::cout << "Name: " << shape.get_name() << std::endl;
}

void Printer::visit(const Shapes::Circle& circle) const {
    visit_default(circle);

    std::cout << "Center: " << circle.get_points().at(0) << std::endl;
    std::cout << "Radius: " << circle.get_radius() << std::endl;
}

void Printer::visit(const Shapes::Triangle& triangle) const {
    visit_default(triangle);

    std::cout << "Points: ";
    for (Shapes::Dot point : triangle.get_points()) {
        std::cout << point << std::endl;
    }
}

void Printer::visit(const Shapes::Rectangle& rectangle) const {
    visit_default(rectangle);

    std::cout << "Points: ";
    for (Shapes::Dot point : rectangle.get_points()) {
        std::cout << point << " ";
    }
}