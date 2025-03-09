#include "shapes/circle.hpp"

Shape::Circle::Circle(const std::string name, Dot center, double radius) : Shape::Shape(name) {
    this->center = center;
    this->radius = radius;
}

double Shape::Circle::get_perimeter() const {
    return 2 * std::numbers::pi * radius;
}
// SOLID
// Replace display and input functions in separated class
// properties pATTERN & fabric
void Shape::Circle::display() const {
    Shape::display();
    std::cout << "Radius: " << radius << std::endl;
}

void Shape::Circle::display_with_perimeter() const {
    Shape::display();
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}

void Shape::Circle::input() {
    Shape::Shape::input();

    Dot center;
    std::cin >> center;
    coordinates.push_back(center);

    std::cout << "Enter radius: ";
    std::cin >> radius;
}
