#pragma once

#include <map>
#include <memory>
#include <string>

#include "commands.hpp"
#include "context.hpp"

class Menu {
    Context ctx;
    std::map<std::string, std::unique_ptr<Commands::Command>> commands;
public:
    Menu(Context &);

    void run();

    std::string read_input() const;

    void display_options() const;
};