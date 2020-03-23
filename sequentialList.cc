#include "sequentialList.h"

int main()
{
    SeqList l(10);
    for (int i = 0; i < 10; i++)
        l.insert(i + 1);

    l.traversal();

    for (int i = 0; i < 10; i++)
        l.remove(i);

    l.traversal();

    return 0;
}
