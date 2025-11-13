#include <iostream>
#include <database.h>
#include <array>
#include <algorithm>

void check_word(std::string& w, std::string& nw)
{
	static int color_green = 92, color_orange = 33;
	std::array<int, 5> guesses{};
	for (int i = 0; i < 5; ++i)
	{
		if (w[i] == nw[i])
		{
			guesses[i] = 1;
		}
		else if (w.find(nw[i]) != std::string::npos)
		{
			guesses[i] = 2;
		}
		else
		{
			guesses[i] = 0;
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		int color = 0;
		switch (guesses[i])
		{
			case 1:
				color = color_green;
				break;
			case 2:
				color = color_orange;
				break;
			default:
				break;
		}
		std::cout << "\033[" << color << "m" << nw[i] << "\033[0m";
	}
	std::cout << "\n";
}

int main()
{
#ifdef _NDEBUG
	std::cout << "Sqlite3 version: " << sqlite3_libversion() << std::endl;
#endif

	try
	{
		Database db("database.db");
		std::string word = db.selectOneWord();
#ifdef _NDEBUG
	std::cout << "Word = " << word << std::endl;
#endif

		while (true)
		{
			std::string word_guess;
			std::cout << "Enter your word: ";
			std::cin >> word_guess;
			
			if (word.size() != 5 && !std::all_of(word.begin(), word.end(), [](char ch) -> bool { return std::isalpha(ch); }))
			{
				std::cout << "Not a valid word" << std::endl;
				continue;
			}

			check_word(word, word_guess);
			if (word == word_guess)
			{
				break;
			}
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception occurred: " << ex.what() << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "You guessed it!" << std::endl;
	return 0;
}
