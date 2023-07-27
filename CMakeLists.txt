cmake_minimum_required(VERSION 3.14)
project(tdd4letcode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include_directories(
        googletest/googlemock/include
        googletest/googletest/include
)

add_subdirectory(googletest)

file(GLOB SRCS src/*.cpp)
add_executable(letcode_test ${SRCS})
target_link_libraries(letcode_test gmock gmock_main)

include(GoogleTest)
gtest_discover_tests(letcode_test)