#include <iostream>
#include <sstream> //stringstream
using namespace std;

typedef int DataType;
const int N_ITEMS = 10;
const int length = 2;

void radixSort(string[], int, int);
void displayArray(const DataType[], int, int);

int main()
{
   DataType a[N_ITEMS] = {10, 5, 21, 5, 99, 8, 16, 4, 72, 25};
   string s[N_ITEMS];

   cout << "Initial array : ";
   displayArray(a, 0, N_ITEMS - 1);
   cout << endl;

   // Convert each element to string
   for (int i = 0; i < N_ITEMS; i++)
   {
      stringstream ss;
      ss << a[i];
      s[i] = ss.str();
      for (int j = s[i].length(); j < length; j++)
         s[i] = "0" + s[i];
   }

   radixSort(s, N_ITEMS, length);

   // Convert each element to integer
   for (int i = 0; i < N_ITEMS; i++)
   {
      stringstream ss;
      ss << s[i];
      ss >> a[i];
   }

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

void radixSort(string theArray[], const int size, int length)
{
   // To do: radix sort by sorting from lowest power to highest
   string tempArray[10][size];
   int endPoint[10];

   for (int j = length - 1; j > -1; j--)
   {
      // Init Empty 2D Array
      for (int i = 0; i < 10; i++)
         for (int k = 0; k < size; k++)
            tempArray[i][k] = "";

      // Init endPoint array
      for (int i = 0; i < 10; i++)
         endPoint[i] = 0;

      for (int index = 0; index < size; index++)
      {
         int k = theArray[index][j] - '0';
         tempArray[k][endPoint[k]] = theArray[index];
         endPoint[k]++;
      }

      cout << "Group by digit " << j + 1 << ": ";

      int index = 0;

      for (int i = 0; i < 10; i++)
      {
         cout << "[ ";
         for (int k = 0; k < endPoint[i]; k++)
         {
            theArray[index] = tempArray[i][k];
            cout << theArray[index] << " ";
            index++;
         }
         cout << "] ";
      }
      cout << endl;
   }
}
