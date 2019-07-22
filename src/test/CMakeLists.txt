cmake_minimum_required(VERSION 3.14)

set(This thvm_test)

set(Sources
        cpp/org/thoriumlang/vm/StackTest.cpp
        cpp/org/thoriumlang/vm/ProgramTest.cpp)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
        gtest_main
        thvmcore
        )

add_test(
        NAME ${This}
        COMMAND ${This}
)