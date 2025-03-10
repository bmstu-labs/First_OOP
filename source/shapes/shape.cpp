#include "shapes/shape.hpp"

#include <iostream>

Shapes::Shape::Shape(const std::string shape_name) : name(shape_name) {}

std::string Shapes::Shape::get_name() const {
    return name;
}

void Shapes::Shape::display() const {
    std::cout << "Name: " << name << std::endl;

    std::cout << "Points coordinates: ";
    std::vector<Shapes::Dot> points = get_points();

    for (auto point : points) {
        std::cout << point << ' ';
    }

    std::cout << std::endl;
}

// void Shapes::Shapes::input() {
//     std::cout << "Enter name: ";
//     std::cin >> name;
// }

bool Shapes::Shape::operator < (const Shapes::Shape& other) const {
    return (get_perimeter() < other.get_perimeter());
}