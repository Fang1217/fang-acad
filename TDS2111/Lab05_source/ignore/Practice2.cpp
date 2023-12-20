#include <iostream>
// #include "QueueA.hpp"
#include "QueueL.hpp"
using namespace std;
// using Practice1::Queue;
using Practice2::Queue;

int main()
{
    Queue q;
    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    char ch = q.getFront();
    q.dequeue();
    q.dequeue();
    q.enqueue('D');
    q.enqueue('E');
    q.enqueue(ch);
    q.dequeue();
    q.enqueue('F');
    q.dequeue();

    // display the content in the queue
    while (!q.isEmpty())
    {
        cout << q.getFront() << endl;
        q.dequeue();
    }

    return 0;
}
