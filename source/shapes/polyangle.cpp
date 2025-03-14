#include "shapes/polyangle.hpp"
#include "printer/printers.hpp"

Shapes::Polyangle::Polyangle(std::string name, std::vector<Shapes::Dot> points) : Shape::Shape(name), points(points) {}

double Shapes::Polyangle::get_perimeter() const {
    double perimeter = 0;
    for (size_t i = 0; i < points.size() - 1; i++) {
        perimeter += points.at(0).get_length(points.at(i + 1));
    }

    return perimeter;
}

std::vector<Shapes::Dot> Shapes::Polyangle::get_points() const {
    return points;
}

void Shapes::Polyangle::accept(const Printer& printer) const {
    printer.visit_polyangle(*this);
}

void Shapes::Polyangle::accept(const PrinterPerim& printer) const {
    printer.visit_polyangle(*this);
}