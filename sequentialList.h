#ifndef DATASTRUCTURE_ISSUE1_SEQUENTIALLIST_H_
#define DATASTRUCTURE_ISSUE1_SEQUENTIALLIST_H_

#include <iostream>

class SeqList {
private:
    int* arr;
    int size, length;

public:
    SeqList(int len = 10)
    {
        size = 0;
        length = len;
        arr = new int[length];
    }

    bool insert(const int index, const int data)
    {
        size++;

        if (index < 0 || index >= length)
            return false;

        int num = index;
        while (num < size) {
            arr[size + 1 - num] = arr[size - num];
            num++;
        }

        arr[index] = data;

        return true;
    }

    bool insert(int data)
    {
        arr[size++] = data;

        return true;
    }

    int remove(const int index)
    {
        if (index < 0 || index >= length)
            return false;

        int num = index;
        int data_index = arr[index];
        while (0 == num || num < size - 1) {
            arr[num] = arr[num + 1];
            num++;
        }

        size--;

        return data_index;
    }

    void traversal()
    {
        for (int i = 0; i < size; i++)
            std::cout << arr[i] << " ";

        std::cout << std::endl;
    }

    ~SeqList()
    {
    }
};
#endif //DATASTRUCTURE_ISSUE1_SEQUENTIALLIST_H_
