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

#include "Program.h"

using namespace org::thoriumlang::vm;

Program::Program(uint8_t *code) :
        code(code), ip(code) {
    // nothing
}

uint8_t Program::next() {
    uint8_t op = *ip;
    ip++;
    return op;
}

int Program::nextInt() {
    int64_t int64 = 0;

    for (int i = 0; i < 8; i++) {
        int64 = int64 << 8;
        int64 += (int64_t) next();
    }

    return int64;
}