#include "shapes/circle.hpp"

Shapes::Circle::Circle(const std::string name, Dot center, double radius) : Shapes::Shape(name) {
    this->center = center;
    this->radius = radius;
}

double Shapes::Circle::get_perimeter() const {
    return 2 * std::numbers::pi * radius;
}

std::vector<Shapes::Dot> Shapes::Circle::get_points() const {
    std::vector<Shapes::Dot> points;
    points.push_back(center);

    return points;
} 

// SOLID
// Replace display and input functions in separated class
// properties pATTERN & fabric

void Shapes::Circle::display() const {
    Shape::display();
    std::cout << "Radius: " << radius << std::endl;
}

void Shapes::Circle::display_with_perimeter() const {
    Shape::display();
    std::cout << "Perimeter: " << get_perimeter() << std::endl;
}

// void Shapes::Circle::input() {
//     Shapes::Shapes::input();

//     Dot center;
//     std::cin >> center;
//     coordinates.push_back(center);

//     std::cout << "Enter radius: ";
//     std::cin >> radius;
// }
