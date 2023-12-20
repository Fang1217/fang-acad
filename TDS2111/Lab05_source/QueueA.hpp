#ifndef QUEUE_A_HPP
#define QUEUE_A_HPP

typedef char QueueItemType;

namespace Practice1
{
    class Queue
    {
    public:
        Queue();
        ~Queue();

        bool isEmpty();
        void enqueue(QueueItemType newItem);
        void dequeue();
        QueueItemType getFront();

    private:
        static const int MAX_QUEUE = 5;

        QueueItemType items[MAX_QUEUE];
        int front; // index of the front element
        int back;  // index of the back element
        int count; // number of elements in the queue

    }; // end Queue

}; // end namespace Practice1

#endif
