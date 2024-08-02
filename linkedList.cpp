/// @brief
/// @tparam T
/// @param item is set to the value at index
/// @param index must be between 0 < index < _size
/// @return True if successful. False if index is out of scope
template <typename T>
bool LinkedList<T>::get_index(T &item, const size_t &index) const
{
    node *temp = _head;
    if (index >= _size || index < 0)
    {
        return false;
    }
    for (size_t x = 0; x != index; ++x)
    {
        temp = temp->next;
    }
    item = temp->val;
    return true;
}

/// @brief Removes the first item in the list
/// @tparam T
/// @return True if successful.
template <typename T>
bool LinkedList<T>::pop_front()
{
    if (_size == 0)
    {
        return false;
    }
    else if (_size == 1)
    {
        delete _head;
        _head = _tail = nullptr;
    }
    else
    {
        node *deleteItem = _head;
        _head = _head->next;
        delete deleteItem;
    }
    --_size;
    return true;
}

/// @brief Removes the last item in the list
/// @tparam T
/// @return True if successful
template <typename T>
bool LinkedList<T>::pop_back()
{
    if (_size == 0)
    {
        return false;
    }
    else if (_size == 1)
    {
        delete _tail;
        _head = _tail = nullptr;
    }
    else
    {
        node *temp = _head;

        // find the second to last item
        for (size_t x = 0; x < (_size - 2); ++x)
        {
            temp = temp->next;
        }
        delete _tail;
        _tail = temp;
        temp->next = nullptr;
    }
    --_size;
    return true;
}

/// @brief
/// @tparam T
/// @param index
/// @return
template <typename T>
bool LinkedList<T>::pop_index(const size_t &index)
{
    node *temp1 = _head;
    node *temp2;
    if (_size == 0 || index >= _size)
    {
        return false;
    }
    else if (index == 0)
    {
        pop_front();
        return true;
    }
    else if (index == _size)
    {
        pop_back();
        return true;
    }
    else
    {
        // find the elem one before the desired elem
        for (size_t x = 1; x != index; ++x, temp1 = temp1->next)
            ;
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        --_size;
        return true;
    }
}

/// @brief
/// @tparam T
/// @param rVal
/// @return
template <typename T>
bool LinkedList<T>::push_front(const T &rVal)
{
    node *newNode = new node(rVal);
    if (_size == 0)
    {
        _head = _tail = newNode;
    }
    else
    {
        newNode->next = _head;
        _head = newNode;
    }
    ++_size;
    return true;
}

template <typename T>
bool LinkedList<T>::push_back(const T &rVal)
{
    node *newNode = new node(rVal);
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
    if (index >= _size)
    {
        return false;
    }
    else if (index == 0)
    {
        return push_front(rVal);
    }
    else if (index == _size)
    {
        return push_back(rVal);
    }
    else
    {
        node *newNode = new node(rVal);
        node *temp1 = _head;
        for (size_t x = 1; x != index; ++x)
        {
            temp1 = temp1->next;
        }
        node *temp2 = temp1->next;
        temp1->next = newNode;
        newNode->next = temp2;
        ++_size;
        return true;
    }
}

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