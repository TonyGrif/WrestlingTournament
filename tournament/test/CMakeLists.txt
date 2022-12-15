enable_testing()
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)
include(GoogleTest)

set(TESTS
    cpp/main.cpp
    cpp/Test_Wrestler.cpp
    cpp/Test_Team.cpp
    cpp/Test_Tournament.cpp
    )

add_executable(Test${PROJECT_NAME} ${TESTS})

target_link_libraries(
    Test${PROJECT_NAME}
    GTest::gtest_main
    Tournament
    )

gtest_discover_tests(Test${PROJECT_NAME})