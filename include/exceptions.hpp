#pragma once

#include <exception>
#include <string>

class InputError : public std::exception {
    std::string message;
public:
    InputError(const std::string &);
    
    const char *what() const noexcept override;
};

// add triangle exception