//#include "linkedList.h"
//#include <iostream>

/// @brief Destructor
/// @tparam T 
template <typename T>
LinkedList<T>::~LinkedList()
{
    while (_head != nullptr)
    {
        node *temp = _head;
        _head = _head->next;
        delete temp;
    }
}

/// @brief
/// @tparam T 
/// @return 
/// @throws std::out_of_range if the list is empty
template <typename T>
T LinkedList<T>::get_front() const
{
    check_empty_list();
    return _head->val;
}

/// @brief 
/// @tparam T 
/// @return 
/// @throws std::out_of_range if the list is empty
template <typename T>
T LinkedList<T>::get_back() const
{
    check_empty_list();
    return _tail->val;
}

/// @brief Gets the value in the list at position 'index'
/// @tparam T
/// @param index non-negative integer
/// @return The value at index
/// @throws std::out_of_range if the list is empty
template <typename T>
T LinkedList<T>::get_index(const size_t &index) //can't be const. TODO
{
    node* temp = get_node(index);
    return temp->val;
}

/// @brief Removes and retrieves the first item in the list.
/// @tparam T
/// @return The first value in the list.
/// @throws std::out_of_range if the list is empty
template <typename T>
T LinkedList<T>::pop_front()
{
    // retrieve the first item
    T value = get_front();

    // remove the item from the list
    node *temp = _head;
    _head = _head->next;
    delete temp;
    --_size;
    if(_size == 0) 
    {
        _tail = nullptr;
    }

    return value;
}

/// @brief Removes and retrieves the last item in the list
/// @tparam T
/// @return The last value in the list
/// @throws std::out_of_range if the list is empty
template <typename T>
T LinkedList<T>::pop_back()
{
    // retrieve the last item
    T value = get_back();

    // retrieve the second to last item
    node* temp = get_node(_size-2);

    // remove the tail and set the pointers
    _tail = temp;
    delete _tail->next;
    _tail->next = nullptr;
    --_size;

    return value;
}

/// @brief
/// @tparam T
/// @param index
/// @return
template <typename T>
T LinkedList<T>::pop_index(const size_t &index)
{
    if (index == 0)
    {
        return pop_front();
    }
    else if (index == (_size-1))
    {
        return pop_back();
    }
    else
    {
        // find the target node and the one to the left
        node* leftNode = get_node(index-1);
        node* targetNode = leftNode->next;
        T value = targetNode->val;

        // set the pointers and delete the node
        leftNode->next = targetNode->next;
        delete targetNode;
        --_size;
        return value;
    }
}

/// @brief
/// @tparam T
/// @param rVal
/// @return
template <typename T>
bool LinkedList<T>::push_front(const T &rVal)
{
    // create the new node
    node* newNode = new(std::nothrow) node(rVal);
    if (newNode == nullptr) 
    {
        return false; // Memory allocation failed
    }

    // update the head
    node* temp = _head;
    _head = newNode;
    _head->next = temp;
    ++_size;
    
    // update the tail if neccessary
    if(_size == 1) 
    {
        _tail = _head;
    }
    return true;
}

template <typename T>
bool LinkedList<T>::push_back(const T &rVal)
{
    // create the new node
    node* newNode = new(std::nothrow) node(rVal);
    if (newNode == nullptr) 
    {
        return false; // Memory allocation failed
    }

    // handle empty list
    if (_size == 0)
    {
        _head = _tail = newNode;
    }
    else
    {
        _tail->next = newNode;
        _tail = newNode;
    }
    ++_size;
    return true;
}

template <typename T>
bool LinkedList<T>::push_index(const T &rVal, const size_t &index)
{
    if (index == 0)
    {
        return push_front(rVal);
    }
    else if (index == _size)
    {
        return push_back(rVal);
    }
    else
    {
        // create the new node
        node* newNode = new(std::nothrow) node(rVal);
        if (newNode == nullptr) 
        {
            return false; // Memory allocation failed
        }

        // find the node to the left of the insertion
        node *temp = get_node(index-1);

        // update pointers
        newNode->next = temp->next;
        temp->next = newNode;
        ++_size;

        return true;
    }
}

/// @brief Implemented to guard against empty list in pop/get functions
template <typename T>
void LinkedList<T>::check_empty_list() const
{
    if(_head == nullptr) 
    {
        throw std::out_of_range("List is empty");
    }
}

/// @brief Find the node in the list and returns the pointer. Also protects 
/// against out of bound index parameter. Might cause push functions to stop
/// prematurely if implemented incorrectly
/// @tparam T 
/// @param index integer is expected to be within bounds 
/// @return 
/// @throws std::out_of_range if the list is empty 
template <typename T>
typename LinkedList<T>::node* LinkedList<T>::get_node(const size_t &index)
{
    check_empty_list();
    node *temp = _head;

    // traverse list
    for (size_t x = 0; temp != nullptr; ++x)
    {
        if(x == index) 
        {
            return temp;
        }
        temp = temp->next;
    }

    // if index is not found then it is out of range
    throw std::out_of_range("Index out of range");
}