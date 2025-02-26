
#include <vector>
#include <iostream>
#include <map>

#include "include/shapes.hpp"
#include "include/menu.hpp"

int main() {
    std::vector<Shape::Shape*> shapes;

    Menu menu(shapes);

    menu.run();

    return 0;
}