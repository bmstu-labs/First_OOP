#include "vector.hpp"
#include "exceptions.hpp"

Shapes::Vector::Vector() : x(), y() {}

Shapes::Vector::Vector(double f, double s) : x(f), y(s) {}


double Shapes::Vector::get_x() const {
    return this->x;
}

double Shapes::Vector::get_y() const {
    return this->y;
}

bool Shapes::Vector::one_point_check(const Vector& obj1, const Vector& obj2) {
    if (fabs(Shapes::Vector::get_length(obj1, obj2)) < Shapes::EPSILON) {
        return true;
    }
    else {
        return false;
    }
}

bool Shapes::Vector::is_line(const Vector& obj1, const Vector& obj2, const Vector& obj3) {

    double alpha = Shapes::Vector::get_length(obj1, obj2);
    double beta  = Shapes::Vector::get_length(obj1, obj3);
    double gamma = Shapes::Vector::get_length(obj2, obj3);

    double max_length = std::max(alpha, beta);
    max_length = std::max(gamma, max_length);
    
    bool result = false;
    
    if (fabs(2 * max_length - alpha - beta - gamma) < Shapes::EPSILON) {
        result = true;
    }

    return result;
}

double Shapes::Vector::get_length(const Vector& obj1, const Vector& obj2) {
    return sqrt(pow((obj1.get_x() - obj2.get_x()), 2) + pow((obj1.get_y() - obj2.get_y()), 2));
}

std::istream& Shapes::operator >> (std::istream& stream, Vector& Vector) {
    std::cout << "Enter point coodinates." << std::endl;
    std::cout << "Enter x: ";
    if (!(stream >> Vector.x)) {
        throw InputError("Incorrect input data format");
    }
    std::cout << "Enter y: ";
    if (!(stream >> Vector.y)) {
        throw InputError("Incorrect input data format");
    }

    return stream;
}

std::ostream& Shapes::operator << (std::ostream& stream, Vector& Vector) {
    stream << '(' << Vector.x << "; " << Vector.y << ')';
    return stream;
}
