#ifndef DEMO_SEQLIST_V0_2_H
#define DEMO_SEQLIST_V0_2_H

template <typename DadaType>
class SeqList {
private:
    DadaType* arr;
    int size, length;

public:
    SeqList(int len = 10) : size(0), length(len), arr(new DadaType[len]) {}

    bool insert(const int index, const DadaType data)
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

    bool insert(DadaType data)
    {
        arr[size++] = data;

        return true;
    }

    DadaType remove(const int index)
    {
        if (index < 0 || index >= length)
            return false;

        int num = index;
        DadaType data_index = arr[index];
        while (0 == num || num < size - 1) {
            arr[num] = arr[num + 1];
            num++;
        }

        size--;

        return data_index;
    }

    void traversal(std::function<void(DadaType)> visit)
    {
        for (SeqList::iterator iter = begin(); iter != end(); iter++)
            visit(*iter);
    }

    DadaType operator[] (const int index) const
    {
        return arr[index];
    }

    ~SeqList()
    {
    }

    class iterator {
    private:
        DadaType* cur;

    public:
        iterator(DadaType* _cur) : cur(_cur) {}

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

        DadaType operator* ()
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

#endif //DEMO_SEQLIST_V0_2_H

