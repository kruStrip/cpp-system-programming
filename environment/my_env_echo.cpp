#include <unistd.h>
#include <stdlib.h>
#include <string_view>
#include <string>

enum class TextColor
{
    CLEAR = 0,
    RED = 91,
    GREEN = 92,
    YELLOW = 93,
    BLUE = 34,
    PURPLE = 35
};

#define RETURN_COLOR(txt) \
if (color == #txt) return txt

TextColor defineColor(std::string_view color)
{
    using enum TextColor;
    RETURN_COLOR(RED);
    RETURN_COLOR(GREEN);
    RETURN_COLOR(YELLOW);
    RETURN_COLOR(BLUE);
    RETURN_COLOR(PURPLE);
    return CLEAR;
}

int main(int argc, char *argv[])
{
    const char * ifs = getenv("IFS");
    if ( ifs == nullptr )
    {
        ifs = " ";
    }

    TextColor txtColor;
    const char * color = getenv("TEXT_COLOR");
    if (color == nullptr)
    {
        txtColor = TextColor::CLEAR;
    }
    else
    {
        txtColor = defineColor(color);
    }

    std::string col = "\033[" + std::to_string(static_cast<int>(txtColor)) + "m";
    write(STDOUT_FILENO, col.c_str(), col.size());
    for (int i = 1; i < argc; ++i)
    {
        size_t count;
        for (count = 0; argv[i][count] != '\0'; ++count);
        
        write(STDOUT_FILENO, argv[i], count);
        write(STDOUT_FILENO, ifs, 1);
    }
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "\033[0m", sizeof("\033[0m") - 1);

    return 0;
}