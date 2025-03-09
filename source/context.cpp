#include "context.hpp"

// Context class

Context::Context(std::vector<Shape::Shape*> &shapes_ref) : shapes(shapes_ref) {};

Context::~Context() {
    for (Shape::Shape *shape : shapes) {
        delete shape;
    }
    shapes.clear();
}