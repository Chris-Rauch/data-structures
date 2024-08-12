#ifndef PAIR_H
#define PAIR_H

namespace MyDataStructure {

template <typename T1, typename T2>
struct pair {
    Pair();
    Pair(const T1 &first, const T2 &second) : first(first), second(second) {}

    T1 first;
    T2 second;

}

bool pair::operator==(const pair& rVal) const {
    return first == rVal.first && second == rVal.second;
}

}

#endif // PAIR_H