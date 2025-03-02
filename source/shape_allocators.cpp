#include "shape_allocators.hpp"

// Memory allocators

Shape::Shape *Allocator::create_circle() {
    return new Shape::Circle();
}

Shape::Shape *Allocator::create_triangle() {
    return new Shape::Triangle();
}

Shape::Shape *Allocator::create_rectangle() {
    return new Shape::Rectangle();
}