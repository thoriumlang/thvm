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

void Stack::push(OBJECT object) {
    if (sp >= size) {
        throw StackOverflow();
    }
    stack[sp++] = object;
}

OBJECT Stack::pop() {
    if (sp <= 0) {
        throw StackUnderflow();
    }
    return stack[--sp];
}

OBJECT Stack::peek() {
    return stack[sp - 1];
}

Stack::Stack(int size) :
        size(size),
        sp(0),
        stack((OBJECT *) malloc(sizeof(OBJECT) * size)) {
    std::cout << "Stack size is "
              << size
              << ". Memory usage is "
              << sizeof(OBJECT) * size
              << " bytes."
              << std::endl;
}

Stack::~Stack() {
    free(stack);
}
