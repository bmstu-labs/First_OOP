#include "factory/circle.hpp"
#include "shapes/circle.hpp"

Shapes::Shape *CircleFactory::create_shape() const {
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter center coords" << std::endl;
    Shapes::Dot center;
    std::cin >> center;

    std::cout << "Enter radius: ";
    double radius;
    std::cin >> radius;

    return new Shapes::Circle(name, center, radius);
}