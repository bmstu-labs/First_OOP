#include "shapes/polygon.hpp"
#include "printer/printers.hpp"
#include "exceptions.hpp"
#include <numbers>

Shapes::Polygon::Polygon(const std::string &name, std::vector<Shapes::Vector> vectors) : Shape::Shape(name) {
    const std::size_t length = vectors.size();
    
    std::vector<double> cross_products;
    for (std::size_t i = 0; i < length; i++) {
        // Retrieving radius-vectors from set
        Shapes::Vector a = vectors.at(i % length);
        Shapes::Vector b = vectors.at((i + 1) % length);
        Shapes::Vector c = vectors.at((i + 2) % length);

        // Compute vectors (shape's sides) from radius-vectors
        Shapes::Vector ba = a - b;
        Shapes::Vector cb = c - b; 

        std::cout << "a: " << a << std::endl << "b: " << b << std::endl << "c: " << c << std::endl;

        std::cout << "ba: " << ba << std::endl;
        std::cout << "cb: " << cb << std::endl;

        // Check angle between vectors (sides)
        double cross_product = ba.get_x() * cb.get_y() - ba.get_y() * cb.get_x();

        if (fabs(cross_product) < Shapes::EPSILON) {
            cross_product = 0;
        }

        cross_products.push_back(cross_product);
    }
    const std::size_t length_products = cross_products.size();
    for (std::size_t i = 0; i < length_products; i++) {
        double cross_product_a = cross_products.at(i);
        double cross_product_b = cross_products.at((i + 1) % length_products);

        if ((cross_product_a <= 0 && cross_product_b > 0) || (cross_product_a > 0 && cross_product_b <= 0)) {
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