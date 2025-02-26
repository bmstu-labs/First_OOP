#include "menu.hpp"

Menu::Menu(std::vector<Shape::Shape*>& shapes) : ctx(shapes) {
    commands["A"] = std::make_unique<Commands::CreateCommand>();
    commands["B"] = std::make_unique<Commands::DisplayCommand>();
    commands["C"] = std::make_unique<Commands::DeleteByNumber>();
    commands["Q"] = std::make_unique<Commands::QuitCommand>();
}

void Menu::run() {
    while(true) {
        Menu::display_options();
        std::string command = read_input();

        auto it = commands.find(command);
        if (it != commands.end()) {
            it->second->execute(ctx);
        }
        else {
            std::cout << "Wrong command. Try again." << std::endl;
        }

        if (command == "Q") {
            break;
        }
    }
}

void Menu::display_options() const {
    for (auto &it : commands) {
        std::cout << it.first << ". " << it.second->description() << std::endl;
    }
}

std::string Menu::read_input() const {
    std::string command;
    std::cin >> command;

    return command;
}