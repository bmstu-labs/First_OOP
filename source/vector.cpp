#include "vector.hpp"
#include "exceptions.hpp"

Shapes::Vector::Vector() : x(), y() {}

Shapes::Vector::Vector(double f, double s) : x(f), y(s) {}

// Getters
double Shapes::Vector::get_x() const {
    return this->x;
}

double Shapes::Vector::get_y() const {
    return this->y;
}

// Checking function
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

// Linear functions
double Shapes::Vector::get_length() const {
    return sqrt(pow(get_x(), 2) + pow(get_y(), 2));
}

double Shapes::Vector::get_length(const Vector& obj1, const Vector& obj2) {
    return sqrt(pow((obj1.get_x() - obj2.get_x()), 2) + pow((obj1.get_y() - obj2.get_y()), 2));
}

double Shapes::Vector::cos(const Vector& obj1, const Vector& obj2) {
    // Getting the vector obj1 coords
    double ax = obj1.get_x();
    double ay = obj1.get_y();

    // Getting the vector obj2 coords
    double bx = obj2.get_x();
    double by = obj2.get_y();

    // Computing cosinus between vectors a and b
    double cos_phi = ax * bx + ay * by;
    cos_phi /= sqrt(pow(ax, 2) + pow(ay, 2));
    cos_phi /= sqrt(pow(bx, 2) + pow(by, 2));

    return cos_phi;
}

double Shapes::Vector::angle(const Vector& obj1, const Vector& obj2) {
    double cos_phi = Shapes::Vector::cos(obj1, obj2);
    if (fabs(cos_phi - 1) < Shapes::EPSILON) {
        cos_phi = 1;
    }
    else if (fabs(cos_phi + 1) < Shapes::EPSILON) {
        cos_phi = -1;
    }

    return acos(cos_phi);
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