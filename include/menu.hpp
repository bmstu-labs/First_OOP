#pragma once

#include <map>
#include <memory>
#include <string>

#include "commands.hpp"

class Menu {
    Context ctx;
    std::map<std::string, std::unique_ptr<Commands::Command>> commands;
public:
    Menu(std::vector<Shape::Shape*>&);

    void run();

    std::string read_input() const;

    void display_options() const;
};