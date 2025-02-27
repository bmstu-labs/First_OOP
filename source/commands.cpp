#include "commands.hpp"

// Context class

Context::Context(std::vector<Shape::Shape*> &shapes_ref) : shapes(shapes_ref) {};

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

// Commands

Commands::Command::~Command() = default;

// Create command

void Commands::CreateCommand::execute(Context& ctx) {
    std::map<std::string, Shape::Shape *(*)()> creation_commands = {
        {"Triangle",    Allocator::create_triangle},
        {"Circle",      Allocator::create_circle},
        {"Rectangle",   Allocator::create_rectangle}
    };

    std::cout << "Enter figure type: ";
    std::string figure_type;
    std::cin >> figure_type;

    try {
        Shape::Shape *shape = creation_commands.at(figure_type)();
        shape->input();
        ctx.shapes.push_back(shape);
    }
    catch (std::out_of_range) {
        std::cout << "Unknown figure type entered. Try again." << std::endl;
    };
};

std::string Commands::CreateCommand::description() const {
    return "Create new shape";
}

// Sort command

void Commands::SortCommand::execute(Context& ctx) {
    std::sort(ctx.shapes.begin(), ctx.shapes.end());
}

std::string Commands::SortCommand::description() const {
    return "Sort figures by perimeter (asc)";
}

// Display command

void Commands::DisplayCommand::execute(Context& ctx) {
    for (Shape::Shape *shape : ctx.shapes) {
        if (shape != nullptr) {
            shape->display();
        }
    }
}

std::string Commands::DisplayCommand::description() const {
    return "Display shapes";
}

// Display with perimeter command

void Commands::DisplayWithPerimeterCommand::execute(Context& ctx) {
    for (auto it : ctx.shapes) {
        it->display_with_perimeter();
    }
}

std::string Commands::DisplayWithPerimeterCommand::description() const {
    return "Display with perimeter";
}

// Delete by number command

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

std::string Commands::DeleteByNumber::description() const {
    return "Delete by number";
}

// Delete by perimeter command

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

std::string Commands::DeleteWithPerimeterCommand::description() const {
    return "Delete shapes with perimeter more than...";
}

// Get sum commandd

void Commands::GetSumCommand::execute(Context& ctx) {
    double sum = 0;
    for (auto it : ctx.shapes) {
        sum += it->get_perimeter();
    }
    std::cout << "Total sum: " << sum << std::endl;
}

std::string Commands::GetSumCommand::description() const {
    return "Get sum of perimeter of all shapes";
}

// Quit command

void Commands::QuitCommand::execute(Context& ctx) {
    for (Shape::Shape *shape : ctx.shapes) {
        delete shape;
    }
    ctx.shapes.clear();
}

std::string Commands::QuitCommand::description() const {
    return "Quit the program";
}