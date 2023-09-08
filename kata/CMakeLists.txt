list(APPEND KATA_UNIT_TESTS
    hello
    bowling_game
    integer_to_binary
    fizzbuzz
)

foreach(TEST ${KATA_UNIT_TESTS})
    add_executable(${TEST}_test "${CMAKE_SOURCE_DIR}/kata/${TEST}/${TEST}.cpp")
    add_test(${TEST} ${TEST}_test)
endforeach()