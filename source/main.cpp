#include <iostream>

#include "libcommandline/flag.h"
#include "libcommandline/interface.h"

int main()
{
    NonNullSharedPtr<LibCommandLine::Flag> flag{'f'};
    LibCommandLine::addOption(flag);
    LibCommandLine::parse("utility_name -f");
    if (flag)
    {
        std::cout << "-f is set\n";
    }
}
