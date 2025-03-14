#include "exceptions.hpp"

InputError::InputError(const std::string& msg) : message(msg) {}

const char *InputError::what() const noexcept {
    return message.c_str();
}

ShapeIsLineError::ShapeIsLineError(const std::string& msg) : message(msg) {}

const char *ShapeIsLineError::what() const noexcept {
    return message.c_str();
}

OnePointError::OnePointError(const std::string& msg) : message(msg) {}

const char *OnePointError::what() const noexcept {
    return message.c_str();
}