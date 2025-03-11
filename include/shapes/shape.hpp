#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "dot.hpp"

class Printer;

class PrinterPerim;

namespace Shapes {
    class Shape {
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
            
            virtual void accept(Printer&) const = 0;

            virtual void accept(PrinterPerim&) const = 0;
        };
}