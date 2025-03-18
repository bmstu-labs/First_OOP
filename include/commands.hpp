#pragma once

#include "context.hpp"
#include <string>

namespace Commands {
    class Command {
        const std::string message;
    public:
        Command(const std::string&);
        
        Command(const char *);

        virtual ~Command() = default;
    public:
        virtual void execute(Context&) = 0;

        std::string description() const;
    };

    class CreateCommand : public Command {
    public:
        CreateCommand(const char *);

        void execute(Context&) override;
    };

    class SortCommand : public Command {
    public:
        SortCommand(const char *);

        void execute(Context&) override;
    };

    class DisplayCommand : public Command {
    public:
        DisplayCommand(const char *);

        void execute(Context&) override;
    };

    class DisplayWithPerimeterCommand : public Command {
    public:
        DisplayWithPerimeterCommand(const char *);

        void execute(Context&) override;
    };

    class DeleteByNumber : public Command {
    public:
        DeleteByNumber(const char *);

        void execute(Context&) override;
    };

    class DeleteWithPerimeterCommand : public Command {
    public:
        DeleteWithPerimeterCommand(const char *);

        void execute(Context&) override;
    };

    class GetSumCommand : public Command {
    public:
        GetSumCommand(const char *);

        void execute(Context&) override;
    };

    class QuitCommand : public Command {
    public:
        QuitCommand(const char *);

        void execute(Context&) override;
    };
}
