# Shapes management program

## How to add custom command

```
// Include all required header files
#include "menu.hpp"
#include "commands.hpp"
#include "context.hpp"


// Custom command inherited from the abstract class Commands::Command
class MyCommad : public Commands::Command {
public:
    MyCommand(const char *description) : message(description) {}

    void execute(Context& ctx) override {
        // your code
        // ...
    }
}

// ...

int main() {
    // Menu initializing
    Menu menu;

    // Custom command object creation
    auto command = std::make_shared<MyCommand>();

    // Add the command to the mnu
    menu.add_command("MyCommandKey", command);

    // Run menu
    menu.run();

    // Code after quitting menu
    // ...

    return 0;
}
```
