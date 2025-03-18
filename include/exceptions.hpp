#pragma once

#include <exception>
#include <string>

class InputError : public std::exception {
    std::string message;
public:
    InputError(const std::string&);
    
    const char *what() const noexcept override;
};

class ShapeIsLineError : public std::exception {
    std::string message;
public:
    ShapeIsLineError(const std::string&);

    const char *what() const noexcept override;
};

class OnePointError : public std::exception {
    std::string message;
public:
    OnePointError(const std::string&);

    const char *what() const noexcept override;
};

class NegativeRadiusError : public std::exception {
    std::string message;
public:
    NegativeRadiusError(const std::string&);

    const char *what() const noexcept override;
};