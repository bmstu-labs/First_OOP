#include "factory/rectangle.hpp"
#include "shapes/rectangle.hpp"

Shapes::Shape *RectangleFactory::create_shape() const {
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    Shapes::Dot left_bottom_point;
    std::cin >> left_bottom_point;

    Shapes::Dot right_upper_point;
    std::cin >> right_upper_point;
    
    return new Shapes::Rectangle(name, left_bottom_point, right_upper_point);
}