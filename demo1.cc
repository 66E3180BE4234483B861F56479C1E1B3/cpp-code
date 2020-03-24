#include "linkedStack.h"
#include "gtest//gtest.h"

TEST(Suite1, Test1)
{
    Stack<int> stack;
    const int N = 5;
    for (int i = 0; i < N; i++)
        stack.push(i + 1);

    int n = N;
    for (int i = 0; i < N; i++) {
        EXPECT_EQ(stack.top(), n);
        n--;
        stack.pop();
    }

    EXPECT_EQ(n, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
