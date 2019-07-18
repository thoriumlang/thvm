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

uint8_t *op_nop(uint8_t *ip, Stack *stack) {
    return ip + 1;
}

uint8_t *op_push(uint8_t *ip, Stack *stack) {
    OBJECT o;
    o.type = 'I';
    o.u8 = *(ip + 1);
    stack->push(o);

    return ip + 2;
}

uint8_t *op_add(uint8_t *ip, Stack *stack) {
    const OBJECT &o1 = stack->pop();
    const OBJECT &o2 = stack->pop();

    OBJECT o;
    o.type = 'I';
    o.u8 = o1.u8 + o2.u8;

    stack->push(o);

    return ip + 1;
}

uint8_t *op_dump(uint8_t *ip, Stack *stack) {
    const OBJECT &o = stack->pop();

    std::cout << "Head of stack: "
              << (int) o.u8
              << " ("
              << o.type
              << ")"
              << std::endl;

    return ip + 1;
}

void Vm::run() {
    typedef uint8_t *(*instruction)(uint8_t *ip, Stack *stack);

    instruction ops[256];
    for (int i = 0; i < 256; i++) {
        ops[i] = op_nop;
    }
    ops[1] = op_push;
    ops[2] = op_add;
    ops[3] = op_dump;

    while (*ip != OP_HALT) {
        this->ip = ops[*ip](ip, &this->data);
    }

    std::cout << "End" << std::endl;
}

Vm::Vm(int stackSize, uint8_t *code) : data(stackSize), code(code), ip(code) {}
