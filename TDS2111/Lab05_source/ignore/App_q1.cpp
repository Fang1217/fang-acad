#include <iostream>
#include "QueueL.hpp"

using namespace std;
using Practice2::Queue;

int main()
{
    Queue input;
    char character = '\0';

    cout << "Input characters (Press ENTER to stop):" << endl;
    while (cin.peek() != '\n')
    {
        cin >> character;
        input.enqueue(character);
    }
    cout << endl;

// TODO: Start your code here
    Queue characterTypes[4];
    
    while (!input.isEmpty()) {
        char ch = input.getFrontAndPop();
        if (ch >= '0' && ch <= '9')
            characterTypes[0].enqueue(ch);
        else if (ch >= 'a' && ch <= 'z')
            characterTypes[1].enqueue(ch);
        else if (ch >= 'A' && ch <= 'Z')
            characterTypes[2].enqueue(ch);
        else 
            characterTypes[3].enqueue(ch);
    }
    for (int i = 0; i < 4; i++) {
        string output = "";
        switch (i)
        {
            case 0: output = "Numbers:"; break;
            case 1: output = "Small Letters:"; break;
            case 2: output = "Capital Letters:"; break;
            case 3: output = "Others:"; break;
        }
        while (!characterTypes[i].isEmpty()) 
            output = output + " " + characterTypes[i].getFrontAndPop();
        cout << output << endl;
    }
    return 0;   
}
