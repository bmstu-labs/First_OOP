#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "dot.hpp"

namespace Shapes {
    class Shape {
        // should be private
        private: 
            const std::string name;
        public:
            Shape(const std::string);

            bool operator < (const Shape&) const;
        
            virtual ~Shape() = default;
        public:
            std::string get_name() const;
        
            virtual double get_perimeter() const = 0;

            virtual std::vector<Shapes::Dot> get_points() const = 0;
        
            virtual void display() const = 0;
        
            virtual void display_with_perimeter() const = 0;

            // virtual void input() = 0;
        };
}