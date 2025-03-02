
#include <vector>
#include <iostream>
#include <map>

#include "shapes/shapes.hpp"
#include "menu.hpp"
#include "context.hpp"

int main() {
    std::vector<Shape::Shape*> shapes;
    Context ctx(shapes);

    Menu menu(ctx);

    menu.run();

    return 0;
}