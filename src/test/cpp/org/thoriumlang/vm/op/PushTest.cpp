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
#include "../../../../../../main/cpp/org/thoriumlang/vm/Stack.h"
#include "../../../../../../main/cpp/org/thoriumlang/vm/op/Push.h"

using namespace org::thoriumlang::vm;

TEST(Push, push) {
    Stack stack(1);

    Code code;
    code.append(std::vector<uint8_t>({0, 0, 0, 0, 0, 0, 0x07, 0xE3 /*2019*/}));

    op::Push::get()->execute(code, &stack);

    ASSERT_EQ(std::get<int64_t>(stack.pop()), 2019);
}