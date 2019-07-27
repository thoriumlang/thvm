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

#ifndef THVM_OP_H
#define THVM_OP_H

#include "../Stack.h"
#include "../Code.h"

namespace org::thoriumlang::vm::op {
    class Op {
    public:
        virtual ~Op() = default;

        virtual void execute(Code &code, Stack *stack) = 0;

        void operator()(Code &code, Stack *stack);
    };
}

#endif //THVM_OP_H
