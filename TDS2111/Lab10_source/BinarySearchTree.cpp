#include <iostream>
#include <cstddef> // for NULL
using namespace std;

typedef int TreeItemType;

class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(TreeItemType newItem);
        void erase(TreeItemType deleteItem);

        void inorderDisplay();
        void descendingOrderDisplay();

    private:
        struct BinaryTreeNode
        {
            BinaryTreeNode()  // struct constructor
            {
                leftChildPtr = NULL;
                rightChildPtr = NULL;
            }

            TreeItemType item;
            BinaryTreeNode* leftChildPtr;
            BinaryTreeNode* rightChildPtr;
        };

        BinaryTreeNode* root;

        void clear(BinaryTreeNode*& ptr);

        void recursiveInorderDisplay(BinaryTreeNode* ptr);

        void recursiveInsert(BinaryTreeNode*& ptr, TreeItemType newItem);
        void recursiveErase(BinaryTreeNode*& ptr, TreeItemType newItem);

        // For leaf, 1 child and 2 children
        void eraseLeftMost(BinaryTreeNode*& ptr, TreeItemType& replaceItem);

        void recursiveDescendingOrderDisplay(BinaryTreeNode* ptr);
};

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    clear(root);
    root = NULL;
}

/*
    Purpose:
        Insert a new item into the tree.

    Parameter:
        newItem - the item to be inserted.
*/
void BinarySearchTree::insert(TreeItemType newItem)
{
    recursiveInsert(root, newItem);
}

/*
    Purpose:
        Recursively insert a new item into the tree.

    Parameter:
        ptr     - the root of the subtree where newItem is inserted
        newItem - the item to be inserted.
*/
void BinarySearchTree::recursiveInsert(BinaryTreeNode*& ptr, TreeItemType newItem)
{
    // reach the bottom level of the tree
    if (ptr == NULL)
    {
        // TODO: Begin practice question 1b
        // Hint:
        // (1) Create a binary tree node
        ptr = new BinaryTreeNode();
        ptr->item = newItem;
    }
    else
    {
        if (newItem < ptr->item)
            // traverse down and insert new item on the left subtree of ptr.
            recursiveInsert(ptr->leftChildPtr, newItem);
        else
            // traverse down and insert new item on the right subtree of ptr.
            recursiveInsert(ptr->rightChildPtr, newItem);
    }
}

void BinarySearchTree::inorderDisplay()
{
    recursiveInorderDisplay(root);
}

void BinarySearchTree::clear(BinaryTreeNode*& ptr)
{
    if (ptr != NULL)
    {
        clear(ptr->leftChildPtr);
        clear(ptr->rightChildPtr);
        delete ptr;   // destructor is postorder traversal
        ptr = NULL;
    }
}

void BinarySearchTree::recursiveInorderDisplay(BinaryTreeNode* ptr)
{
    if (ptr != NULL)
    {
        recursiveInorderDisplay(ptr->leftChildPtr);
        cout << ptr->item << " ";
        recursiveInorderDisplay(ptr->rightChildPtr);
    }
}

/*
    Purpose:
        Erase an item from the tree if it's found.

    Parameter:
        deleteItem - the item to be erased.
 */


void BinarySearchTree::erase(TreeItemType deleteItem)
{
    recursiveErase(root, deleteItem);
}

/*
    Purpose:
        Recursively erase an item into the tree.

    Parameter:
        ptr        - the root of the subtree where deleteItem is searched
        deleteItem - the item to be erased.
 */
void BinarySearchTree::recursiveErase(BinaryTreeNode*& ptr, TreeItemType deleteItem)
{
    if (ptr == NULL)
        cout << "Error at recursiveErase(): Item not found." << endl;
    else if (deleteItem < ptr->item)
        recursiveErase(ptr->leftChildPtr, deleteItem);
    else if (deleteItem > ptr->item)
        recursiveErase(ptr->rightChildPtr, deleteItem);
    // the item is found, deleteItem == ptr->item
    else
    {
        // Case 1: the node to be deleted is a leaf node
        if (ptr->leftChildPtr == NULL && ptr->rightChildPtr == NULL)
        {
            // TODO: Begin practice question 2b-1
            // Hint:
            // (1) Delete the node pointed by ptr
            delete ptr;
            // (2) Set ptr to null.
            ptr = NULL;
        }
        // Case 2: the node to be deleted has no right subtree
        else if (ptr->rightChildPtr == NULL)
        {
            // TODO: Begin practice question 2b-2
            // Hint:
            // (1) Make a temporary copy of ptr.
            BinaryTreeNode* temp = ptr;
            // (2) Assign ptr with its left child pointer.
            ptr = ptr->leftChildPtr;
            // (3) Delete the temporary copy of ptr.
            delete temp;
            temp = NULL;
        }
        // Case 3: the node to be deleted has no left subtree
        else if (ptr->leftChildPtr == NULL)
        {
            // TODO: Begin practice question 2b-3
            // Hint:
            // (1) Make a temporary copy of ptr.
            // (2) Assign ptr with its right child pointer.
            // (3) Delete the temporary copy of ptr.
            BinaryTreeNode* temp = ptr;
            // (2) Assign ptr with its left child pointer.
            ptr = ptr->rightChildPtr;
            // (3) Delete the temporary copy of ptr.
            delete temp;
            temp = NULL;
        }
        // Case 4: The node to be deleted has 2 subtrees
        else
        {
            // node N leftmost means inorder successor of node N
            eraseLeftMost(ptr->rightChildPtr, ptr->item);
        }
    }
}

void BinarySearchTree::eraseLeftMost(BinaryTreeNode*& ptr, TreeItemType& replaceItem)
{
    // The leftmost children is found
    if (ptr->leftChildPtr == NULL)
    {
        // this is the node you want;
        // it has no left child, but
        // it might have a right subtree
        replaceItem = ptr->item;

        // delete this pointer
        BinaryTreeNode* temp = ptr;

        // the actual argument corresponding to ptr
        // is a child pointer of ptr's parent; thus, the
        // following "moves up" ptr's right subtree
        ptr = ptr->rightChildPtr;

        delete temp;
    }
    else
    {
        // Keep traversing the left most children.
        eraseLeftMost(ptr->leftChildPtr, replaceItem);
    }
}

void BinarySearchTree::descendingOrderDisplay()
{
    recursiveDescendingOrderDisplay(root);
}

void BinarySearchTree::recursiveDescendingOrderDisplay(BinaryTreeNode* ptr)
{
    // TODO: Begin practice question 3b
    // No hints because this is relatively easy   v(^_^)v
    if (ptr != NULL)
    {
        recursiveDescendingOrderDisplay(ptr->rightChildPtr);
        cout << ptr->item << " ";
        recursiveDescendingOrderDisplay(ptr->leftChildPtr);
    }
    // End question
}


