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

#ifndef THVM_CODE_H
#define THVM_CODE_H

#include <vector>
#include "opcodes.h"

using namespace org::thoriumlang::vm;

class Code {
    int ip = -1;
    std::vector<uint8_t> code;

public:
    unsigned long physicalSize();

    void append(op::OPCODE op);

    void append(int64_t value);

    void append(const std::vector<uint8_t> &elements);

    uint8_t op();

    int64_t integer();
};

#endif //THVM_CODE_H