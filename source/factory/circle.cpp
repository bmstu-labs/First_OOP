#include "factory/circle.hpp"

Shape::Shape *CircleFactory::create() {
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter center coords" << std::endl;
    Shape::Dot center;
    std::cin >> center;

    std::cout << "Enter radius: ";
    double radius;
    std::cin >> radius;

    return new Shape::Circle(name, center, radius);
}