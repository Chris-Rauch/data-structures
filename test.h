#ifndef TEST_H
#define TEST_H

class myClass 
{
    struct node {
        int first;
        int last;
    };

public:
    myClass();
    void doSomething();
    int getSomeVal();

private:
    int someVal;
};

#endif