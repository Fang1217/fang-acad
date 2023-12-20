#include <iostream>
using namespace std;

void displayArray(const int theArray[], int size);

// storageArea : array to store input
// size : the size of the storage area
// input : the value to be hashed
// storeIndex : the result after input is hashed
// found : the flag to indicate whether a storeIndex can be found
// probeStopValue : a value to stop probing from continue
void hash1(const int storageArea[], int size, int input, int &storeIndex, bool &found, int probeStopValue);

int main()
{
    const int N_ITEMS = 20;
    int input[N_ITEMS] = {524, 104, 230, 298, 172, 242, 827, 9, 14, 81, 26, 913, 238, 301, 329, 85, 329, 102, 24, 7};

    // Initialize storage area
    int store[N_ITEMS];
    for (int i = 0; i < N_ITEMS; i++)
    {
        // -1 indicates an empty slot
        store[i] = -1;
    }

    // Store input using hash function input[ i ] mod 20
    int storeIndex;
    bool found;
    for (int i = 0; i < N_ITEMS; i++)
    {
        hash1(store, N_ITEMS, input[i], storeIndex, found, -1);
        store[storeIndex] = input[i];
    }

    // Display storage map
    cout << "Storage map " << endl;
    displayArray(store, N_ITEMS);

    // Searching
    int searchKey;
    cout << "Input a value to search : ";
    cin >> searchKey;

    hash1(store, N_ITEMS, searchKey, storeIndex, found, searchKey);
    if (found == true)
    {
        cout << searchKey << " found at store index " << storeIndex << endl;
    }
    else
    {
        cout << searchKey << " not found." << endl;
    }

    return 0;
}

void hash1(const int storageArea[], int size, int input, int &storeIndex, bool &found, int probeStopValue)
{ // Write your code here
    int attempts = 1;
    found = false; 

    storeIndex = ((input % size) + size) % size;
    while (attempts <= size && !found)
    {
        if (storageArea[storeIndex] == probeStopValue)
            found = true;
        else
        {
            storeIndex = (storeIndex + 1) % size;
            attempts++;
        }
    }
}

void displayArray(const int theArray[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << i << "  " << theArray[i] << endl;
    }
}
