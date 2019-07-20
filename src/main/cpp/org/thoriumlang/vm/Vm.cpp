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
#include "op/Op.h"
#include "op/Nop.h"
#include "op/Push.h"
#include "op/Add.h"
#include "op/Dump.h"
#include "op/Pop.h"

using namespace org::thoriumlang::vm;
using namespace org::thoriumlang::vm::op;

Vm::Vm(int stackSize, Program program) : data(stackSize), program(program) {
    for (Op *&op : ops) {
        op = Nop::get();
    }
    ops[OP_PUSH] = Push::get();
    ops[OP_ADD] = Add::get();
    ops[OP_DUMP] = Dump::get();
    ops[OP_POP] = Pop::get();
}

void Vm::run() {
    uint8_t op;
    while ((op = program.fetch()) != OP_HALT) {
        decode(op)->execute(&program, &data);
    }

    std::cout << "End" << std::endl;
}

op::Op *Vm::decode(uint8_t opCode) {
    return ops[opCode];
}
