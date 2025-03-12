#include "menu.hpp"

Menu::Menu() : ctx() {
    commands["A"] = std::make_shared<Commands::CreateCommand>("Create new shape");
    commands["B"] = std::make_shared<Commands::DisplayCommand>("Display shapes");
    commands["C"] = std::make_shared<Commands::DisplayWithPerimeterCommand>("Display with perim");
    commands["D"] = std::make_shared<Commands::DeleteByNumber>("Delete by number");
    commands["E"] = std::make_shared<Commands::DeleteWithPerimeterCommand>("Delete by perim");
    commands["F"] = std::make_shared<Commands::GetSumCommand>("Print perim sum");
    commands["G"] = std::make_shared<Commands::SortCommand>("Sort by perim (asc)");
    commands["Q"] = std::make_shared<Commands::QuitCommand>("Quit the program");
}

Menu::Menu(Context &data) : ctx(data) {
    commands["A"] = std::make_shared<Commands::CreateCommand>("Create new shape");
    commands["B"] = std::make_shared<Commands::DisplayCommand>("Display shapes");
    commands["C"] = std::make_shared<Commands::DisplayWithPerimeterCommand>("Display with perim");
    commands["D"] = std::make_shared<Commands::DeleteByNumber>("Delete by number");
    commands["E"] = std::make_shared<Commands::DeleteWithPerimeterCommand>("Delete by perim");
    commands["F"] = std::make_shared<Commands::GetSumCommand>("Print perim sum");
    commands["G"] = std::make_shared<Commands::SortCommand>("Sort by perim (asc)");
    commands["Q"] = std::make_shared<Commands::QuitCommand>("Quit the program");
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
            std::cout << "Wrong command. Enter Q to quit the program safely." << std::endl;
        }

        if (command == "Q") {
            break;
        }
    }
}

void Menu::add_command(const std::string& key, const std::shared_ptr<Commands::Command>& command) {
    if (commands.find(key) == commands.end()) {
        commands[key] = command;
    }
    else {
        std::cout << "Command with such key already exists. Try again." << std::endl;
    }   
}

void Menu::display_options() const {
    for (const auto &it : commands) {
        std::cout << it.first << ". " << it.second->description() << std::endl;
    }
}

std::string Menu::read_input() const {
    std::string command;
    std::cout << "Enter command: ";
    std::cin >> command;

    return command;
}