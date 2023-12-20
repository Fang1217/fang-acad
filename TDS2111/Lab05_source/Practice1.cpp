#include <iostream>
#include "QueueA.hpp"
using namespace std;
using Practice1::Queue;

int main()
{
    Queue q;

    q.enqueue('a');
    q.enqueue('a');
    q.enqueue('F');
    q.enqueue('I');
    q.enqueue('S');
    q.enqueue('T');
    q.dequeue();
    q.dequeue();

    q.enqueue('M');
    q.enqueue('M');
    char ch = 'U';
    


    // q.enqueue('A');
    // q.enqueue('B');
    // q.enqueue('C');
    // char ch = q.getFront();
    // q.dequeue();
    // q.dequeue();
    // q.enqueue('D');
    // q.enqueue('E');
    // q.enqueue(ch);
    // q.dequeue();
    // q.enqueue('F');
    // q.dequeue();

    // display the content in the queue
    while (!q.isEmpty())
    {
        cout << q.getFront() << endl;
        q.dequeue();
    }

    return 0;
}
