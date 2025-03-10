#include "shapes/rectangle.hpp"

Shapes::Rectangle::Rectangle(const std::string name, Dot left, Dot right) : Shapes::Shape(name) {
    left_bottom_corner = left;
    right_upper_corner = right;
}

std::vector<Shapes::Dot> Shapes::Rectangle::get_points() const {
    std::vector<Shapes::Dot> points;
    
    points.push_back(left_bottom_corner);
    points.push_back(right_upper_corner);

    return points;
} 

// Add exceptions handling
double Shapes::Rectangle::get_perimeter() const {
    Dot a = left_bottom_corner;
    Dot b = right_upper_corner;
    return 2 * (fabs(a.get_x() - b.get_x()) + fabs(a.get_y() - b.get_y()));
}

void Shapes::Rectangle::display() const {
    Shapes::Shape::display();
}

void Shapes::Rectangle::display_with_perimeter() const {
    Shape::display();
    std::cout << "Perimeter: " << get_perimeter() << std::endl;
}

// void Shapes::Rectangle::input() {
//     Shapes::Shapes::input();

//     std::cout << "Enter points' coordinates:" << std::endl;
//     Dot a, b;
//     std::cin >> a >> b;
//     coordinates.push_back(a);
//     coordinates.push_back(b);
// }