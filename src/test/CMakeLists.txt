enable_testing()
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(${PROJECT_NAME}_Test cpp/main.cpp)

set(TESTS
    )

add_library(Testing ${TESTS})
target_link_libraries(${PROJECT_NAME}_Test Testing)

target_link_libraries(
    ${PROJECT_NAME}_TEST
    GTest::GTest
    Tournament
    )

gtest_discover_tests(${PROJECT_NAME}_Test)
