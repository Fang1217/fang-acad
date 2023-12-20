#include <iostream>
#include "QueueL.hpp"
using namespace std;
using namespace Practice2;

Queue::Queue() : backPtr(NULL), frontPtr(NULL)
{}

Queue::~Queue()
{
    while (!isEmpty())
        dequeue();
}

bool Queue::isEmpty()
{
    // TODO: Fill in your code here
    return backPtr == NULL;
}

void Queue::enqueue(QueueItemType newItem)
{
    // TODO: Fill in your code here    
    // HINT:
    // (a) Create a new node to store the new item
    QueueNode* newPtr = new QueueNode;
    newPtr->item = newItem;
    newPtr->next = NULL;

    // (b) If the queue is empty, the front pointer will point to the new node.
    if (isEmpty()) {
        frontPtr = newPtr;
        backPtr = newPtr;
    }
    // Otherwise, the back pointer's next pointer will point to the new node
    else 
        backPtr->next = newPtr;

    // (c) Assign the back pointer to the new node
    backPtr = newPtr;

}

void Queue::dequeue()
{
    // TODO: Fill in your code here    
    // HINT:
    // (a) Check whether the queue is empty
    if (isEmpty())
        return;
    // (b) Remove the front item of the queue if it's not empty
    QueueNode* tempPtr = frontPtr;
    if (frontPtr == backPtr) {
        frontPtr = NULL;
        backPtr = NULL;
    }
    else {
        tempPtr = frontPtr;
        frontPtr = frontPtr->next;
        tempPtr->next = NULL;
        delete tempPtr;
    }
}



QueueItemType Queue::getFront()
{
    return frontPtr->item;
}

QueueItemType Queue::getFrontAndPop()
{   QueueItemType frontItem = frontPtr->item;
    dequeue();
    return frontItem;
}