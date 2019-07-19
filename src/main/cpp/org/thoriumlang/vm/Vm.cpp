/*
 * Copyright 2019 Christophe Pollet
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include "Vm.h"

#define OP_HALT 0
using namespace org::thoriumlang::vm;

Vm::Vm(int stackSize, Program program) : data(stackSize), program(program) {}

void op_nop(Program *program, Stack *stack) {
    // nothing
}

void op_push(Program *program, Stack *stack) {
    OBJECT o;
    o.type = 'I';
    o.u8 = program->next();

    stack->push(o);
}

void op_add(Program *program, Stack *stack) {
    const OBJECT &o1 = stack->pop();
    const OBJECT &o2 = stack->pop();

    OBJECT o;
    o.type = 'I';
    o.u8 = o1.u8 + o2.u8;

    stack->push(o);
}

void op_dump(Program *program, Stack *stack) {
    const OBJECT &o = stack->pop();

    std::cout << "Head of stack: "
              << (int) o.u8
              << " ("
              << o.type
              << ")"
              << std::endl;
}

void Vm::run() {
    typedef void (*instruction)(Program *program, Stack *stack);

    instruction ops[256];
    for (int i = 0; i < 256; i++) {
        ops[i] = op_nop;
    }
    ops[1] = op_push;
    ops[2] = op_add;
    ops[3] = op_dump;

    uint8_t op;
    while ((op = program.next()) != OP_HALT) {
        ops[op](&program, &data);
    }

    std::cout << "End" << std::endl;
}
