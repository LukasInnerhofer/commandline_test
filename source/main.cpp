#include <iostream>

#include "libcommandline/flag.h"
#include "libcommandline/interface.h"

int main(int argc, char const *argv[])
{
    auto f{LibUtilities::makeNonNullShared<LibCommandLine::Flag>('f')};
    auto g{LibUtilities::makeNonNullShared<LibCommandLine::Flag>('g')};
    LibCommandLine::addOption(f);
    LibCommandLine::addOption(g);
    LibCommandLine::parse(argc, argv);
    if (*f)
    {
        std::cout << "-f is set\n";
    }
    if (*g)
    {
        std::cout << "-g is set\n";
    }
}
