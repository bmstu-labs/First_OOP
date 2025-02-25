#include "include/commands.hpp"

Commands::Command::~Command() = default;

void Commands::CreateCommand::execute(Context& ctx) {
    // std::map<std::string, 
    // Need to choose figures to create; Typename??
    std::string figure_type;
    std::cin >> figure_type;
    if (figure_type == "Triangle") {
        Shape::Triangle *shape = new Shape::Triangle();
        std::cin >> *shape;
        ctx.shapes.push_back(shape);
    } 
    if (figure_type == "Circle") {
        Shape::Circle *shape = new Shape::Circle();
        std::cin >> *shape;
        ctx.shapes.push_back(shape);
    }
    if (figure_type == "Rectangle") {
        Shape::Rectangle *shape = new Shape::Rectangle();
        std::cin >> *shape;
        ctx.shapes.push_back(shape);
    }
};

void Commands::SortCommand::execute(Context& ctx) {
    std::sort(ctx.shapes.begin(), ctx.shapes.end());
}

void Commands::DisplayCommand::execute(Context& ctx) {
    for (auto it : ctx.shapes) {
        it->display();
    }
}

void Commands::DeleteWithPerimeterCommand::execute(Context& ctx) {
    for (auto it : ctx.shapes) {
        it->display_with_perimeter();
    }
}

void Commands::DeleteByNumber::execute(Context& ctx) {
    try {
        std::cout << "Write number: ";
        std::size_t index;
        std::cin >> index;

        ctx.shapes.erase(ctx.shapes.begin() + index - 1);
    }
    catch (std::out_of_range) {
        std::cout << "Something went wrong. Try again." << std::endl;
    }
}

void Commands::DeleteWithPerimeterCommand::execute(Context& ctx) {
    try {
        std::cout << "Enter perimeter: ";
        double perimeter;
        std::cin >> perimeter;

        // !!! ACHTUNG. WATNING. REWRITE ELEMENT ERASING !!!
        // it's okey to use ctx.shapes.size() because the compiler will call once automatically
        for (std::size_t index = 0; index < ctx.shapes.size(); index++) {
            if (fabs(ctx.shapes.at(0)->get_perimeter() - perimeter) > EPSILON) {
                ctx.shapes.erase(ctx.shapes.begin() + index);
            }
        }
    }
    catch (std::out_of_range) {
        std::cout << "Something went wrong. Try again." << std::endl;
    }
}

void Commands::QuitCommand::execute(Context& ctx) {
    for (Shape::Shape *shape : ctx.shapes) {
        delete shape;
    }
    ctx.shapes.clear();
}

