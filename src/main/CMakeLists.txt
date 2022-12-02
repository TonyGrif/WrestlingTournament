add_executable(${PROJECT_NAME} cpp/main.cpp)

set(SOURCES
	cpp/Wrestler.cpp
	)

add_library(Tournament ${SOURCES})
target_link_libraries(${PROJECT_NAME} Tournament)