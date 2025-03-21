# Shapes management program
 
## How to build :hammer:
1. Install make utility 
2. In the command line write `make`
3. Run `./prog.out`

## How does it work :mag_right:
Основные сущности:

**Menu** - основной класс, который собирает другие сущности воедино. В конструкторе заполняет свои поля: таблицу с командами вида ключ-значение (строка и `shared_ptr` на объект класса Command и его наследников) и контекст (объект класса Context). 
Через метод `menu::run()` запускает бесконечный цикл, который сначала вызывает метод `menu::display_options()` (отображает описание всех команд в таблице).  

**Command** - абстрактный класс, имеет два метода: `command::execute()` и `command::description()`. Класс команды хранит в себе описание команды, которое отображется в меню (`menu::display_options()`) черз метод `command::description()`. `command::execute()` содержит основную логику: манипулирует фигурами, может добавлять и удалять фигуры из контекста.

**Shape** - абстрактный класс, основа для всех классов фигур.

**Context** - класс оболочка, который содержит в себе массив из указателей на объекты класса `Shapes::Shape` и его наследников (`std::vector<Shapes::Shape *>`). Используется для передачи данных (фигур) между меню и командами.

**Vector** - класс радиус-вектора. В качестве полей содержит в себе координаты `x` и `y`. Включает в себя методы для работы с векторами в двумерном пространстве (можно представлять как точку, но через векторы удобнее представлять их разность).

**Printer** - абстрактный класс, содержащий методы для вывода объекта класса наследника `Shapes::Shape`.

**ShapeFactory** - абстрактный класс для создания объекта указанного класса. Берет на себя ввод и проверку всех значений и создает объект через конструктор. Может кидать исключения при проверке корректности данных (см. exceptions.hpp).

## How to add custom command :pencil:

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
