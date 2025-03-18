#include "shapes/triangle.hpp"
#include "printer/printers.hpp"

Shapes::Triangle::Triangle(const std::string& name, Vector point1, Vector point2, Vector point3) : Shapes::Shape(name) {
    first_point = point1;
    second_point = point2;
    third_point = point3;
}

std::vector<Shapes::Vector> Shapes::Triangle::get_points() const {
    std::vector<Shapes::Vector> points;
    
    points.push_back(first_point);
    points.push_back(second_point);
    points.push_back(third_point);

    return points;
} 

double Shapes::Triangle::get_perimeter() const {
    double perim = .0;
    try {
        Vector a = first_point;
        Vector b = second_point;
        Vector c = third_point;

        perim = Shapes::Vector::get_length(a, b) + Shapes::Vector::get_length(b, c) + Shapes::Vector::get_length(a, c);
    }

    catch(std::out_of_range) {
        std::cout << "Not enough points to get perimeter of triangle." << std::endl;
    }

    return perim;
}

void Shapes::Triangle::accept(const IPrinter *printer) const {
    printer->visit_triangle(*this);
}