#ifndef DATASTRUCTURE__LINKEDLISTV0_1_H_
#define DATASTRUCTURE__LINKEDLISTV0_1_H_

#include <iostream>
#include <functional>

template <typename T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node* next;
    };

    Node* first = nullptr;

public:
    LinkedList() {}

    void insert(T data)
    {
        Node* newNode = new Node();
        newNode->next = first;
        newNode->data = data;
        first = newNode;
    }

    void traversal(std::function<void(T)> visit)
    {
        for (iterator iter = first; iter != nullptr; iter++)
            visit(*iter);
    }

    ~LinkedList()
    {

    }

    class iterator {
    private:
        Node* node;

    public:
        iterator(Node* _node) : node(_node) {}
        iterator&operator++()
        {
            node = node->next;
            return *this;
        }

        iterator operator ++(int)
        {
            iterator reVal = node;
            ++(*this);
            return reVal;
        }

        bool operator ==(iterator iter)
        {
            return node == iter.node;
        }

        bool operator !=(iterator iter)
        {
            return !(node == iter.node);
        }

        T operator* () const
        {
            return node->data;
        }
    };

    iterator begin()
    {
        return iterator(first);
    }

    iterator end()
    {
        return iterator(nullptr);
    }
};
#endif //DATASTRUCTURE__LINKEDLISTV0_1_H_
