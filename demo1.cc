#include <iostream>

#include "seqListv1.0.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1)
{
    const int N = 7;
    SeqList<int> list(N);

    for (int i = 0; i < N; i++)
        list.insert(i, i + 1);

    EXPECT_EQ(list.isEmpty(), false);

    int n = 0;
    for (int data : list) {
        n++;
        EXPECT_EQ(data, n);
    }

    EXPECT_EQ(n, N);
}

template <typename T>
void func(T n)
{
    std::cout << n << " ";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
