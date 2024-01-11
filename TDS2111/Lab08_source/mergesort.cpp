#include <iostream>
using namespace std;

typedef int DataType;
const int N_ITEMS = 10;

void displayArray(const DataType[], int, int);
void merge(DataType[], int, int, int);
void mergeSort(DataType[], int, int);

int main()
{
    DataType a[N_ITEMS] = {10, 5, 21, 5, 99, 8, 16, 4, 72, 25};

    cout << "Initial array : ";
    displayArray(a, 0, N_ITEMS - 1);
    cout << endl;

    mergeSort(a, 0, N_ITEMS - 1);

    cout << "Sorted array : ";
    displayArray(a, 0, N_ITEMS - 1);
    cout << endl;

    return 0;
}

void displayArray(const DataType theArray[], int first, int last)
{
    for (int i = first; i <= last; ++i)
        cout << theArray[i] << " ";
}

void merge(DataType theArray[], int first, int mid, int last)
{
    // To do: Merge two halves into a sorted part using a
    //        temporary array

    // Create temp array
    DataType tempArray[N_ITEMS];
    // Compare and merge
    int leftPointer = first;
    int rightPointer = mid + 1;
    int index = first;

    while (leftPointer <= mid && rightPointer <= last)
    {
        if (theArray[leftPointer] <= theArray[rightPointer])
        {
            tempArray[index] = theArray[leftPointer];
            leftPointer++;
        }
        else {
            tempArray[index] = theArray[rightPointer];
            rightPointer++;
        }
        index++;
    }
    if (leftPointer > mid)
        for (int i = rightPointer; i <= last; i++) {
            tempArray[index] = theArray[i];
            index++;
        }
    else if (rightPointer > last)
        for (int i = leftPointer; i <= mid; i++) {
            tempArray[index] = theArray[i];
            index++;
        }

    for (int i = first; i <= last; i++) 
        theArray[i] = tempArray[i];
    
    // Check any item in left half
    // Check any item in right half
    // Copy all the items in the temp array to original array.
}

void mergeSort(DataType theArray[], int first, int last)
{

    if (first < last)
    {
        // Mid value
        int mid = (first + last) / 2;

        // Recursive call to split left half
        mergeSort(theArray, first, mid);

        // Recursive call to split right half
        mergeSort(theArray, mid+1, last);

        // Merge function
        merge(theArray, first, mid, last);
        displayArray(theArray, first, last);
        cout << endl;
    }

    // To do: Recursively call the mergeSort to split then use
    //        the merge function to combine and sort the halves
}
