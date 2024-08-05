// for testing dataStruct.h
#include <iostream>
#include <cstdlib>
#include <chrono>
#include "linkedList.h"

using namespace std;
using namespace std::chrono;

void testLinkedList();
void test();

int NUM_LOOPS = 1000000000;

int main()
{
    testLinkedList();
    //test();

    return 0;
}

void test() {
/*
    myClass obj;
    std::cout << "The value is " << obj.getSomeVal() << std::endl;
*/
}

void testLinkedList()
{
    LinkedList<int> list;
    list.push_front(0);

    auto start = high_resolution_clock::now();
    for(size_t x = 0; x < NUM_LOOPS; ++x) {
        list.push_index(rand(),rand()%list.getSize());
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;


/*
    for(size_t x = 0; x < (NUM_LOOPS/4); ++x) {
        list.pop_index(rand()%list.getSize());
    }
    */

/*
    for (int x = 0; x < list.getSize(); ++x)
    {
        int value = list.get_index(x);
        cout << value << endl;
    }
    */

    
}