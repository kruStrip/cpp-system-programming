#include <iostream>
#include "analysis.h"
#include "process.h"
#include "library_loading.h"

static const std::string analysisPath = "/home/user/Projects/SampleProject/build/sample_project/libtext_analysis.so";

int main()
{
#ifdef _NDEBUG
	std::cout << analysisPath << std::endl;
#endif

	try
	{
		LibraryLoader analysis(analysisPath);
		auto countWordsF = analysis.get_symbol<countWordsT>( "countWords" );
		auto countParagraphsF = analysis.get_symbol<countParagraphsT>( "countParagraphs" );

		std::string text;
		std::cout << "Enter your text:\n";
		std::string str;
		while (std::getline(std::cin, str) && str != "")
		{
			text.append(str).append("\n");
		}

		std::cout << "Word count: " << countWordsF(text) << "\n";
		std::cout << "Paragraphs count: " << countParagraphsF(text) << "\n";
	}
	catch (const std::exception& exc)
	{
		std::cerr << "Exception occurred: " << exc.what() << std::endl;
		return EXIT_FAILURE;
	}

	return 0;
}
