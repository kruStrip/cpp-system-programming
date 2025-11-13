#include <unistd.h>
#include <iostream>

// 0 - std::cin
// 1 - std::cout
// 2 - std::cerr
int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        size_t count;
        for (count = 0; argv[i][count] != '\0'; ++count);

        write(1, argv[i], count);
        write(1, " ", 1);
    }
    write(1, "\n", 1);
    return 0;
}