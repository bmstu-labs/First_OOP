#include "shapes/triangle.hpp"
#include "printer/printers.hpp"

Shapes::Triangle::Triangle(const std::string& name, Dot point1, Dot point2, Dot point3) : Shapes::Shape(name) {
    first_point = point1;
    second_point = point2;
    third_point = point3;
}

std::vector<Shapes::Dot> Shapes::Triangle::get_points() const {
    std::vector<Shapes::Dot> points;
    
    points.push_back(first_point);
    points.push_back(second_point);
    points.push_back(third_point);

    return points;
} 

double Shapes::Triangle::get_perimeter() const {
    double perim = .0;
    try {
        Dot a = first_point;
        Dot b = second_point;
        Dot c = third_point;

        perim = Shapes::Dot::get_length(a, b) + Shapes::Dot::get_length(b, c) + Shapes::Dot::get_length(a, c);
    }

    catch(std::out_of_range) {
        std::cout << "Not enough points to get perimeter of triangle." << std::endl;
    }

    return perim;
}

void Shapes::Triangle::accept(const IPrinter *printer) const {
    printer->visit_triangle(*this);
}