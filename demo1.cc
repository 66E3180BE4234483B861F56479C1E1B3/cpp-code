#include "seqStack.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1)
{
    const int N = 7;
    Stack<int> stack;

    for (int i = 0; i < N; i++)
        stack.push(i + 1);
    
    int n = N;
    for (int i = 0; i < N; i++) {
        EXPECT_EQ(stack.top(), n);
        stack.pop();
        n--;
    }

    EXPECT_EQ(n, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
