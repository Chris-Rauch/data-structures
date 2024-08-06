#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

template <typename T>
class ArrayList
{
public:
    ArrayList() : _size(0), _capacity(64) { _arr = new T[_capacity]; };
    ~ArrayList() { delete[] _arr; };
    void push_front(const T &rVal);
    void push_back(const T &rVal);
    T pop_front();
    T pop_back();
    size_t size() { return _size; };

private:
    void resize();

private:
    T* _arr;
    size_t _size;
    size_t _capacity;
};

#endif // ARRAY_LIST_H

/// @brief 
/// @tparam T 
/// @param rVal 
template<typename T>
void ArrayList<T>::push_front(const T &rVal) {
    // resize if necessary
    if(_size == _capacity) {
        resize();
    }

    // shift all elements to the right. O(n)
    for(size_t x = size; x > 0; --x) {
        _arr[x] = _arr[x-1];
    }
    _arr[0] = rVal;
    ++_size;
}

/// @brief 
/// @tparam T 
/// @param rVal 
template <typename T>
void ArrayList<T>::push_back(const T &rVal)
{
    // resize if necessary
    if(_size == _capacity) {
        resize();
    }
    _arr[_size] = rVal;
    ++_size;
}

/// @brief 
/// @tparam T 
/// @return 
template <typename T>
T ArrayList<T>::pop_front()
{
    T value = _arr[0];

    //shift all elements to the left
    for(size_t x = 0; x < _size; ++x)
    {
        _arr[x] = _arr[x+1];
    }
    --_size;
}

template <typename T>
T ArrayList<T>::pop_back()
{
    --_size;
    return _arr[_size];
}

/// @brief 
/// @tparam T 
template <typename T>
void ArrayList<T>::resize() 
{
    _capacity = _capacity * 2;
    T* temp = new T[_capacity];

    for(size_t x = 0; x < _size; ++x)
    {
        temp[x] = _arr[x];
    }

    delete[] _arr;
    _arr = temp;
}