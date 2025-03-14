#include "factory/polyangle.hpp"
#include "shapes/polyangle.hpp"

#include "exceptions.hpp"

Shapes::Shape *PolyangleFactory::create_shape() const {
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    std::vector<Shapes::Dot> points;
    std::cout << "Enter coords" << std::endl;
    char choose = 'y';
    while (choose == 'y' || choose == 'Y' || points.size() < 3) {
        Shapes::Dot point; 
        std::cin >> point;

        points.push_back(point);

        if (points.size() > 3) {
            std::cout << "Continue? [N/y]: ";
            std::cin >> choose;
        }
    }

    bool ShapeIsLine = true;
    for (size_t i = 0; i < points.size() - 2; i++) {
        const Shapes::Dot a = points.at(i);
        const Shapes::Dot b = points.at(i + 1);
        const Shapes::Dot c = points.at(i + 2);

        if (a.one_point_check(b) || a.one_point_check(c)) {
            throw OnePointError("Two ore more points cannot have the same coordinates.");
        }

        ShapeIsLine = a.is_line(b, c);
    }

    if (ShapeIsLine) {
        throw ShapeIsLineError("The points cannot be on the line");
    }

    return new Shapes::Polyangle(name, points);
}