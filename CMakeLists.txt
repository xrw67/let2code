cmake_minimum_required(VERSION 3.14)
project(let2code)

enable_testing()

####################################################################
# 3rd
####################################################################
add_subdirectory(3rd/googletest)


####################################################
# Set the C++ Standard to be used (Default to C++17)
####################################################
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

####################################################################
# Set Compiler flags
####################################################################
IF (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++${CXX_STANDARD}")
ELSEIF (MSVC)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
ENDIF()


include_directories(
        3rd
        3rd/googletest/googlemock/include
        3rd/googletest/googletest/include
)

add_subdirectory(letcode)
add_subdirectory(kata)