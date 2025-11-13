#include "process.h"
#include <algorithm>

std::string replace(const std::string& text, char what, char to)
{
    std::string copy = text;
    std::replace(copy.begin(), copy.end(), what, to);
    return copy;
}