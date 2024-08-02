#include "ArrayList.h"

template<typename T>
void ArrayList::push_front(const T &rVal) {
    if(_size == _capacity) {
        resize();
    }

    T tempArr[++_size];
    _arr[0] = rVal;
    for(size_t x = 1; x < _size; ++x) {

    }
}