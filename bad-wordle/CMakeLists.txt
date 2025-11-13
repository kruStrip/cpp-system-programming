project(bad-wordle)

set(SOURCES
	src/main.cpp
)

include_directories(AFTER
	include
)

add_executable(bad-wordle
	${SOURCES}
)

add_library(wordle_database STATIC
	src/database.cpp
)

target_link_libraries(bad-wordle
	sqlite3
	wordle_database
)

install(TARGETS bad-wordle DESTINATION ${CMAKE_SOURCE_DIR}/out)
