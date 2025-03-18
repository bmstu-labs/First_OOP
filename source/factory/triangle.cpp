#include "factory/triangle.hpp"
#include "shapes/triangle.hpp"

#include "exceptions.hpp"

Shapes::Shape *TriangleFactory::create_shape() const {
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    Shapes::Vector first_point;
    std::cin >> first_point;

    Shapes::Vector second_point;
    std::cin >> second_point;
    
    Shapes::Vector third_point;
    std::cin >> third_point;

    if (Shapes::Vector::one_point_check(first_point, second_point) || Shapes::Vector::one_point_check(second_point, third_point)  || Shapes::Vector::one_point_check(first_point, third_point)) {
            throw OnePointError("Two or more points cannot have the same coordinates.");
        }

    if (Shapes::Vector::is_line(first_point, second_point, third_point)) {
        throw ShapeIsLineError("The points cannot be on the line");
    }

    return new Shapes::Triangle(name, first_point, second_point, third_point);
}