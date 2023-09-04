cmake_minimum_required(VERSION 3.14)
project(let2code)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include_directories(
        3rd
        3rd/googletest/googlemock/include
        3rd/googletest/googletest/include
)

add_subdirectory(3rd/googletest)
add_subdirectory(letcode)
add_subdirectory(game_kata)