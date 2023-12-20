    /*******************************************************************************

	Your Task:
		This program accepts a name from the user and display the text as shown in the sample run.
		However, there are syntax as well as logical errors in the program.

		Correct the errors such that given the sample input below,  
		the output will be correct as indicated.

	Sample run 1:
   		Enter a name -> william
   		Output : william illiam lliam liam iam am m

 	Sample run 2:
   		Enter a name -> cyberjaya
   		Output : cyberjaya yberjaya berjaya erjaya rjaya jaya aya ya a

    *******************************************************************************/
#include <iostream>
#include <cstdlib> //system
using namespace std;

int main()
{
    char name[20];
    char* initialPointer;
    char* currentPointer;

    system("title Lab 1: Are you ready?");
    cout << "Enter a name -> ";
    cin >> name;
    cout << "Output : ";

    for (initialPointer = name; *initialPointer != '\0'; initialPointer++)
    {
        for (currentPointer = initialPointer; *currentPointer != '\0'; currentPointer++)
            cout << *currentPointer;
        cout << ' ';
    }
    cout << endl;

    system("pause");
    return 0;
}



