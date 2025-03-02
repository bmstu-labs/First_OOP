#include "shapes/triangle.hpp"

Shape::Triangle::Triangle() = default;

double Shape::Triangle::get_perimeter() const {
    double perim = .0;
    try {
        Dot first_point = coordinates.at(0);
        Dot second_point = coordinates.at(1);
        Dot third_point = coordinates.at(2);

        perim = first_point.get_length(second_point) + first_point.get_length(third_point) + second_point.get_length(third_point);
    }

    catch(std::out_of_range) {
        std::cout << "Not enough points to get perimeter of triangle." << std::endl;
    }

    return perim;
}

void Shape::Triangle::display() const {
    Shape::display();
}

void Shape::Triangle::display_with_perimeter() const {
    Shape::display();
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}

void Shape::Triangle::input() {
    Shape::Shape::input();

    Dot a, b, c;
    std::cin >> a >> b >> c;

    if (a.is_line(b, c)) {
        std::cout << "The points are line or the same. Try again." << std::endl;
    }
    else {
        coordinates.push_back(a);
        coordinates.push_back(b);
        coordinates.push_back(c);
    }    
}
