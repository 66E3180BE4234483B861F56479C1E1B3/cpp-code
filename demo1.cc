#include "linkedListv1.0.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1)
{
    const int N = 7;
    LinkedList<int> list;

    for (int i = 0; i < N; i++)
        list.insert(i + 1);

    int n = 0;
    for (int d : list) {
        n++;
        EXPECT_EQ(d, n);
    }

    EXPECT_EQ(n, N);

    for (int i = 0; i < 5; i++)
        list.insert(i + 2, 3);

    EXPECT_EQ(list.removeAll(3), list.contains(3));
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
