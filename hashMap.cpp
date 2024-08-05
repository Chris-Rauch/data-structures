#include "hashMap.h"

/// @brief 
/// @tparam KeyType 
/// @tparam ValueType 
/// @param key 
/// @param val 
/// @return 
template <typename KeyType, typename ValueType>
bool HashMap<KeyType,ValueType>::insert(const KeyType &key, const ValueType &val)
{
    //compute the key's hash code (size_t)

    //map the hash code to an index

    //at this index, add the key/value pair to the map
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
/// @tparam ValueType 
/// @param key 
/// @return 
template <typename KeyType, typename ValueType>
size_t HashMap<KeyType,ValueType>::hashFunction(const KeyType &key) const
{

}