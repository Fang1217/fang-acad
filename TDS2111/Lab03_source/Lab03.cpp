#include <iostream>
#include <cstring>
using namespace std;

//Question 1
int sum(int input) { //Recursive method
    return (input == 1 ? 1 : (input + sum(input - 1)));
}

int sumNonrecursive(int input) {
    int result = 0;
    for (int i = 0; i <= input; i++) 
        result += i;
    return result;
}

//End Question 1
//

//Question 2

float pow(float input, int exponent) {
    if (exponent > 0)
        return (exponent == 1 ? input : input * pow(input, exponent-1));
    else if (exponent < 0)
        return (1.0 / (input * pow(input, -(exponent + 1))));
    else 
        return 1.0;
}

float powNonrecursive(float input, int exponent) {
    float result = 1;
    for (int i = 0; i < abs(exponent); i++) 
        result *= input;
    return exponent > 0 ? result : 1.0f/(float)result;
}
//End Question 2
//

//Question 3
bool palindrome(char *p1, char *p2) {
    if (tolower(*p1) != tolower(*p2))
        return false;
    else if (p2 < p1)
        return palindrome(p1+1, p2-1);
    return true;
}
//End Question 3
//

//Question 4
int array_sum(const int arr[], const int size) {
    return size == 0 ? 0 : arr[0] + array_sum(arr + 1, size - 1);
}


// Test runs (main())
int main() {
    cout << " " << sum(3); 
    cout << " " << sum(4); 
    cout << " " << sumNonrecursive(3);
    cout << " " << sumNonrecursive(4);
    cout << " " << pow(2, 4);
    cout << " " << pow(3, 4);
    cout << " " << pow(2.0, -4);
    cout << " " << pow(3, -4);
    cout << " " << pow(3, 0);
    cout << " " << powNonrecursive(2, 4);
    cout << " " << powNonrecursive(3, 4);
    cout << " " << powNonrecursive(2, -4);
    cout << " " << powNonrecursive(3, -4);
    cout << " " << powNonrecursive(3, 0);
    cout << endl;

    char str[] = "Nowwon";
    if (palindrome(str, str+strlen(str)-1))
        cout << str << " is a palindrome" << endl;
    else
        cout << str << " is not a palindrome" << endl;

    int a[] = { 4, 2, 2 };
    int b[] = { 4, 3, 2, 8 };
    cout << array_sum(a, 3) << endl; // 2nd arg is the number of elements
    cout << array_sum(b, 4) << endl;
    return 0;

}




