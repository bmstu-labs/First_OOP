#pragma once

#include <vector>
#include <string>

#include "vector.hpp"

class IPrinter;

namespace Shapes {
    class Shape {
        private: 
            const std::string name;
        public:
            Shape(const std::string&);

            bool operator < (const Shape&) const;
        
            virtual ~Shape() = default;
        public:
            std::string get_name() const;
        
            virtual double get_perimeter() const = 0;

            virtual std::vector<Shapes::Vector> get_points() const = 0;
            
            virtual void accept(const IPrinter *) const = 0;
        };
}