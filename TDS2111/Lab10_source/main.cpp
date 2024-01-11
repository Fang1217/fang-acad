#include <iostream>
#include "BinarySearchTree.cpp"
#include "Heap.cpp"
using namespace std;

void Practice1()
{
    BinarySearchTree bst;
    bst.insert(13);
    bst.insert(4);
    bst.insert(2);
    bst.insert(7);
    bst.insert(3);
    bst.insert(1);
    bst.insert(6);
    bst.insert(11);
    bst.insert(5);
    bst.insert(9);
    bst.insert(10);
    bst.inorderDisplay();
}

void Practice2()
{
    BinarySearchTree bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(7);
    bst.insert(3);
    bst.insert(1);
    bst.insert(6);
    bst.insert(11);
    bst.insert(5);
    bst.insert(9);
    bst.insert(10);

    cout << "Before erase: " << endl;
    bst.inorderDisplay();

    cout << "\nAfter erase 9, 10, and 6:" << endl;
    bst.erase(9);
    bst.erase(10);
    bst.erase(6);
    bst.inorderDisplay();
}

void Practice3()
{
    BinarySearchTree bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(7);
    bst.insert(3);
    bst.insert(1);
    bst.insert(6);
    bst.insert(11);
    bst.insert(5);
    bst.insert(9);
    bst.insert(10);
    bst.insert(13);
    bst.descendingOrderDisplay();
}


void Practice4()
{
    Heap heap;
    heap.insert(3);
    heap.insert(2);
    heap.insert(5);
    heap.insert(9);
    heap.insert(6);

    while (!heap.isEmpty())
    {
        HeapItemType value;
        heap.erase(value);

        cout << value << " ";
    }
    cout << endl;
}

int main()
{
    // Practice1();
    // Practice2();
    // Practice3();
    // Practice4();

    return 0;
}
