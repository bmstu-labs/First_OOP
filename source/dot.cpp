#include "dot.hpp"
#include "exceptions.hpp"

Shapes::Dot::Dot() : x(), y() {}

Shapes::Dot::Dot(double f, double s) : x(f), y(s) {}


double Shapes::Dot::get_x() const {
    return this->x;
}

double Shapes::Dot::get_y() const {
    return this->y;
}

bool Shapes::Dot::is_line(Dot& obj1, Dot& obj2) const {

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

double Shapes::Dot::get_length(Dot& other) const {
    return sqrt(pow((this->x - other.x), 2) + pow((this->y - other.y), 2));
}

std::istream& Shapes::operator >> (std::istream& stream, Dot& dot) {
    std::cout << "Enter point coodinates." << std::endl;
    std::cout << "Enter x: ";
    if (!(stream >> dot.x)) {
        throw InputError("Incorrect input data format");
    }
    std::cout << "Enter y: ";
    if (!(stream >> dot.y)) {
        throw InputError("Incorrect input data format");
    }

    return stream;
}

std::ostream& Shapes::operator << (std::ostream& stream, Dot& dot) {
    stream << '(' << dot.x << "; " << dot.y << ')';
    return stream;
}
