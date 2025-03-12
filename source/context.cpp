#include "context.hpp"

// Context class

Context::Context() : shapes() {}

Context::Context(std::vector<Shapes::Shape*> &shapes_ref) : shapes(shapes_ref) {};

Context::~Context() {
    for (Shapes::Shape *shape : shapes) {
        if (shape) {
            delete shape;
        }
    }
    shapes.clear();
}