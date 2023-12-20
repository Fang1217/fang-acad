#include <iostream>
#include "QueueA.hpp"
using namespace std;
using namespace Practice1;

Queue::Queue() : front(0), back(MAX_QUEUE - 1), count(0)
{}

Queue::~Queue()
{}

bool Queue::isEmpty()
{
    return count == 0;
}

void Queue::enqueue(QueueItemType newItem)
{
// TODO: Fill in your code here
    // HINT:
    // (a) Check whether the queue is full
    if (count == MAX_QUEUE)
        return;
    
    // (b) Add the new item into the queue if it's not full
    back = (back + 1) % MAX_QUEUE;
    items[back] = newItem;

    // (c) Increase the count by 1
    count++;
}

void Queue::dequeue()
{
// TODO: Fill in your code here
    // HINT:
    // (a) Check whether the queue is empty
    if (count == 0) 
        return;
    
    // (b) Remove the front item of the queue if it's not empty
    items[front] = '\0';
    front = (front + 1) % MAX_QUEUE;
    // (c) Reduce the count by 1
    count--;
    
}

QueueItemType Queue::getFront()
{
// TODO: Fill in your code here
    if (isEmpty()) {
        return QueueItemType();
    }
    return items[front];
}
