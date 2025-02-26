#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "dot.hpp"

namespace Shape {
    class Shape {
        protected:
            std::string name;
            std::vector<Dot> coordinates;
        public:
            Shape();
        
            const std::string get_name() const;
        
            virtual double get_perimeter() const = 0;
        
            virtual void display() const = 0;
        
            virtual void display_with_perimeter() const = 0;

            virtual void input() = 0;

            bool operator < (Shape&);
        
            virtual ~Shape();
        };
}