#pragma once

#include "shapes.hpp"

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

struct Context {
    std::vector<Shape::Shape*>& shapes;

    Context(std::vector<Shape::Shape*>&);
};

namespace Allocator {
    Shape::Shape *create_circle();

    Shape::Shape *create_rectangle();

    Shape::Shape *create_triangle();
}

namespace Commands {
    class Command {
    public:
        virtual ~Command();
        virtual void execute(Context&) = 0;
        virtual std::string description() const = 0;
    };

    class CreateCommand : public Command {
        void execute(Context&) override;
        std::string description() const override;
    };

    class SortCommand : public Command {
        void execute(Context&) override;
        std::string description() const override;
    };

    class DisplayCommand : public Command {
        void execute(Context&) override;
        std::string description() const override;
    };

    class DisplayWithPerimeterCommand : public Command {
        void execute(Context&) override;
        std::string description() const override;
    };

    class DeleteByNumber : public Command {
        void execute(Context&) override;
        std::string description() const override;
    };

    class DeleteWithPerimeterCommand : public Command {
        void execute(Context&) override;
        std::string description() const override;
    };

    class GetSumCommand : public Command {
        void execute(Context&) override;
        std::string description() const override;
    };

    class QuitCommand : public Command {
        void execute(Context&) override;
        std::string description() const override;
    };
}
