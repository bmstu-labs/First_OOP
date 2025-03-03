#pragma once

#include <map>
#include <memory>
#include <string>

#include "commands.hpp"
#include "context.hpp"

class Menu {
    Context ctx;
    std::map<std::string, std::shared_ptr<Commands::Command>> commands;
public:
    Menu(Context &);

    void run();

    void add_command(const std::string&, const std::shared_ptr<Commands::Command>&);

    std::string read_input() const;

    void display_options() const;
};