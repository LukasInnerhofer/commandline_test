#include <iostream>

#include "libcommandline/flag.h"
#include "libcommandline/parser.h"

int main(int argc, char const *argv[])
{
    auto f{makeNonNullShared<LibCommandLine::Flag>('f')};
    auto g{makeNonNullShared<LibCommandLine::Flag>('g')};
    LibCommandLine::Parser::addOption(f);
    LibCommandLine::Parser::addOption(g);
    LibCommandLine::Parser::parse(argc, argv);
    if (*f)
    {
        std::cout << "-f is set\n";
    }
    if (*g)
    {
        std::cout << "-g is set\n";
    }
}
