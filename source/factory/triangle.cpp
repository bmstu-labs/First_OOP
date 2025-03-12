#include "factory/triangle.hpp"
#include "shapes/triangle.hpp"

Shapes::Shape *TriangleFactory::create_shape() const {
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    Shapes::Dot first_point;
    std::cin >> first_point;

    Shapes::Dot second_point;
    std::cin >> second_point;
    
    Shapes::Dot third_point;
    std::cin >> third_point;

    return new Shapes::Triangle(name, first_point, second_point, third_point);
}