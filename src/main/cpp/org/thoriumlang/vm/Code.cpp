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

#include "Code.h"
#include "opcodes.h"

unsigned long Code::physicalSize() {
    return code.size();
}

void Code::append(op::OPCODE op) {
    code.push_back(op);
}

void Code::append(int64_t value) {
    for (int i = 1; i <= 8; i++) {
        append((op::OPCODE) (value >> ((8 - i) * 8)));
    }
}

void Code::append(const std::vector<uint8_t> &elements) {
    code.insert(code.end(), elements.begin(), elements.end());
}

uint8_t Code::op() {
    ip++;
    return code[ip];
}

int64_t Code::integer() {
    int value = 0;

    for (int i = 0; i < 8; i++) {
        value = value << 8 | op();
    }

    return value;
}


