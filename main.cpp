#include "include/shapes.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<Shape*> shapes;

    char cmd;
    std::cin >> cmd;
    while (cmd != 'Q') {
        if (cmd == 'A') {
            std::string figure_type;
            std::cin >> figure_type;
            if (figure_type == "Triangle") {
                Triangle *shape = new Triangle();
                std::cin >> *shape;
                shapes.push_back(shape);
            }
            // else if (figure_type == "Rectangle") {
            //     Rectangle *shape = new Rectangle();
            //     std::cin >> *shape;
            //     shapes.push_back(shape);
            // }
            else if (figure_type == "Circle") {
                Circle *shape = new Circle();
                std::cin >> *shape;
                shapes.push_back(shape);
            }
        }
        if (cmd == 'B') {
            std::size_t length = shapes.size(); 
            for (std::size_t i = 0; i < length; i++) {
                std::cout << "Shape " << i + 1 << ' ' << std::endl;
                shapes.at(i)->display();
            }
        }
        if (cmd == 'C') {
            std::size_t length = shapes.size();
            for (std::size_t i = 0; i < length; i++) {
                std::cout << "Shape " << i + 1 << std::endl;
                shapes.at(i)->display_with_perimeter();
            }
        }
        std::cin >> cmd;
    }

    for (auto *ptr : shapes) {
        delete ptr;
    }
    shapes.clear();

    return 0;
}