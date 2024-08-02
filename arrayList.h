#ifndef ARRAY_LIST
#define AARAY_LIST

template <typename T>
class ArrayList
{

public:
    ArrayList() : _size(0), _capacity(64) { _arr = new T[_capacity]; };
    ~ArrayList() { delete[] _arr; };
    void push_front(const T &rVal);
    void push_back(const T &rVal);
    bool pop_front();
    bool pop_back();
    size_t size() { return _size; };

private:
    void resize();

private:
    T *_arr;
    size_t _size;
    size_t _capacity;
};

#include "ArrayList.cpp"

#endif