set(This thvm_test)

set(Sources
        cpp/org/thoriumlang/vm/StackTest.cpp
        cpp/org/thoriumlang/vm/op/AddTest.cpp
        cpp/org/thoriumlang/vm/op/PushTest.cpp
        cpp/org/thoriumlang/vm/op/PopTest.cpp
        cpp/org/thoriumlang/vm/CodeTest.cpp)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC gtest_main thvmcore)

add_test(
        NAME ${This}
        COMMAND ${This}
)