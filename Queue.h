#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

#include <iostream>

struct person{
    string name;
    int age;
    string address;
};

class Queue
{
public:
    Queue(int);
    ~Queue();
    bool enqueue(person individual);
    person dequeue();
    void printQueue();
    bool queueIsFull(); 
    bool queueIsEmpty(); 
    
protected:
private:
    int queueSize;
    int queueHead;
    int queueTail;
    int queueCount;
    person *personQueue;
};

#endif // QUEUE_H

