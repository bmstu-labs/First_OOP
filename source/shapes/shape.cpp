#include "shapes/shape.hpp"

Shape::Shape::Shape(const std::string shape_name) : name(shape_name) {}

std::string Shape::Shape::get_name() const {
    return name;
}

void Shape::Shape::display() const {
    std::cout << name << std::endl;
    std::cout << "Points coordinates: ";
    for (auto it : coordinates) {
        std::cout << it << ' ';
    }

    std::cout << std::endl;
}

// void Shape::Shape::input() {
//     std::cout << "Enter name: ";
//     std::cin >> name;
// }

bool Shape::Shape::operator < (Shape& other) {
    return get_perimeter() < other.get_perimeter();
}

Shape::Shape::~Shape() = default;