#ifndef HASH_MAP
#define HASH_MAP

template<typename KeyType, class ValueType> 
class HashMap 
{
public:
    bool insert(const KeyType& key, const ValueType& val);
    bool remove(const KeyType& key);

private:
    size_t hashFunction(const KeyType &key) const;

private:
    ArrayList<LinkedList<pair<KeyType, ValueType>>> _hashMap;
};

#include <iostream>
#include <functional>
#include "hashMap.cpp"
#include "arrayList.h"
#include "linkedList.h"
#include "pair.h"

#endif

/// @brief 
/// @tparam KeyType 
/// @tparam ValueType 
/// @param key 
/// @param val 
/// @return 
template <typename KeyType, typename ValueType>
bool HashMap<KeyType,ValueType>::insert(const KeyType &key, const ValueType &val)
{
    // get the index for the new key/val pair
    std::size_t hashKey = hashFunction(key);
    std::size_t index = hashKey % _hashMap.size();

    // create the new pair object
    pair<KeyType, ValueType> p(key, val);

    // check to see if key already exists
    for(std::size_t x = 0; x < _hashMap[index].size(); ++x) 
    {
        if(_hashMap[index][x].first == key)
        {
            return false;
        }
    }

    // at this index, add the key/value pair to the map
    _hashMap[index].push_back(p);
    return true;
}

/// @brief 
/// @tparam KeyType 
/// @tparam ValueType 
/// @param key 
/// @return 
template <typename KeyType, typename ValueType>
bool HashMap<KeyType,ValueType>::remove(const KeyType &key)
{

}

/// @brief 
/// @tparam KeyType
/// @param key 
/// @return 
template <typename KeyType, typename ValueType>
size_t HashMap<KeyType,ValueType>::hashFunction(const KeyType &key) const
{
    return std::hash<KeyType>(key);  
}