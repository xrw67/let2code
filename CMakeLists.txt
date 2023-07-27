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
include(GoogleTest)

function(add_letcode letcode_name)
    add_executable(${letcode_name} src/${letcode_name}.cpp)
    target_link_libraries(${letcode_name} gmock gmock_main)
    gtest_discover_tests(${letcode_name})
endfunction()

add_letcode(002-add-two-numbers)
add_letcode(003-longest-substring-without-repeating-characters)
add_letcode(004-median-of-two-sorted-arrays)
add_letcode(005-longest-palindromic-substring)
add_letcode(006-zigzag-conversion)
add_letcode(007-reverse-integer)
add_letcode(008-string-to-integer-atoi)
add_letcode(009-palindrome-number)
add_letcode(TODO_010-regular-expression-matching)