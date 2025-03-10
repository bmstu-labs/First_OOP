#pragma once

#include "shapes/shapes.hpp"
#include "context.hpp"

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <limits>

namespace Commands {
    class Command {
        const std::string message;
    public:
        Command(const std::string);
        
        Command(const char *);

        virtual ~Command();

        virtual void execute(Context&) = 0;

        std::string description() const;
    };

    class CreateCommand : public Command {
            void execute(Context&) override;
        public:
            CreateCommand(const char *);
    };

    class SortCommand : public Command {
            void execute(Context&) override;
        // std::string description() const override;
        public:
            SortCommand(const char *);
    };

    class DisplayCommand : public Command {
            void execute(Context&) override;
        // std::string description() const override;
        public:
            DisplayCommand(const char *);
    };

    class DisplayWithPerimeterCommand : public Command {
            void execute(Context&) override;
        // std::string description() const override;
        public:
            DisplayWithPerimeterCommand(const char *);
    };

    class DeleteByNumber : public Command {
            void execute(Context&) override;
        // std::string description() const override;
        public:
            DeleteByNumber(const char *);
    };

    class DeleteWithPerimeterCommand : public Command {
        void execute(Context&) override;
        // std::string description() const override;
        public:
        DeleteWithPerimeterCommand(const char *);
    };

    class GetSumCommand : public Command {
        void execute(Context&) override;
        // std::string description() const override;
        public:
            GetSumCommand(const char *);
    };

    class QuitCommand : public Command {
        void execute(Context&) override;
        // std::string description() const override;
        public:
            QuitCommand(const char *);
    };
}
