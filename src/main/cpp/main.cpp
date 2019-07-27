/**
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
#include "org/thoriumlang/vm/op/Op.h"

using namespace org::thoriumlang::vm;

int main() {
    static const uint8_t program[] = {
            op::OP::PUSH,
            0, 0, 0, 0, 0, 0, 0x07, 0xE3, // 2019
            op::OP::PUSH,
            0, 0, 0, 0, 0, 0, 0, 1,       // 1
            op::OP::ADD,
            op::OP::DUMP,
            op::OP::POP,
            op::OP::HALT
    };

    Vm(
            1024,
            Program((uint8_t *) &program[0])
    ).run();
    return 0;
}

