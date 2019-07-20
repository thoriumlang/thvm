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

#ifndef THVM_STACK_H
#define THVM_STACK_H

#include <cstdint>

namespace org::thoriumlang::vm {
    typedef struct OBJECT_t {
        uint8_t type;
        union {
            int64_t i64 ;
        };
    } OBJECT;

    class Stack {
        int size;
        OBJECT *stack;
        int sp; // stack pointer
    public:
        Stack(int size);

        virtual ~Stack();

        void push(OBJECT object);

        OBJECT pop();

        OBJECT peek();
    };
}

#endif //THVM_STACK_H
