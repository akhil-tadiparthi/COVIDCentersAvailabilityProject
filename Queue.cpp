#include <iostream>
#include <fstream>
#include <sstream>
//#include "Graph-1.h"
#include "Queue.h"

using namespace std;

Queue::Queue(int size){
    queueSize = size;
    queueHead = queueTail = -1;
    queueCount = 0;
    personQueue = new person[queueSize];
};


bool Queue::enqueue(person individual){
    if(queueHead == -1){
        queueHead = queueTail = 0;
    } else if((queueTail == queueHead-1) || (queueHead == 0 && queueTail == queueSize-1)){
        cout << "Queue is full" << endl;
        return false;
    } else if(queueHead != 0 && queueTail == queueSize-1){
        queueTail = 0;
    } else{
        queueTail++;
    }
    personQueue[queueTail] = individual;
    queueCount++;
    return true;
};


person Queue::dequeue(){
    person tmpCar;
    tmpCar = personQueue[queueHead];
    personQueue[queueHead].name = "";
    personQueue[queueHead].age = 0;
    personQueue[queueHead].address = "";
    if(queueHead == queueTail){
        queueHead = queueTail = -1;
        cout << "Queue is empty" << endl;
    }else if(queueHead == queueTail -1){
        queueHead = 0;
    } else{
        queueHead++;
    }
        queueCount--;
    return tmpCar;
};


void Queue::printQueue(){
    if(queueHead == -1){
        cout << "queue is empty" << endl;
        return;
    }
    if(queueTail >= queueHead){
        for(int i=queueHead; i<=queueTail; i++){
            cout << "q[" << i << "]: " << personQueue[i].name << " : " << personQueue[i].age << " : " << personQueue[i].address << endl;
        }
    } else{
        for(int i=queueHead; i<queueSize; i++){
            cout << "q[" << i << "]: " << personQueue[i].name << " : " << personQueue[i].age << " : " << personQueue[i].address << endl;
        }
        for(int i=0; i<=queueTail; i++){
            cout << "q[" << i << "]: " << personQueue[i].name << " : " << personQueue[i].age << " : " << personQueue[i].address << endl;
        }
    }
};


bool Queue::queueIsFull(){
    return queueCount == queueSize;
};


bool Queue::queueIsEmpty(){
    return queueCount == 0;
};

