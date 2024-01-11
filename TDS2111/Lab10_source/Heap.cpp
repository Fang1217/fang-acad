#include <iostream>
using namespace std;

typedef int HeapItemType;

class Heap
{
    public:
        Heap();
        // ~Heap();   // static destructor, not needed

        bool isEmpty();
        void insert(HeapItemType newItem);
        void erase(HeapItemType& rootItem);

    private:
        static const int MAX_SIZE = 100;

        HeapItemType items[MAX_SIZE]; // uses array-based implementation because heap is a complete BST
        int size;

        void rebuild(int rootIndex);
        void swap(HeapItemType& first, HeapItemType& second);

};

Heap::Heap() : size(0)
{}

bool Heap::isEmpty()
{
    return size == 0;
}

void Heap::insert(HeapItemType newItem)
{
    if (size == MAX_SIZE)
    {
        cout << "Error at insert(): Heap is full!" << endl;
    }
    else
    {
        // TODO: Begin practice question 4a-1 (ONLY the numbered comments)
        // (1) Place the new item at the end of the heap.
        items[size] = newItem; 

        // End question

        int newItemIndex = size;
        int parent = (newItemIndex - 1) / 2; // floor of decimal point value
                                             // for integer division

        // "Tickles the new item up" to an appropriate spot in the tree.
        // Exclude zero index.
        while (newItemIndex > 0 && items[newItemIndex] > items[parent])
        {
            // TODO: Begin practice question 4a-2
            // (2) Swap items[newItemIndex] and items[parent]
            HeapItemType temp = items[newItemIndex];
            items[newItemIndex] = items[parent];
            items[parent] = temp;
            // (3) Update newItemIndex to its correct place
            newItemIndex = parent;
            // (4) Update parent to its correct place
            parent = (parent - 1) / 2;
        }
        size++;
    }
}

void Heap::erase(HeapItemType& rootItem)
{
    if (isEmpty())
    {
        cout << "Error at erase(): Heap is empty!" << endl;
    }
    else
    {
        // TODO: Begin practice question 4b
        // (1) Set the root item with the first item in this heap
        rootItem = items[0];
        // (2) Decrease the size by 1
        size--;
        // (3) Set the first item of the heap with the last item.
        items[0] = items[size];

        // Rebuild the heap.
        rebuild(0); //trickles down
    }
}

void Heap::rebuild(int rootIndex)
{
    // assume the largest child so far is the "left child"
    int indexOfLargestChild = 2 * rootIndex + 1;

    // if the left child exists
    if (indexOfLargestChild < size)
    {
        // get the index of the right child
        int rightChild = indexOfLargestChild + 1;

        if (rightChild < size && items[indexOfLargestChild] < items[rightChild])
            indexOfLargestChild = rightChild;

        // if the item in the rootIndex is smaller than the items in the largest child
        if (items[rootIndex] < items[indexOfLargestChild])
        {
            // swap the item in rootIndex with the item in the largest child
            swap(items[rootIndex], items[indexOfLargestChild]);

            // rebuild the "semiheap" tree to "heap" tree
            // starts with the new index of largest child as the root
            rebuild(indexOfLargestChild); //recursion here, trickles down
        }
    }
}

void Heap::swap(HeapItemType& first, HeapItemType& second)
{
    HeapItemType temp = first;
    first = second;
    second = temp;
}
