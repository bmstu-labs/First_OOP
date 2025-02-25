#include "circle.hpp"

Shape::Circle::Circle() = default;

double Shape::Circle::get_perimeter() const {
    return 2 * std::numbers::pi * radius;
}

void Shape::Circle::display() const {
    Shape::display();
    std::cout << "Radius: " << radius << std::endl;
}

void Shape::Circle::display_with_perimeter() const {
    Shape::display();
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}

std::istream& Shape::operator >> (std::istream& stream, Circle& obj) {
    std::cout << "Enter circle name: ";
    stream >> obj.name;

    std::cout << "Enter radius: ";
    stream >> obj.radius;

    Dot center;
    stream >> center;

    return stream;
}
