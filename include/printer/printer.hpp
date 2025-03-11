#pragma once

namespace Shapes {
    class Shape;
    class Circle;
    class Rectangle;
    class Triangle;
}

class Printer {
public:
    void visit_default(const Shapes::Shape&) const;

    void visit(const Shapes::Circle&) const;

    void visit(const Shapes::Triangle&) const;

    void visit(const Shapes::Rectangle&) const;
};