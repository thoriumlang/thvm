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

#include <gtest/gtest.h>
#include "../../../../../main/cpp/org/thoriumlang/vm/Stack.h"
#include "../../../../../main/cpp/org/thoriumlang/vm/StackOverflow.h"
#include "../../../../../main/cpp/org/thoriumlang/vm/StackUnderflow.h"

using namespace org::thoriumlang::vm;

TEST(StackTest, pushAndPop) {
    Stack stack(1);
    stack.push(object(1));

    ASSERT_EQ(stack.pop().i64, 1);
}

TEST(StackTest, popPastStackThrowsException) {
    Stack stack(0);

    ASSERT_THROW(stack.pop(), StackUnderflow);
}

TEST(StackTest, pushPastStackThrowsException) {
    Stack stack(0);

    ASSERT_THROW(stack.push(object(1)), StackOverflow);
}

TEST(StackTest, pushAndPopReverseTheOrder) {
    Stack stack(2);
    stack.push(object(1));
    stack.push(object(2));

    ASSERT_EQ(stack.pop().i64, 2);
    ASSERT_EQ(stack.pop().i64, 1);
}

TEST(StackTest, peek) {
    Stack stack(1);
    stack.push(object(1));

    ASSERT_EQ(stack.peek().i64, 1);
    ASSERT_EQ(stack.peek().i64, 1);
}