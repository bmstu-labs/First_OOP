
#include <vector>
#include <iostream>
#include <map>

#include "shapes/shapes.hpp"
#include "menu.hpp"
#include "context.hpp"
#include "commands.hpp"

class UserCommand : public Commands::Command {
public:
    void execute(Context& ctx) override {
        std::cout << "Hello" << std::endl;
    }

    std::string description() const override {
        return "Print Hello";
    }
};

int main() {
    std::vector<Shape::Shape*> shapes;
    
    Context ctx(shapes);

    Menu menu(ctx);

    // menu.add_command("H", std::make_shared<UserCommand>());

    menu.run();

    return 0;
}