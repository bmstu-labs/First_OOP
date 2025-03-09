#pragma once

#include "shapes/shapes.hpp"

// to do fabric

namespace Allocator {
    Shape::Shape *create_circle();

    Shape::Shape *create_rectangle();

    Shape::Shape *create_triangle();
}