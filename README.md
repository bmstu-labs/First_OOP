# Shapes management program

## Current todo list
- Decompose project structure (decompose source files and include files into subdirs respectively) (50%)
- Make menu initialization with commands config, not commands themselves
- Do input exception handling (50%)

## How to add custom command

1. Create class inherited from Commands::Command (in commands.hpp)
2. Write code for both execute() and description() functions
3. Create a string you want to use as a key for command
4. Create object of your class
```
std::shared_ptr<YourCommandClass> your_command = std::make_shared<YourCommandClass>();
```
5. Add it to menu
```
menu.add_command(your_key, your_command);
```
6. Run menu

