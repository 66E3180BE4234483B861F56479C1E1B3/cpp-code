#ifndef DEMO_SEQSTACK_H
#define DEMO_SEQSTACK_H

#include "seqListv1.0.h"

template <typename T>
class Stack : public SeqList<T> {
private:
    int stackTop, stackSize;
    SeqList<T> list;

public:
    Stack(int size = 10) : stackTop(-1), stackSize(size), list(stackSize) {}

    void push(T data)
    {
        if (stackTop >= stackSize)
            exit(0);

        list.insert(++stackTop, data);
    }

    void pop()
    {
        if (stackTop == -1)
            exit(0);

        list.remove(stackTop--);
    }

    T top() const
    {
        if (stackTop == -1)
            return false;

        return list.get(stackTop);
    }

    int size() const
    {
        return stackTop + 1;
    }
};

#endif //DEMO_SEQSTACK_H
