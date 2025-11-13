#include <database.h>

Database::Database(const std::filesystem::path& path)
{
	int rv = sqlite3_open_v2(path.string().c_str(), &db, SQLITE_OPEN_READONLY, nullptr);
	if (rv != SQLITE_OK)
	{
		throw std::logic_error("Could not open database " + path.string());
	}
}

Database::~Database()
{
	sqlite3_close_v2(db);
}

std::string Database::selectOneWord()
{
	std::string query = "select word from Words where length(word) = 5 order by random() limit 1";
	
	std::string word;
	auto callback = [](void* result, int, char** values, char**) -> int
	{
		auto& ref = *static_cast<std::string*>(result);
		ref = values[0];
		return SQLITE_OK;
	};

	int rv = sqlite3_exec(db, query.c_str(), callback, &word, nullptr);
	if (rv != SQLITE_OK)
	{
		throw std::logic_error("Could not execute query '" + query + "', error " + sqlite3_errmsg(db));
	}
	return word;
}
