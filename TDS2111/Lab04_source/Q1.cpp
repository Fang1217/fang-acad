
#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef char StackItemType;

class Stack
{
    private:
        stack<StackItemType> s;

    public:
        bool isEmpty() const
        {
            return s.empty();
        }

        void push(const StackItemType &v)
        {
            s.push(v);
        }

        void pop()
        {
            s.pop();
        }

        void pop(StackItemType &stackTop)
        {
            stackTop = s.top();
            s.pop();
        }

        void getTop(StackItemType &stackTop)
        {
            stackTop = s.top();
        }

        int size()
        {
            return s.size();
        }
};

// TODO: Write your code here
// Begin Question
bool balancedBraces(const string &input)
{  
    Stack s;
    for (char i : input) {
        switch (i)
        {
            case '{':
                s.push('{');
                break;
            case '}':
                if (s.isEmpty())
                    return false;
                s.pop();
                break;
            default:
                break;
        }
    }
    return s.isEmpty();
}
// End Question

int main(int argc, char *argv[])
{
    string input;
    bool balancedSoFar = false;

    cout << "Input a string: ";
    cin >> input;

    balancedSoFar = balancedBraces(input);

    if (balancedSoFar)
    {
        cout << "Result: The above string is balanced" << endl;
    }
    else
    {
        cout << "Result: The above string is not balanced" << endl;
    }

    system("PAUSE");
    return 0;
}
