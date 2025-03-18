#include "shapes/rectangle.hpp"
#include "printer/printers.hpp"

Shapes::Rectangle::Rectangle(const std::string& name, Vector left, Vector right) : Shapes::Shape(name) {
    left_bottom_corner = left;
    right_upper_corner = right;
}

std::vector<Shapes::Vector> Shapes::Rectangle::get_points() const {
    std::vector<Shapes::Vector> points;
    
    points.push_back(left_bottom_corner);
    points.push_back(right_upper_corner);

    return points;
} 

double Shapes::Rectangle::get_perimeter() const {
    Vector a = left_bottom_corner;
    Vector b = right_upper_corner;
    return 2 * (fabs(a.get_x() - b.get_x()) + fabs(a.get_y() - b.get_y()));
}

void Shapes::Rectangle::accept(const IPrinter *printer) const {
    printer->visit_rectangle(*this);
}