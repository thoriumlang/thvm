cmake_minimum_required(VERSION 3.14)
project(thvm)

set(CMAKE_CXX_STANDARD 17)

add_executable(thvm src/main/cpp/main.cpp src/main/cpp/org/thoriumlang/vm/Vm.cpp src/main/cpp/org/thoriumlang/vm/Vm.h src/main/cpp/org/thoriumlang/vm/Stack.cpp src/main/cpp/org/thoriumlang/vm/Stack.h)