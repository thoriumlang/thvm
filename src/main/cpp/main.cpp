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
#include "org/thoriumlang/vm/Vm.h"

using namespace org::thoriumlang::vm;

int main(int argc, char *argv[]) {
    static const uint8_t program[] = {
            OP_PUSH,
            0, 0, 0, 0, 0, 0, 0x07, 0xE3, // 2019
            OP_PUSH,
            0, 0, 0, 0, 0, 0, 0, 1,       // 1
            OP_ADD,
            OP_DUMP,
            OP_POP,
            OP_HALT
    };

    Vm(
            1024,
            Program((uint8_t *) &program[0])
    ).run();
    return 0;
}

