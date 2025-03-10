#include "commands.hpp"
#include "exceptions.hpp"
#include "factory/shapes.hpp"

// Commands

Commands::Command::Command(const std::string name) : message(name) {}

Commands::Command::Command(const char *name) : message(name) {}

Commands::Command::~Command() = default;

std::string Commands::Command::description() const {
    return message;
}

// Create command

Commands::CreateCommand::CreateCommand(const char *name) : Commands::Command(name) {}


void Commands::CreateCommand::execute(Context &ctx) {
    TriangleFactory triangle_factory;
    CircleFactory circle_factory;
    RectangleFactory rectangle_factory;

    std::map<std::string, ShapeFactory *> creation_commands = {
        {"Triangle",    &triangle_factory},
        {"Circle",      &circle_factory},
        {"Rectangle",   &rectangle_factory}
    };

    std::cout << "Enter figure type: ";
    std::string figure_type;
    std::cin >> figure_type;

    try {
        Shapes::Shape *shape = creation_commands.at(figure_type)->create_shape();
        ctx.shapes.push_back(shape);
    }
    catch (std::out_of_range) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Unknown figure type entered. Try again." << std::endl;
    }
    catch (InputError &error) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << error.what() << std::endl;
    }
}

// Sort command

Commands::SortCommand::SortCommand(const char *name) : Commands::Command(name) {}

void Commands::SortCommand::execute(Context& ctx) {
    std::sort(ctx.shapes.begin(), ctx.shapes.end(), 
    [](const Shapes::Shape* a, const Shapes::Shape* b) {
        return *a < *b;
    });
}

// Display command

Commands::DisplayCommand::DisplayCommand(const char *name) : Commands::Command(name) {}

void Commands::DisplayCommand::execute(Context& ctx) {
    for (Shapes::Shape *shape : ctx.shapes) {
        if (shape != nullptr) {
            shape->display();
        }
    }
}

// Display with perimeter command

Commands::DisplayWithPerimeterCommand::DisplayWithPerimeterCommand(const char *name) : Commands::Command(name) {}

void Commands::DisplayWithPerimeterCommand::execute(Context& ctx) {
    for (auto it : ctx.shapes) {
        it->display_with_perimeter();
    }
}

// Delete by number command

Commands::DeleteByNumber::DeleteByNumber(const char *name) : Commands::Command(name) {}

void Commands::DeleteByNumber::execute(Context& ctx) {
    try {
        std::cout << "Write number: ";
        std::size_t index;
        if (!(std::cin >> index)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Invalid input. Enter a number");
        }

        if (index < 1 || index > ctx.shapes.size()) {
            throw std::out_of_range("Number is too big");
        }

        ctx.shapes.erase(ctx.shapes.begin() + index - 1);
        std::cout << "Shape " << index << " has been deleted" << std::endl;
    }
    catch (const std::out_of_range& error) {
        std::cout << error.what() << std::endl;
    }
    catch (const std::runtime_error& error) {
        std::cout << error.what() << std::endl;
    }
}

// Delete by perimeter command

Commands::DeleteWithPerimeterCommand::DeleteWithPerimeterCommand(const char *name) : Commands::Command(name) {}

void Commands::DeleteWithPerimeterCommand::execute(Context& ctx) {
    std::cout << "Enter perimeter: ";
    double perimeter;
    std::cin >> perimeter;

    for (auto it = ctx.shapes.begin(); it != ctx.shapes.end();) {
        if (((*it)->get_perimeter() - perimeter) > EPSILON) {
            ctx.shapes.erase(it);
        }
        else {
            it++;
        }
    }
}

// Get sum commandd

Commands::GetSumCommand::GetSumCommand(const char *name) : Commands::Command(name) {}

void Commands::GetSumCommand::execute(Context& ctx) {
    double sum = 0;
    for (auto it : ctx.shapes) {
        sum += it->get_perimeter();
    }
    std::cout << "Total sum: " << sum << std::endl;
}

// Quit command

Commands::QuitCommand::QuitCommand(const char *name) : Commands::Command(name) {}

void Commands::QuitCommand::execute(Context& ctx) {
    for (Shapes::Shape *shape : ctx.shapes) {
        delete shape;
    }
    ctx.shapes.clear();
}