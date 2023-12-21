#include <iostream>
#include <iomanip>
using namespace std;

typedef int DataType;
const int N_ITEMS = 10;

void insertionSort( DataType theArray[], int n );
void displayArray( const DataType theArray[], int first, int last );

int main(){
   DataType a[ N_ITEMS ] = { 10, 5, 21, 5, 99, 8, 16, 4, 72, 25 };

   cout << "Initial array : ";
   displayArray( a, 0, N_ITEMS-1 );
   cout << endl;

   insertionSort( a, N_ITEMS );

   cout << "Sorted array : ";
   displayArray( a, 0, N_ITEMS-1 );
   cout << endl;

   return 0;
}

void displayArray( const DataType theArray[], int first, int last ){
   for ( int i = first; i <= last; ++i )
      cout << setw(2) << theArray[ i ] << " ";
}

void insertionSort(DataType theArray[], int n){
   
   for (int i = 1; i < n; i++) {
      DataType temp = theArray[i];

      for (int j = i; j > 0; j--) {
         //cout << theArray[j] << endl;
         //cout << theArray[j-1] << endl;
         if (temp > theArray[j-1]) {
            theArray[j] = temp;
            break;
         }
         theArray[j] = theArray[j-1];
         theArray[j-1] = temp;
      }
      displayArray( theArray, 0, 9 );cout << endl;
   }
   // unsorted = first index of the unsorted region,
   // loc = index of insertion in the sorted region,
   // nextItem = next item in the unsorted region
   // To do: Implement insertion sort
}
