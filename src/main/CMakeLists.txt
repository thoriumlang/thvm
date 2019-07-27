set(This thvm)

set(Headers
        cpp/org/thoriumlang/vm/Vm.h
        cpp/org/thoriumlang/vm/Stack.h
        cpp/org/thoriumlang/vm/op/Op.h
        cpp/org/thoriumlang/vm/op/Nop.h
        cpp/org/thoriumlang/vm/op/Push.h
        cpp/org/thoriumlang/vm/op/Add.h
        cpp/org/thoriumlang/vm/op/Dump.h
        cpp/org/thoriumlang/vm/op/Pop.h
        cpp/org/thoriumlang/vm/StackOverflow.h
        cpp/org/thoriumlang/vm/StackUnderflow.h
        cpp/org/thoriumlang/vm/Code.h
        cpp/org/thoriumlang/vm/opcodes.h)
set(Sources
        cpp/org/thoriumlang/vm/Vm.cpp
        cpp/org/thoriumlang/vm/Stack.cpp
        cpp/org/thoriumlang/vm/op/Op.cpp
        cpp/org/thoriumlang/vm/op/Nop.cpp
        cpp/org/thoriumlang/vm/op/Push.cpp
        cpp/org/thoriumlang/vm/op/Add.cpp
        cpp/org/thoriumlang/vm/op/Dump.cpp
        cpp/org/thoriumlang/vm/op/Pop.cpp
        cpp/org/thoriumlang/vm/StackOverflow.cpp
        cpp/org/thoriumlang/vm/StackUnderflow.cpp
        cpp/org/thoriumlang/vm/Code.cpp)

add_library(${This}core STATIC ${Sources} ${Headers})

add_executable(${This} cpp/main.cpp)
target_link_libraries(${This} PUBLIC ${This}core)