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
    T get_front() const;
    T get_back() const;
    T get_index(const size_t &index) const;
    T pop_front();
    T pop_back();
    T pop_index(const size_t &index);
    bool push_front(const T &rVal);
    bool push_back(const T &rVal);
    bool push_index(const T &rVal, const size_t &index);
    size_t getSize() const { return _size; }

private:
    void check_empty_list() const;
    node* get_node(const size_t &index);

private:
    node *_head;
    node *_tail;
    size_t _size;
};

#include "linkedList.cpp"

#endif