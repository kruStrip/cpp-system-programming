#include <algorithm>
#include "analysis.h"

extern "C" size_t countWords(const std::string& text)
{
    if (text.empty()) return 0;

    size_t count = 0;
    std::for_each(text.begin(), text.end(), [ &count ]( char ch ){ if (ch == ' ') ++count; });
    return count + 1;
}

extern "C" size_t countParagraphs(const std::string& text)
{
    if (text.empty()) return 0;

    size_t count = 0;
    std::for_each(text.begin(), text.end(), [ &count ]( char ch ){ if (ch == '\n') ++count; });
    return count + 1;
}