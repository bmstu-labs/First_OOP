#include "menu.hpp"

Menu::Menu(Context &data) : ctx(data) {
    commands["A"] = std::make_shared<Commands::CreateCommand>();
    commands["B"] = std::make_shared<Commands::DisplayCommand>();
    commands["C"] = std::make_shared<Commands::DisplayWithPerimeterCommand>();
    commands["C"] = std::make_shared<Commands::DeleteByNumber>();
    commands["E"] = std::make_shared<Commands::DeleteWithPerimeterCommand>();
    commands["F"] = std::make_shared<Commands::GetSumCommand>();
    commands["G"] = std::make_shared<Commands::SortCommand>();
    commands["Q"] = std::make_shared<Commands::QuitCommand>();
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
            std::cout << "Wrong command. Try again" << std::endl;
        }

        if (command == "Q") {
            break;
        }
    }
}

void Menu::add_command(const std::string& key, const std::shared_ptr<Commands::Command>& command) {
    try {
        commands.at(key);
        std::cout << "Command with such key already exists. Try again." << std::endl;
    }
    catch (std::out_of_range) {
        commands[key] = command;
    }
}

void Menu::display_options() const {
    for (auto &it : commands) {
        std::cout << it.first << ". " << it.second->description() << std::endl;
    }
}

std::string Menu::read_input() const {
    std::string command;
    std::cout << "Enter command: ";
    std::cin >> command;

    return command;
}