#ifndef DEMO_SEQLISTV1_0_H
#define DEMO_SEQLISTV1_0_H

#include <iostream>
#include <functional>

template <typename DataType>
class SeqList {
private:
    DataType* arr;
    int size, capacity;

public:
    SeqList(int len = 10) : size(0), capacity(len), arr(new DataType[len]) {}

    void insert(const int index, const DataType data)
    {
        if (index < 0 || index >= capacity || size >= capacity)
            exit(1);

        size++;

        for (int i = size; i != index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = data;
    }

    bool insert(DataType data)
    {
        if (size >= capacity)
            return false;

        arr[size++] = data;

        return true;
    }

    DataType remove(const int index)
    {
        if (index < 0 || index >= capacity || size == 0)
            return false;

        int num = index;
        DataType data_index = arr[index];
        while (0 == num || num < size - 1) {
            arr[num] = arr[num + 1];
            num++;
        }

        size--;

        return data_index;
    }

    void traversal(std::function<void(DataType)> visit)
    {
        for (SeqList::iterator iter = begin(); iter != end(); iter++)
            visit(*iter);
    }

    DataType operator[] (const int index) const
    {
        return arr[index];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    DataType get(int index) const
    {
        if (index < 0 || index >= capacity)
            return false;

        return arr[index];
    }

    bool set(int index, DataType data)
    {
        if (index < 0 || index >= capacity)
            return false;

        arr[index] = data;

        return true;
    }

    int removeAll(DataType data)
    {
        int count = 0;
        for (int i = size - 1; i != -1; i--)
            if (arr[i] == data) {
                count++;
                remove(i);
            }

        return count;
    }

    int contains(DataType dada)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
            if (arr[i] == dada)
                count++;

        return count;
    }

    ~SeqList()
    {
    }

    class iterator {
    private:
        DataType* cur;

    public:
        iterator(DataType* _cur) : cur(_cur) {}

        iterator&operator++ ()
        {
            cur++;
            return *this;
        }

        iterator&operator-- ()
        {
            cur--;
            return *this;
        }

        iterator operator++ (int)
        {
            iterator reVal = cur;
            ++(*this);
            return reVal;
        }

        iterator operator-- (int)
        {
            iterator reVal = cur;
            --(*this);
            return reVal;
        }

        bool operator == (const iterator& iterator1)
        {
            return cur == iterator1.cur;
        }

        bool operator != (const iterator& iterator1)
        {
            return !(cur == iterator1.cur);
        }

        DataType operator* ()
        {
            return *cur;
        }
    };

    iterator begin()
    {
        return iterator(arr);
    }

    iterator end()
    {
        return iterator(arr + size);
    }
};

#endif //DEMO_SEQLISTV1_0_H
