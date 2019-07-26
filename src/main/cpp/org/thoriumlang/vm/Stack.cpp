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

#include <cstdlib>
#include <iostream>
#include "Stack.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"

using namespace org::thoriumlang::vm;

OBJECT org::thoriumlang::vm::object(int64_t value) {
    return OBJECT(value);
}

void Stack::push(OBJECT object) {
    if (sp + 1 == size) {
        throw StackOverflow();
    }
    stack[++sp] = object;
}

OBJECT Stack::pop() {
    if (sp < 0) {
        throw StackUnderflow();
    }
    return stack[sp--];
}

OBJECT Stack::peek() {
    if (sp < 0) {
        throw StackUnderflow();
    }
    return stack[sp];
}

Stack::Stack(int size) :
        size(size),
        stack(size),
        sp(-1) {
    std::cout << "Stack size is "
              << size
              << "."
              << std::endl;
}