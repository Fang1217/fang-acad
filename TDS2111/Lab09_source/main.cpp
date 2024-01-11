#include <iostream>
#include "BinaryTree.cpp"
using namespace std;

void Practice1()
{
    BinaryTree tree1;
    tree1.setRootData("A");
    tree1.attachLeft("B");
    tree1.attachRight("C");
    tree1.inorderDisplay();
}

void Practice2()
{
    BinaryTree tree1;
    tree1.setRootData("D");
    tree1.attachLeft("E");
    tree1.attachRight("F");

    BinaryTree tree2;
    tree2.setRootData("G");
    tree2.attachLeft("H");
    tree2.attachRight("I");

    BinaryTree tree3;
    tree3.setRootData("J");
    tree3.attachLeftSubTree(tree1);
    tree3.attachRightSubTree(tree2);

    tree3.inorderDisplay();
}

void Practice3()
{
    BinaryTree tree1;
    tree1.setRootData("D");
    tree1.attachLeft("E");
    tree1.attachRight("F");

    BinaryTree tree2;
    tree2.setRootData("G");
    tree2.attachLeft("H");
    tree2.attachRight("I");

    BinaryTree tree3;
    tree3.setRootData("J");
    tree3.attachLeftSubTree(tree1);
    tree3.attachRightSubTree(tree2);

    tree3.preorderDisplay();
}

void Practice4()
{
    BinaryTree tree1;
    tree1.setRootData("D");
    tree1.attachLeft("E");
    tree1.attachRight("F");

    BinaryTree tree2;
    tree2.setRootData("G");
    tree2.attachLeft("H");
    tree2.attachRight("I");

    BinaryTree tree3;
    tree3.setRootData("J");
    tree3.attachLeftSubTree(tree1);
    tree3.attachRightSubTree(tree2);

    tree3.postorderDisplay();
}

void BuildAlexFamilyTree(BinaryTree& tree)
{
    // TODO: Begin app question 1a
    // (1) Build Alex's family tree.
    BinaryTree bernardTree;
    bernardTree.setRootData("Bernard");
    bernardTree.attachLeft("Carmen");
    bernardTree.attachRight("Dorothy");

    BinaryTree emirTree;
    emirTree.setRootData("Emir");
    emirTree.attachLeft("Felicia");
    emirTree.attachRight("Gordon");

    tree.setRootData("Alex");
    tree.attachLeftSubTree(bernardTree);
    tree.attachRightSubTree(emirTree);
    // End question
}

void Application1()
{
    BinaryTree alexfamily;
    BuildAlexFamilyTree(alexfamily);

    // TODO: Begin app question 1b
    // (1) Display all the family members' of Alex (including himself)
    //     in alphabetical order.
    // Hint: Uses preorder to display this. Infer Alex family tree diagram
    cout << "Alex's family: ";
    alexfamily.preorderDisplay();
    cout << endl;
}

void Application2()
{
    BinaryTree alexfamily;
    BuildAlexFamilyTree(alexfamily);

    string name;

    cout << "Enter a name: ";
    cin >> name;

    // TODO: Begin app question 2b
    // (1) Find the name from Alex family tree.
    bool found = alexfamily.find(name);

    // (2) Display the results according to the sample output in
    //     the lab sheet.

    if (found) {
        cout << name << " is a member of Alex's family." << endl;
    } else {
        cout << name << " is not found in Alex's family." << endl;
    }
}

void Application3()
{
    BinaryTree alexfamily;
    BuildAlexFamilyTree(alexfamily);

    string firstName, secondName;

    cout << "Enter name 1: ";
    cin >> firstName;
    cout << "Enter name 2: ";
    cin >> secondName;

    // TODO: Begin app question 3b
    // (1) Determine whether firstName is one of the descendants of
    //     secondName.
    bool isDescendant = alexfamily.isDescendant(firstName, secondName);

    // (2) Display the results according to the sample output in
    //     the lab sheet.
    if (isDescendant) {
        cout << firstName << " is a descendant of " << secondName << "." << endl;
    } else {
        cout << firstName << " is not a descendant of " << secondName << "." << endl;
    }
}

int main()
{
    // Practice1();     // Expected Output: B A C             inorder
    // Practice2();     // Expected Output: E D F J H G I     inorder
    // Practice3();     // Expected Output: J D E F G H I     preorder
    // Practice4();     // Expected Output: E F D H I G J     postorder

     Application1();
    // Application2();
    // Application3();

    return 0;
}
