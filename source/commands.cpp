#include "commands.hpp"
#include "exceptions.hpp"
#include "factory/shapes.hpp"
#include "printer/printers.hpp"
#include "shapes/shapes.hpp"


#include <map>
#include <algorithm>
#include <limits>
#include <iostream>

// Commands

Commands::Command::Command(const std::string name) : message(name) {}

Commands::Command::Command(const char *name) : message(name) {}

std::string Commands::Command::description() const {
    return message;
}

// Create command

Commands::CreateCommand::CreateCommand(const char *name) : Commands::Command(name) {}

void Commands::CreateCommand::execute(Context &ctx) {
    // Factories
    TriangleFactory triangle_factory;
    CircleFactory circle_factory;
    RectangleFactory rectangle_factory;
    PolyangleFactory polyangle_factory;

    std::map<std::string, ShapeFactory *> creation_commands = {
        {"Triangle",    &triangle_factory},
        {"Circle",      &circle_factory},
        {"Rectangle",   &rectangle_factory},
        {"Polyangle",   &polyangle_factory}
    };

    // Shape type enter. The only 3 shapes are available by default
    std::cout << "Enter figure type: ";
    std::string figure_type;
    std::cin >> figure_type;

    try {
        auto it = creation_commands.find(figure_type);
        if (it != creation_commands.end()) {
            Shapes::Shape *shape = (*it).second->create_shape();
            ctx.shapes.push_back(shape);
        }
        else {
            std::cout << "Unknown shape type" << std::endl;
        }
    }

    // Being catched if letters are in the input (only digits are needed)
    catch (InputError& error) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << error.what() << std::endl;
    }
    catch (ShapeIsLineError& error) {
        std::cout << error.what() << std::endl;
    }
    catch (OnePointError& error) {
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
    Printer printer;
    for (Shapes::Shape *shape : ctx.shapes) {
        if (shape != nullptr) {
            shape->accept(printer);
        }
    }
}

// Display with perimeter command

Commands::DisplayWithPerimeterCommand::DisplayWithPerimeterCommand(const char *name) : Commands::Command(name) {}

void Commands::DisplayWithPerimeterCommand::execute(Context& ctx) {
    PrinterPerim printer;
    for (auto it : ctx.shapes) {
        it->accept(printer);
    }
}

// Delete by number command

Commands::DeleteByNumber::DeleteByNumber(const char *name) : Commands::Command(name) {}

void Commands::DeleteByNumber::execute(Context& ctx) {
    std::cout << "Write number: ";
    std::size_t index;
    if (!(std::cin >> index)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid number format. Enter again." << std::endl;
    }
    else {
        if (index <= 0 || index > ctx.shapes.size()) {
            std::cout << "Number is too big" << std::endl;
        } 
        else {
            ctx.shapes.erase(ctx.shapes.begin() + index - 1);
            std::cout << "Shape " << index << " has been deleted" << std::endl;
        }
    }
}

// Delete by perimeter command

Commands::DeleteWithPerimeterCommand::DeleteWithPerimeterCommand(const char *name) : Commands::Command(name) {}

void Commands::DeleteWithPerimeterCommand::execute(Context& ctx) {
    std::cout << "Enter perimeter: ";
    double perimeter;
    std::cin >> perimeter;

    for (auto it = ctx.shapes.begin(); it != ctx.shapes.end();) {
        if (((*it)->get_perimeter() - perimeter) > Shapes::EPSILON) {
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