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

#include "Add.h"

using namespace org::thoriumlang::vm::op;

Add Add::instance;

void Add::execute(Program *, Stack *stack) {
    const OBJECT &o2 = stack->pop();
    const OBJECT &o1 = stack->pop();

    stack->push(object(std::get<int64_t>(o1) + std::get<int64_t>(o2)));
}
