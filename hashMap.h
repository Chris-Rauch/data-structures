#ifndef HASH_MAP
#define HASH_MAP

#include <iostream>

template<class KeyType, class ValueType> 
class HashMap {

public:
    bool insert(const KeyType& key, const ValueType& val);
    bool remove(const KeyType& key);

private:
    size_t hashFunction(char* key);


private:
    vector<List<Pair<KeyType, ValueType>>> _hashMap;

};

#include "hashMap.cpp"


#endif