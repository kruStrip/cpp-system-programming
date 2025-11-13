#include <unistd.h>
#include <stdlib.h>
#include <iostream>

int main(int /*argc*/, char *argv[])
{
    const char* editor = getenv("EDITOR");
    if (editor == nullptr)
    {
        editor = "nano";
    }

    execvp(editor, argv);
    return 1;
}