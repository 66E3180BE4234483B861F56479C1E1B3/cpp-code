#ifndef DATASTRUCTURE__LINKEDLISTV1_0_H_
#define DATASTRUCTURE__LINKEDLISTV1_0_H_

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

    Node *head, *tail;
    int size = 0;

public:
    LinkedList()
    {
        head = new Node();
        head->next = nullptr;
        head->data = 0;
        tail = head;
    }

    void insert(T data)
    {
        size++;
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->data = data;
        tail->next = newNode;
        tail = newNode;
    }

    void insert(int index, T data)
    {
        if (index < 0 || index > size)
            exit(0);
        size++;

        Node* node = new Node();
        node->data = data;

        Node* pNew = head;
        for (int i = 0; i != index; i++)
            pNew = pNew->next;
        node->next = pNew->next;
        pNew->next = node;
    }

    T remove(int index)
    {
        if (index < 0 || index >= size)
            return false;
        size--;

        Node* pNew = head;
        for (int i = 0; i != index; i++)
            pNew = pNew->next;

        Node* p = pNew->next;
        T temp = p->data;
        pNew->next = p->next;
        delete p;

        return temp;
    }

    int removeAll(T data)
    {
        int count = 0;
        Node* node = head->next;
        for(int i = 0; node != nullptr; node = node->next)
            if (node->data == data) {
                remove(i);
                count++;
            } else
                i++;

        return count;
    }

    int contains(T data)
    {
        int count = 0;
        Node* node = head->next;
        for(int i = 0; node != nullptr; node = node->next)
            if (node->data == data)
                count++;

        return count;
    }

    T get(int index) const
    {
        if (index < 0 || index >= size)
            return false;

        Node* pNode = head->next;
        for (int i = 0; i != index; i++)
            pNode = pNode->next;

        return pNode->data;
    }

    bool set(int index, T data)
    {
        if (index < 0 || index >= size)
            return false;

        Node* pNode = head->next;
        for (int i = 0; i != index; i++)
            pNode = pNode->next;
        pNode->data = data;

        return true;
    }

    void traversal(std::function<void(T)> visit)
    {
        for(Node* node = head->next; node != nullptr; node = node->next)
            visit(node->data);
    }

    ~LinkedList()
    {
    }

    bool isEmpty()
    {
        return size == 0;
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
        return iterator(head->next);
    }

    iterator end()
    {
        return iterator(nullptr);
    }
};
#endif //DATASTRUCTURE__LINKEDLISTV1_0_H_
