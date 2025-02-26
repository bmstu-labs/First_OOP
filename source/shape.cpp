#include "shape.hpp"

Shape::Shape::Shape() = default;

const std::string Shape::Shape::get_name() const {
    return this->name;
}

void Shape::Shape::display() const {
    std::cout << this->name << std::endl;
    std::cout << "Points coordinates: ";
    for (auto it : this->coordinates) {
        std::cout << it << ' ';
    }

    std::cout << std::endl;
}

void Shape::Shape::input() {
    std::cout << "Enter name: ";
    std::cin >> name;
}

bool Shape::Shape::operator < (Shape& other) {
    return get_perimeter() < other.get_perimeter();
}

Shape::Shape::~Shape() = default;