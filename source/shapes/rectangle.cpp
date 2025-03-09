#include "shapes/rectangle.hpp"

Shape::Rectangle::Rectangle(const std::string name, Dot left, Dot right) : Shape::Shape(name) {
    left_bottom_corner = left;
    right_upper_corner = right;
}

// Add exceptions handling
double Shape::Rectangle::get_perimeter() const {
    Dot a = coordinates.at(0);
    Dot b = coordinates.at(1);
    return 2 * (fabs(a.get_x() - b.get_x()) + fabs(a.get_y() - b.get_y()));
}

void Shape::Rectangle::display() const {
    Shape::Shape::display();
}

void Shape::Rectangle::display_with_perimeter() const {
    Shape::Shape::display();
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}

void Shape::Rectangle::input() {
    Shape::Shape::input();

    std::cout << "Enter points' coordinates:" << std::endl;
    Dot a, b;
    std::cin >> a >> b;
    coordinates.push_back(a);
    coordinates.push_back(b);
}