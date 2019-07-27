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

#include <gtest/gtest.h>
#include <vector>
#include "../../../../../main/cpp/org/thoriumlang/vm/Code.h"

using namespace org::thoriumlang::vm::op;

TEST(CodeTest, appendOp) {
    Code code;
    code.append(OPCODE::HALT);
    code.append(OPCODE::PUSH);
    ASSERT_EQ(code.physicalSize(), 2);
}

TEST(CodeTest, appendInteger) {
    Code code;
    code.append(2019);
    ASSERT_EQ(code.physicalSize(), 8);
}

TEST(CodeTest, append) {
    Code code;
    code.append(std::vector<uint8_t>({1, 2, 3, 4, 5, 6, 7, 8}));
    ASSERT_EQ(code.physicalSize(), 8);
}

TEST(CodeTest, op) {
    Code code;
    code.append(OPCODE::HALT);
    code.append(OPCODE::PUSH);
    ASSERT_EQ(code.op(), OPCODE::HALT);
    ASSERT_EQ(code.op(), OPCODE::PUSH);
}

TEST(CodeTest, integer) {
    Code code;
    code.append(std::vector<uint8_t>({0, 0, 0, 0, 0, 0, 0x07, 0xE3 /*2019*/}));

    ASSERT_EQ(code.integer(), 2019);
}

TEST(CodeTest, append_integer) {
    Code code;
    code.append(2019);
    ASSERT_EQ(code.integer(), 2019);
}