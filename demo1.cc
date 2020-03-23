#include "linkedListv0.1.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1)
{
    const int N = 7;
    LinkedList<int> list;

    for (int i = 0; i < N; i++)
        list.insert( i + 1);

    int n = N;
    for (int d : list) {
        EXPECT_EQ(d, n);
        n--;
    }

    EXPECT_EQ(n, 0);
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
