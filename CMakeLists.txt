cmake_minimum_required(VERSION 4.0)
project(aoc_cpp_2025)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Main

add_executable(${PROJECT_NAME}
        src/days/day01.cpp
        src/util.cpp
        src/main.cpp
        src/days/day02.cpp)

target_include_directories(${PROJECT_NAME}
        PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Tests

enable_testing()

add_executable(tests tests/days/testDay01.cpp
        src/days/day01.cpp
        src/util.cpp)

target_link_libraries(tests GTest::gtest GTest::gtest_main)

target_include_directories(tests
        PRIVATE ${PROJECT_SOURCE_DIR}/include)

include(GoogleTest)
gtest_discover_tests(tests)