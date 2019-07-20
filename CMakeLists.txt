cmake_minimum_required(VERSION 3.14)
project(thvm)

set(CMAKE_CXX_STANDARD 17)

add_executable(thvm src/main/cpp/main.cpp src/main/cpp/org/thoriumlang/vm/Vm.cpp src/main/cpp/org/thoriumlang/vm/Vm.h src/main/cpp/org/thoriumlang/vm/Stack.cpp src/main/cpp/org/thoriumlang/vm/Stack.h src/main/cpp/org/thoriumlang/vm/op/Nop.cpp src/main/cpp/org/thoriumlang/vm/op/Nop.h src/main/cpp/org/thoriumlang/vm/op/Op.cpp src/main/cpp/org/thoriumlang/vm/op/Op.h src/main/cpp/org/thoriumlang/vm/Program.cpp src/main/cpp/org/thoriumlang/vm/Program.h src/main/cpp/org/thoriumlang/vm/op/Push.cpp src/main/cpp/org/thoriumlang/vm/op/Push.h src/main/cpp/org/thoriumlang/vm/op/Add.cpp src/main/cpp/org/thoriumlang/vm/op/Add.h src/main/cpp/org/thoriumlang/vm/op/Dump.cpp src/main/cpp/org/thoriumlang/vm/op/Dump.h src/main/cpp/org/thoriumlang/vm/op/Pop.cpp src/main/cpp/org/thoriumlang/vm/op/Pop.h)