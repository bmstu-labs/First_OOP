#include "dot.hpp"

Shape::Dot::Dot() = default;

double Shape::Dot::get_x() const {
    return this->x;
}

double Shape::Dot::get_y() const {
    return this->y;
}

bool Shape::Dot::is_line(Dot& obj1, Dot& obj2) const {

    double alpha = this->get_length(obj1);
    double beta  = this->get_length(obj2);
    double gamma = obj1.get_length(obj2);

    double max_length = std::max(alpha, beta);
    max_length = std::max(gamma, max_length);
    
    bool result = false;

    if (fabs(2 * max_length - alpha - beta - gamma) < EPSILON) {
        result = true;
    }

    return result;
}

double Shape::Dot::get_length(Dot& other) const {
    return sqrt(pow((this->x - other.x), 2) + pow((this->y - other.y), 2));
}

std::istream& Shape::operator >> (std::istream& stream, Dot& dot) {
    std::cout << "Enter point coodinates." << std::endl;
    std::cout << "Enter x: ";
    stream >> dot.x;
    std::cout << "Enter y: ";
    stream >> dot.y;

    return stream;
}

std::ostream& Shape::operator << (std::ostream& stream, Dot& dot) {
    stream << '(' << dot.x << "; " << dot.y << ')';
    return stream;
}
