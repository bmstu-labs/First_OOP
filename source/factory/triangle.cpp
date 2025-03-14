#include "factory/triangle.hpp"
#include "shapes/triangle.hpp"

#include "exceptions.hpp"

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

    if (first_point.one_point_check(second_point) || 
        first_point.one_point_check(third_point)  ||
        second_point.one_point_check(third_point)) {
            throw OnePointError("Two or more points cannot have the same coordinates.");
        }

    if (first_point.is_line(second_point, third_point)) {
        throw ShapeIsLineError("The points cannot be on the line");
    }

    return new Shapes::Triangle(name, first_point, second_point, third_point);
}