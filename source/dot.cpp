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

bool Shapes::Dot::one_point_check(const Dot& obj1, const Dot& obj2) {
    if (fabs(Shapes::Dot::get_length(obj1, obj2)) < Shapes::EPSILON) {
        return true;
    }
    else {
        return false;
    }
}

bool Shapes::Dot::is_line(const Dot& obj1, const Dot& obj2, const Dot& obj3) {

    double alpha = Shapes::Dot::get_length(obj1, obj2);
    double beta  = Shapes::Dot::get_length(obj1, obj3);
    double gamma = Shapes::Dot::get_length(obj2, obj3);

    double max_length = std::max(alpha, beta);
    max_length = std::max(gamma, max_length);
    
    bool result = false;
    
    if (fabs(2 * max_length - alpha - beta - gamma) < Shapes::EPSILON) {
        result = true;
    }

    return result;
}

double Shapes::Dot::get_length(const Dot& obj1, const Dot& obj2) {
    return sqrt(pow((obj1.get_x() - obj2.get_x()), 2) + pow((obj1.get_y() - obj2.get_y()), 2));
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
