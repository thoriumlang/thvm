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
#include "../../../../../main/cpp/org/thoriumlang/vm/Program.h"

using namespace org::thoriumlang::vm;

TEST(ProgramTest, fetchOpCodes) {
    static const uint8_t codes[] = {
            1,
            0
    };
    Program program((uint8_t *) codes);

    ASSERT_EQ(program.fetch(), (uint8_t) 1);
    ASSERT_EQ(program.fetch(), (uint8_t) 0);
}

TEST(ProgramTest, fetchInteger) {
    static const uint8_t codes[] = {
            0, 0, 0, 0, 0, 0, 0, 1,       // 1
            0, 0, 0, 0, 0, 0, 0x07, 0xE3, // 2019
    };
    Program program((uint8_t *) codes);

    ASSERT_EQ(program.nextInt(), (int64_t) 1);
    ASSERT_EQ(program.nextInt(), (int64_t) 2019);
}
