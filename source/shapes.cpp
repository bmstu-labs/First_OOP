#include "shapes.hpp"

/* Dot implementation */

Dot::Dot() = default;

std::istream& operator >> (std::istream& stream, Dot& dot) {
    std::cout << "Enter point coodinates." << std::endl;
    std::cout << "Enter x: ";
    stream >> dot.x;
    std::cout << "Enter y: ";
    stream >> dot.y;

    return stream;
}

std::ostream& operator << (std::ostream& stream, Dot& dot) {
    stream << '(' << dot.x << "; " << dot.y << ')';
    return stream;
}


/* Shape implementation */

Shape::Shape() = default;

const std::string Shape::get_name() const {
    return this->name;
}

void Shape::display() const {
    std::cout << "Name: " << this->name << std::endl;
}

Shape::~Shape() = default;


/* Circle implementation */

Circle::Circle() = default;

double Circle::get_perimeter() const {
    return 2 * std::numbers::pi * radius;
}

void Circle::display() const {
    Shape::display();
    std::cout << "Radius: " << radius << std::endl;
    // std::cout << "Center coordinates: " << this->coordinates.cbegin();
}

void Circle::display_with_perimeter() const {
    Shape::display();
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}

std::istream& operator >> (std::istream& stream, Circle& obj) {
    std::cout << "Enter circle name: ";
    stream >> obj.name;

    std::cout << "Enter radius: ";
    stream >> obj.radius;

    Dot center;
    stream >> center;

    return stream;
}

/* Triangle implementation */

Triangle::Triangle() = default;

double Triangle::get_perimeter() const {
    Dot first_point = coordinates.at(0);
    Dot second_point = coordinates.at(1);
    Dot third_point = coordinates.at(2);

    double perimeter = sqrt((pow(first_point.x - second_point.x, 2) + pow(first_point.y - second_point.y, 2)));
    perimeter += sqrt((pow(first_point.x - third_point.x, 2) + pow(first_point.y - third_point.y, 2)));
    perimeter += sqrt((pow(second_point.x - third_point.x, 2) + pow(second_point.y - third_point.y, 2)));

    return perimeter;
}

void Triangle::display() const {
    Shape::display();
    std::cout << "Points coordinates: ";
    for (auto it : this->coordinates) {
        std::cout << it << ' ';
    }

    std::cout << std::endl;
}

void Triangle::display_with_perimeter() const {
    Shape::display();
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}

std::istream& operator >> (std::istream& stream, Triangle& obj) {
    std::cout << "Enter triangle name: ";
    stream >> obj.name;

    // for (int i = 0; i < 3; i++) {
    //     Dot a;
    //     std::cin >> a;
    //     obj.coordinates.push_back(a);
    // }

    Dot a, b, c;
    std::cin >> a >> b >> c;
    obj.coordinates.push_back(a);
    obj.coordinates.push_back(b);
    obj.coordinates.push_back(c);

    return stream;
}



/* Rectangle implementation */

Rectangle::Rectangle() = default;

double Rectangle::get_perimeter() const {
    Dot a = this->coordinates.at(0);
    Dot b = this->coordinates.at(1);
    return 2 * (fabs(a.x - b.x) + fabs(a.y - b.y));
}

void Rectangle::display() const {
    Shape::display();
    std::cout << "Points coordinates: ";
    for (auto it : this->coordinates) {
        std::cout << it << ' ';
    }
}

void Rectangle::display_with_perimeter() const {
    Shape::display();
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}

std::istream& operator >> (std::istream& stream, Rectangle& obj) {
    std::cout << "Enter rectangle name: ";
    stream >> obj.name;

    Dot a, b;
    stream >> a;
    stream >> b;

    return stream;
}

