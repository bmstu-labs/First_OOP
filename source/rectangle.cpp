#include "rectangle.hpp"

Shape::Rectangle::Rectangle() = default;

double Shape::Rectangle::get_perimeter() const {
    Dot a = this->coordinates.at(0);
    Dot b = this->coordinates.at(1);
    return 2 * (fabs(a.get_x() - b.get_x()) + fabs(a.get_y() - b.get_y()));
}

void Shape::Rectangle::display() const {
    Shape::display();
}

void Shape::Rectangle::display_with_perimeter() const {
    Shape::display();
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}

std::istream& Shape::operator >> (std::istream& stream, Rectangle& obj) {
    std::cout << "Enter rectangle name: ";
    stream >> obj.name;

    Dot a, b;
    stream >> a;
    stream >> b;

    return stream;
}
