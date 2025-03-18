#include "shapes/polyangle.hpp"
#include "printer/printers.hpp"

Shapes::Polyangle::Polyangle(const std::string& name, std::vector<Shapes::Dot> points) : Shape::Shape(name), points(points) {}

double Shapes::Polyangle::get_perimeter() const {
    double perimeter = 0;
    for (size_t i = 0; i < points.size() - 1; i++) {
        perimeter += Shapes::Dot::get_length(points.at(0), points.at(i + 1));
    }

    return perimeter;
}

std::vector<Shapes::Dot> Shapes::Polyangle::get_points() const {
    return points;
}

void Shapes::Polyangle::accept(const IPrinter *printer) const {
    printer->visit_polyangle(*this);
}