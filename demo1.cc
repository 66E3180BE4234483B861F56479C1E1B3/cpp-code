#include <iostream>

#include "gtest/gtest.h"
#include "seqList-v0.2.h"

TEST(Suite1, Test1) {
    SeqList<int> seqList(3);
    const int N = 3;

    for (int i = 0; i < N; i++) {
        seqList.insert(i + 1);
    }

    int n = 1;
    for (int d : seqList) {
        EXPECT_EQ(d, n);
        n++;
    }
    EXPECT_EQ(n, N + 1);
}

template <typename T>
void func(T n)
{
    std::cout << n << " ";
}

int main(int argc, char **argv) {
    SeqList<char> l(10);
    for (int i = 0; i < 10; i++)
        l.insert(i + 'a');
    l.traversal([] (char d) {std::cout << d << " ";});
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        std::cout << l.remove(0) << " ";

    l.traversal(func<char>);
    std::cout << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

