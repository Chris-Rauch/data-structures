// for testing dataStruct.h
#include <iostream>
#include "linkedList.h"

using namespace std;

void testLinkedList();

int main()
{
    testLinkedList();

    return 0;
}

void testLinkedList()
{
    LinkedList<int> list;

    list.push_front(2);
    list.push_front(1);
    list.push_back(4);
    list.push_back(5);
    list.push_index(3, 2);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);

    list.pop_front();
    list.pop_back();
    list.pop_index(0);
    list.pop_index(4);

    for (int x = 0; x < list.getSize(); ++x)
    {
        int value;
        list.get_index(value, x);
        cout << value << endl;
    }
}