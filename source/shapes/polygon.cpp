#include "shapes/polygon.hpp"
#include "printer/printers.hpp"
#include "exceptions.hpp"
#include <numbers>

Shapes::Polygon::Polygon(const std::string& name, std::vector<Shapes::Vector> vectors) : Shape::Shape(name) {
    const std::size_t length = vectors.size();

    for (std::size_t i = 0; i < length; i++) {
        // Retrieving radius-vectors from set
        Shapes::Vector a = vectors.at(i % length);
        Shapes::Vector b = vectors.at((i + 1) % length);
        Shapes::Vector c = vectors.at((i + 2) % length);

        // Compute vectors (shape's sides) from radius-vectors
        Shapes::Vector ab = b - a;
        Shapes::Vector ac = c - a; 

        // Check angle between vectors (sides)
        double cross_product = ab.get_x() * ac.get_y() - ab.get_y() * ac.get_x();
        std::cout << "Cross product: " << cross_product << std::endl;
        
        if (cross_product - Shapes::EPSILON < 0) {
            throw ConcavePolygon("The polygon cannot be concave");
        }
    }
    points = vectors;
}

double Shapes::Polygon::get_perimeter() const {
    double perimeter = 0;
    for (size_t i = 0; i < points.size() - 1; i++) {
        perimeter += Shapes::Vector::get_length(points.at(0), points.at(i + 1));
    }

    return perimeter;
}

std::vector<Shapes::Vector> Shapes::Polygon::get_points() const {
    return points;
}

void Shapes::Polygon::accept(const IPrinter *printer) const {
    printer->visit_polygon(*this);
}