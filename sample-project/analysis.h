#ifndef TEXT_ANALYSIS
#define TEXT_ANALYSIS

#include <string>

extern "C"
{

size_t countWords(const std::string& text);

size_t countParagraphs(const std::string& text);

}

typedef size_t (countWordsT)(const std::string& text);
typedef size_t (countParagraphsT)(const std::string& text);

#endif // TEXT_ANALYSIS