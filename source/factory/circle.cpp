#include "factory/circle.hpp"
#include "shapes/circle.hpp"

#include "exceptions.hpp"

Shapes::Shape *CircleFactory::create_shape() const {
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter center coords" << std::endl;
    Shapes::Vector center;
    std::cin >> center;

    std::cout << "Enter radius: ";
    double radius;
    std::cin >> radius;

    if (radius < 0) {
        throw NegativeRadiusError("Radius cannot be negative value.");
    }

    return new Shapes::Circle(name, center, radius);
}