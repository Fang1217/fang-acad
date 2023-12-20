/** ADT Stack - Pointer-based implementation. */

#include <iostream>
#include <stdexcept> // for exception
#include <string>
#include <cstddef> // for NULL
#include <new>     // for bad_alloc
#include <regex>


using namespace std;

typedef float StackItemType;

/** @class StackException
 * Exception class throw by ADT stack. */
class StackException : public logic_error
{
public:
    StackException(const string &message = "")
        : logic_error(message.c_str())
    {
    }
};

class Stack
{
public:
    /** Default constructor. */
    Stack();

    /** Copy constructor.
     * @param aStack The stack to copy. */
    Stack(const Stack &aStack);

    /** Destructor. */
    ~Stack();

    // Stack operations:
    bool isEmpty() const;
    /*
    void push(const StackItemType &newItem) throw(StackException);
    void pop() throw(StackException);
    void pop(StackItemType &stackTop) throw(StackException);
    void getTop(StackItemType &stackTop) const throw(StackException);
    */
    void push(const StackItemType &newItem);
    void pop();
    void pop(StackItemType &stackTop);
    void getTop(StackItemType &stackTop) const;

private:
    /** A node on the stack. */
    struct StackNode
    {
        /** A data item on the stack. */
        StackItemType item;
        /** Pointer to next node.     */
        StackNode *next;
    };

    /** Pointer to first node in the stack. */
    StackNode *topPtr;
};

Stack::Stack() : topPtr(NULL)
{
}

// Copy constructor, Deep copy
Stack::Stack(const Stack &aStack)
{
    if (aStack.topPtr == NULL)
        topPtr = NULL; // original list is empty

    else
    {
        // copy first node
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        // copy rest of list
        StackNode *newPtr = topPtr; // new node pointer
        for (StackNode *origPtr = aStack.topPtr->next;
             origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }

        newPtr->next = NULL; // tail
    }
}

Stack::~Stack()
{
    // pop until stack is empty
    while (!isEmpty())
        pop();
    // Assertion: topPtr == NULL
}

bool Stack::isEmpty() const
{
    return topPtr == NULL;
}

void Stack::push(const StackItemType &newItem) //throw(StackException)
{
    // create a new node
    try
    {
        StackNode *newPtr = new StackNode;

        // set data portion  of new node
        newPtr->item = newItem;

        // insert the new node
        newPtr->next = topPtr; // newPtr->next pointer points to topPtr
        topPtr = newPtr;
    }
    catch (bad_alloc e)
    {
        throw StackException(
            "StackException: push cannot allocate memory.");
    }
}

void Stack::pop()// throw(StackException)
{
    if (isEmpty())
        throw StackException("StackException: stack empty on pop");
    else
    {
        // stack is not empty; delete top
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        // return deleted node to system
        temp->next = NULL; // safeguard, don't point anything, points to nothing
        delete temp;
    }
}

void Stack::pop(StackItemType &stackTop)// throw(StackException)
{
    if (isEmpty())
        throw StackException("StackException: stack empty on pop");
    else
    {
        // stack is not empty; retrieve and delete top
        stackTop = topPtr->item;
        StackNode *temp = topPtr;
        topPtr = topPtr->next;

        // return deleted node to system
        temp->next = NULL; // safeguard, points to nothing
        delete temp;
    }
}

void Stack::getTop(StackItemType &stackTop) const //throw(StackException)
{
    if (isEmpty())
        throw StackException("StackException: stack empty on getTop");
    else
        // stack is not empty; retrieve top
        stackTop = topPtr->item;
}

// TODO: Write your code here
// Begin Question
float evalPostfixExpression(string str)
{
    Stack numberStack; 
    string operand = "+-*/";

    float number = 0; 
    float result = 0;

    for (char ch : str) {
        if (operand.find(ch) != std::string::npos) {
            // Char `ch` is found in string `operand` (did not fail to find)
            float n1 = 0, n2 = 0;
            numberStack.getTop(n2);
            numberStack.pop();
            numberStack.getTop(n1);
            numberStack.pop();

            switch (ch) {
                case '+':   numberStack.push(n1 + n2);  break;
                case '-':   numberStack.push(n1 - n2);  break;
                case '*':   numberStack.push(n1 * n2);  break;
                case '/':   numberStack.push(n1 / n2);  break;
            };
        }
        else if (ch >= '0' && ch <= '9') 
            number = (number * 10) + (ch - '0'); // Numbers
        else if (ch == ' ')
            if (number != 0) {
                numberStack.push(number); // Spaces 
                number = 0;
            }
    }
    numberStack.getTop(result);
    return result; 
}

// End Question

int main()
{
    system("title ADT Stack Application - Evaluating Postfix Expressions");

    string postfixExp;
    float result;

    cout << "Enter a postfix expression to be evaluated: ";
    getline(cin, postfixExp);

    result = evalPostfixExpression(postfixExp);

    cout << postfixExp << " = " << result << endl;

    system("pause");
    return 0;
}
