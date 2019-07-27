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

using namespace org::thoriumlang::vm;

int main() {
    Code code;
    code.append(op::OPCODE::PUSH);
    code.append(2019);
    code.append(op::OPCODE::PUSH);
    code.append(1);
    code.append(op::OPCODE::ADD);
    code.append(op::OPCODE::DUMP);
    code.append(op::OPCODE::POP);
    code.append(op::OPCODE::HALT);

    Vm(
            1024,
            code
    ).run();
    return 0;
}