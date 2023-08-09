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
add_subdirectory(letcode)
add_subdirectory(game-kata)