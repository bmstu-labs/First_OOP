#include "factory/polygon.hpp"
#include "shapes/polygon.hpp"

#include "exceptions.hpp"

Shapes::Shape *PolygonFactory::create_shape() const {
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    std::vector<Shapes::Vector> points;
    std::cout << "Enter coords" << std::endl;
    char choose = 'y';
    while (choose == 'y' || choose == 'Y' || points.size() < 3) {
        Shapes::Vector point; 
        std::cin >> point;

        points.push_back(point);

        if (points.size() > 3) {
            std::cout << "Continue? [N/y]: ";
            std::cin >> choose;
        }
    }

    bool ShapeIsLine = true;
    for (size_t i = 0; i < points.size() - 2; i++) {
        const Shapes::Vector a = points.at(i);
        const Shapes::Vector b = points.at(i + 1);
        const Shapes::Vector c = points.at(i + 2);

        if (Shapes::Vector::one_point_check(a, b) || Shapes::Vector::one_point_check(a, c) || Shapes::Vector::one_point_check(b, c)) {
            throw OnePointError("Two ore more points cannot have the same coordinates.");
        }

        ShapeIsLine = Shapes::Vector::is_line(a, b, c);
    }

    if (ShapeIsLine) {
        throw ShapeIsLineError("The points cannot be on the line");
    }

    return new Shapes::Polygon(name, points);
}