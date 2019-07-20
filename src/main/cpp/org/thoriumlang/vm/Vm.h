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

#ifndef THVM_VM_H
#define THVM_VM_H

#include "Stack.h"
#include "Program.h"
#include "op/Op.h"

#define OP_HALT 0
#define NOP 0
#define OP_PUSH 1
#define OP_ADD 2
#define OP_DUMP 3

namespace org::thoriumlang::vm {
    class Vm {
        Program program;
        Stack data;
        op::Op *ops[256]{};

    public:
        Vm(int dataStackSize, Program program);

        void run();
    };
}

#endif //THVM_VM_H