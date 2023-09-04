function(add_kata kata_name)
    add_executable(${kata_name}_test ${kata_name}/${kata_name}.cpp)
    add_test(kata_${kata_name} ${kata_name}_test)
endfunction()

add_kata(bowling_game)
