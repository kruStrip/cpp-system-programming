#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <filesystem>

class Database
{
public:
	explicit Database(const std::filesystem::path& path);

	virtual ~Database();

	std::string selectOneWord();

private:
	sqlite3* db;
};

#endif // DATABASE_H
