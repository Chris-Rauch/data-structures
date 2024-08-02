#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

template <typename T>
class LinkedList
{
    struct node
    {
        node(T rVal) : val(rVal), next(nullptr){};
        node *next;
        T val;
    };

public:
    LinkedList() : _head(nullptr), _tail(nullptr), _size(0){};
    ~LinkedList();
    bool get_index(T &item, const size_t &index) const;
    bool pop_front();
    bool pop_back();
    bool pop_index(const size_t &index);
    bool push_front(const T &rVal);
    bool push_back(const T &rVal);
    bool push_index(const T &rVal, const size_t &index);
    size_t getSize() const { return _size; }

private:
    node *_head;
    node *_tail;
    size_t _size;
};

#include "linkedList.cpp"

#endif