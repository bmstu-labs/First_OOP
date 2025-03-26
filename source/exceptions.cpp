#include "exceptions.hpp"

InputError::InputError(const std::string &msg) : message(msg) {}

const char *InputError::what() const noexcept {
    return message.c_str();
}

ShapeIsLineError::ShapeIsLineError(const std::string &msg) : message(msg) {}

const char *ShapeIsLineError::what() const noexcept {
    return message.c_str();
}

OnePointError::OnePointError(const std::string &msg) : message(msg) {}

const char *OnePointError::what() const noexcept {
    return message.c_str();
}

NegativeRadiusError::NegativeRadiusError(const std::string &msg) : message(msg) {}

const char *NegativeRadiusError::what() const noexcept {
    return message.c_str();
}

ConcavePolygon::ConcavePolygon(const std::string &msg) : message(msg) {}

const char *ConcavePolygon::what() const noexcept {
    return message.c_str();
}