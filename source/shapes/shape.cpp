#include "shapes/shape.hpp"
#include "printer/printers.hpp"

Shapes::Shape::Shape(const std::string shape_name) : name(shape_name) {}

std::string Shapes::Shape::get_name() const {
    return name;
}

bool Shapes::Shape::operator < (const Shapes::Shape& other) const {
    return (get_perimeter() < other.get_perimeter());
}