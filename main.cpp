
#include <vector>
#include <iostream>

#include "include/shapes.hpp"
#include "include/menu.hpp"

int main() {
    std::vector<Shape::Shape*> shapes;

    Menu menu(shapes);

    menu.run();

    return 0;
}