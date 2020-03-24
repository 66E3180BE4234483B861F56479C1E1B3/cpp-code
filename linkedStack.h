#ifndef DEMO_LINKEDSTACK_H
#define DEMO_LINKEDSTACK_H

#include "linkedListv1.0.h"

template <typename T>
class Stack : public LinkedList<T> {
private:
    int stackTop;
    LinkedList<T> list;

public:
    Stack() : stackTop(-1) {}

    void push(T data)
    {
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
        return list.get(stackTop);
    }

    int size() const
    {
        return stackTop + 1;
    }
};

#endif //DEMO_LINKEDSTACK_H
