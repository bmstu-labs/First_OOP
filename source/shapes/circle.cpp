#include "shapes/circle.hpp"
#include "printer/printers.hpp"

Shapes::Circle::Circle(const std::string& name, Dot center, double radius) : Shapes::Shape(name), center(center), radius(radius) {}

double Shapes::Circle::get_perimeter() const {
    return 2 * std::numbers::pi * radius;
}

double Shapes::Circle::get_radius() const {
    return radius;
}

std::vector<Shapes::Dot> Shapes::Circle::get_points() const {
    std::vector<Shapes::Dot> points;
    points.push_back(center);

    return points;
} 

void Shapes::Circle::accept(const IPrinter *printer) const {
    printer->visit_circle(*this);
}