#include "triangle.hpp"

Shape::Triangle::Triangle() = default;

double Shape::Triangle::get_perimeter() const {
    double perim = .0;
    try {
        Dot first_point = coordinates.at(0);
        Dot second_point = coordinates.at(1);
        Dot third_point = coordinates.at(2);

        perim = first_point.get_length(second_point) + first_point.get_length(third_point) + second_point.get_length(third_point);
    }

    catch(std::out_of_range) {
        std::cout << "Not enough points to get perimeter of triangle." << std::endl;
    }

    return perim;
}

void Shape::Triangle::display() const {
    Shape::display();
}

void Shape::Triangle::display_with_perimeter() const {
    Shape::display();
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}

std::istream& Shape::operator >> (std::istream& stream, Triangle& obj) {
    std::cout << "Enter triangle name: ";
    stream >> obj.name;

    
    // Should throw an exception and then exit without saving 
    // point in array
    try {
        Dot a, b, c;
        std::cin >> a >> b >> c;
        if (a.is_line(b, c)) {
            std::cout << "It's a line or point. Try again." << std::endl;
            std::cin >> a >> b >> c;
        }
    }
    catch (std::input_exception) {
        
    }

    obj.coordinates.push_back(a);
    obj.coordinates.push_back(b);
    obj.coordinates.push_back(c);

    return stream;
}
