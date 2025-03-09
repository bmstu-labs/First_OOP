# Shapes management program

## Current todo list
- Add painter classes (interface ShapePrinter and its children: CirclePrinter, TrianglePrinter, RectanglePrinter, etc.)
- Add factory for shapes
- Implement constructor with arguments for shapes
- Implement output for shapes
- Add comments (menu.cpp and .hpp, dot.cpp andd .hpp)
- Add input exception handling

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

