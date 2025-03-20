#include "vector.hpp"
#include "exceptions.hpp"

Shapes::Vector::Vector() : x(), y() {}

Shapes::Vector::Vector(double f, double s) : x(f), y(s) {}

// Getters
double Shapes::Vector::get_x() const noexcept {
    return this->x;
}

double Shapes::Vector::get_y() const noexcept {
    return this->y;
}

// Checking function
bool Shapes::Vector::one_point_check(const Vector& obj1, const Vector& obj2) noexcept {
    // If the length between points is less than the accurancy, it is a point
    if (fabs(Shapes::Vector::get_length(obj1, obj2)) < Shapes::EPSILON) {
        return true;
    }
    else {
        return false;
    }
}

bool Shapes::Vector::is_line(const Vector& obj1, const Vector& obj2, const Vector& obj3) noexcept {
    // Getting sides length
    double alpha = Shapes::Vector::get_length(obj1, obj2);
    double beta  = Shapes::Vector::get_length(obj1, obj3);
    double gamma = Shapes::Vector::get_length(obj2, obj3);

    // Detecting max length of all three sides
    double max_length = std::max(alpha, beta);
    max_length = std::max(gamma, max_length);
    
    bool result = false;
    
    // If the max side (length) is less than the accurancy, it is a line
    if (fabs(2 * max_length - alpha - beta - gamma) < Shapes::EPSILON) {
        result = true;
    }

    return result;
}

// Linear functions
double Shapes::Vector::get_length() const noexcept {
    return sqrt(pow(get_x(), 2) + pow(get_y(), 2));
}

double Shapes::Vector::get_length(const Vector& obj1, const Vector& obj2) noexcept {
    return sqrt(pow((obj1.get_x() - obj2.get_x()), 2) + pow((obj1.get_y() - obj2.get_y()), 2));
}

// Operators overloading
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

Shapes::Vector Shapes::Vector::operator - (const Shapes::Vector& obj) const {
    // Getting this vector's coordinates
    double ax = get_x();
    double ay = get_y();

    // Getting other vector's coordinates
    double bx = obj.get_x();
    double by = obj.get_y();

    return Shapes::Vector(ax - bx, ay - by);
}