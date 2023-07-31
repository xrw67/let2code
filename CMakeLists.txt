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

function(add_letcode letcode_name)
    add_executable(${letcode_name}_test src/${letcode_name}.cpp)
    target_link_libraries(${letcode_name}_test gmock gmock_main)
    add_test(${letcode_name} ${letcode_name}_test)
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
add_letcode(011-container-with-most-water)
add_letcode(012-integer-to-roman)
add_letcode(013-roman-to-integer)