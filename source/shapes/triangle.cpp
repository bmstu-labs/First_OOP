#include "shapes/triangle.hpp"
#include "printer/printers.hpp"

Shapes::Triangle::Triangle(const std::string name, Dot point1, Dot point2, Dot point3) : Shapes::Shape(name) {
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

        perim = first_point.get_length(a) + first_point.get_length(b) + second_point.get_length(c);
    }

    catch(std::out_of_range) {
        std::cout << "Not enough points to get perimeter of triangle." << std::endl;
    }

    return perim;
}

void Shapes::Triangle::accept(Printer& printer) const {
    printer.visit_triangle(*this);
}

void Shapes::Triangle::accept(PrinterPerim& printer) const {
    printer.visit_triangle(*this);
}

// void Shapes::Triangle::display() const {
//     Shape::display();
// }

// void Shapes::Triangle::display_with_perimeter() const {
//     Shape::display();
//     std::cout << "Perimeter: " << get_perimeter() << std::endl;
// }

// void Shapes::Triangle::input() {
//     Shapes::Shapes::input();

//     Dot a, b, c;
//     std::cin >> a >> b >> c;

//     if (a.is_line(b, c)) {
//         std::cout << "The points are line or the same. Try again." << std::endl;
//     }
//     else {
//         coordinates.push_back(a);
//         coordinates.push_back(b);
//         coordinates.push_back(c);
//     }    
// }
