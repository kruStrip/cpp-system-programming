project(sample)

message(STATUS "Using standart C++${CMAKE_CXX_STANDART}")

add_compile_options(-std=c++20)

message(STATUS ${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME}
	main.cpp
)

add_library(library_loading STATIC
	library_loading.cpp
)

add_library(text_analysis SHARED
	analysis.cpp
)

add_library(text_processing SHARED
	process.cpp
)

target_link_libraries(${PROJECT_NAME}
	library_loading
	${CMAKE_DL_LIBS}
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/out)
