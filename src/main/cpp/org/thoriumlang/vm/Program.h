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

#ifndef THVM_PROGRAM_H
#define THVM_PROGRAM_H


#include <cstdint>

namespace org::thoriumlang::vm {
    class Program {
        uint8_t *code;
        uint8_t *ip; // instruction pointer
    public:
        Program(uint8_t *code);

        uint8_t next();

        int nextInt();
    };
}

#endif //THVM_PROGRAM_H