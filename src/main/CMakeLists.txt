cmake_minimum_required(VERSION 3.14)

set(This thvm)

set(Headers
        cpp/org/thoriumlang/vm/Vm.h
        cpp/org/thoriumlang/vm/Stack.h
        cpp/org/thoriumlang/vm/Program.h
        cpp/org/thoriumlang/vm/op/Op.h
        cpp/org/thoriumlang/vm/op/Nop.h
        cpp/org/thoriumlang/vm/op/Push.h
        cpp/org/thoriumlang/vm/op/Add.h
        cpp/org/thoriumlang/vm/op/Dump.h
        cpp/org/thoriumlang/vm/op/Pop.h
        )
set(Sources
        cpp/org/thoriumlang/vm/Vm.cpp
        cpp/org/thoriumlang/vm/Stack.cpp
        cpp/org/thoriumlang/vm/Program.cpp
        cpp/org/thoriumlang/vm/op/Op.cpp
        cpp/org/thoriumlang/vm/op/Nop.cpp
        cpp/org/thoriumlang/vm/op/Push.cpp
        cpp/org/thoriumlang/vm/op/Add.cpp
        cpp/org/thoriumlang/vm/op/Dump.cpp
        cpp/org/thoriumlang/vm/op/Pop.cpp
        )

add_library(${This}core STATIC ${Sources} ${Headers})

add_executable(${This} cpp/main.cpp)
target_link_libraries(${This} PUBLIC
        ${This}core
        )