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
    ArrayList<LinkedList<Pair<KeyType, ValueType>>> _hashMap;
};

#include <iostream>
#include "hashMap.cpp"
#include "arrayList.h"
#include "linkedList.h"

#endif