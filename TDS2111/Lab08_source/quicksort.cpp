#include <iostream>
#include <iomanip>
using namespace std;

typedef int DataType;
const int N_ITEMS = 10;

void swap(DataType &, DataType &);
void displayArray(const DataType[], int, int);
void quickSort(DataType[], int, int);
void partition(DataType[], int, int, int &);

int main()
{
    DataType a[N_ITEMS] = {10, 5, 21, 5, 99, 8, 16, 4, 72, 25};

    cout << "Initial array : ";
    displayArray(a, 0, N_ITEMS - 1);
    cout << endl;

    quickSort(a, 0, N_ITEMS - 1);

    cout << "Sorted array : ";
    displayArray(a, 0, N_ITEMS - 1);
    cout << endl;

    return 0;
}

void swap(DataType &x, DataType &y)
{
    DataType temp = x;
    x = y;
    y = temp;
    cout << "Swapped " << setw(2) << x << " with " << setw(2) << y << "\n";
}

void displayArray(const DataType theArray[], int first, int last)
{
    for (int i = first; i <= last; ++i)
        cout << setw(2) << theArray[i] << " ";
}

void partition(DataType theArray[], int first, int last, int &pivotIndex)
{
    // To do: partition array into [ S1 | Pivot | S2 ]
    DataType pivot = theArray[first];

    int lastS1 = first;
    int firstUnknown = first + 1;
    for (; firstUnknown <= last; firstUnknown++)
    {
        if (theArray[firstUnknown] < pivot) {
            swap(theArray[firstUnknown], theArray[lastS1 + 1]);
            lastS1++;
        } 
    }

    swap(theArray[first], theArray[lastS1]);
    pivotIndex = lastS1;

    // set pivot to first element
    // sort unknowns to S1 and S2
    // given items in S1 are < pivot
    //       items in S2 are >= pivot
}

void quickSort(DataType theArray[], int first, int last)
{
    // To do: implement quicksort when items in list > 1
    int pivotIndex;
    if (first < last)
    {

        partition(theArray, first, last, pivotIndex);

        quickSort(theArray, first, pivotIndex - 1); 
        quickSort(theArray, pivotIndex + 1, last);
    }
}
