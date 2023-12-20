#ifndef QUEUE_L_HPP
#define QUEUE_L_HPP

typedef char QueueItemType;

namespace Practice2
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
        QueueItemType getFrontAndPop();

    private:
        struct QueueNode
        {
            QueueItemType item;
            QueueNode *next;
        }; // end QueueNode

        QueueNode *backPtr;
        QueueNode *frontPtr;

    }; // end Queue

}; // end namespace Practice2

#endif
