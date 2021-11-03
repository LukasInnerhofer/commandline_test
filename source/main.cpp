#include <iostream>

#include "libcommandline/flag.h"
#include "libcommandline/multi_option.h"
#include "libcommandline/parser.h"

int main(int argc, char const *argv[])
{
    auto f{makeNonNullShared<LibCommandLine::Flag>('f')};
    auto g{makeNonNullShared<LibCommandLine::Flag>('g')};
    auto i{makeNonNullShared<LibCommandLine::MultiOption>('i')};
    LibCommandLine::Parser::addOption(f);
    LibCommandLine::Parser::addOption(g);
    LibCommandLine::Parser::addOption(i);
    LibCommandLine::Parser::parse(argc, argv);
    if (*f)
    {
        std::cout << "-f is set\n";
    }
    if (*g)
    {
        std::cout << "-g is set\n";
    }
    auto args = i->getArguments();
    if (!args.empty())
    {
        std::cout << "-i passed with arguments:\n";
        for (auto arg : args)
        {
            std::cout << arg << "\n";
        }
    }
}
