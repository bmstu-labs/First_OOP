#include "shapes/circle.hpp"
#include "printer/printers.hpp"

#include <numbers>

Shapes::Circle::Circle(const std::string& name, Vector center, double radius) : Shapes::Shape(name), center(center), radius(radius) {}

double Shapes::Circle::get_perimeter() const {
    return 2 * std::numbers::pi * radius;
}

double Shapes::Circle::get_radius() const {
    return radius;
}

std::vector<Shapes::Vector> Shapes::Circle::get_points() const {
    std::vector<Shapes::Vector> points;
    points.push_back(center);

    return points;
} 

void Shapes::Circle::accept(const IPrinter *printer) const {
    printer->visit_circle(*this);
}