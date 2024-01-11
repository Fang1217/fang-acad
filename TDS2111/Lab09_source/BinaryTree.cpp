#include <iostream>
//#include "BinaryTree.hpp"
#include <string>
using namespace std;

typedef string TreeItemType;

class BinaryTree
{
    public:
        BinaryTree();
        ~BinaryTree();

        TreeItemType getRootData();
        void         setRootData(TreeItemType rootItem);

        void attachLeft(TreeItemType newItem);
        void attachRight(TreeItemType newItem);

        void attachLeftSubTree(BinaryTree& leftTree);
        void attachRightSubTree(BinaryTree& rightTree);

        void inorderDisplay();
        void preorderDisplay();
        void postorderDisplay();
        bool find(TreeItemType item);
        bool isDescendant(TreeItemType first, TreeItemType second);

    private:
        struct BinaryTreeNode
        {
            BinaryTreeNode()  // constructor
            {
                leftChildPtr = NULL;
                rightChildPtr = NULL;
            }

            TreeItemType    item;
            BinaryTreeNode* leftChildPtr;
            BinaryTreeNode* rightChildPtr;
        };

        BinaryTreeNode* root;

        void clear(BinaryTreeNode*& ptr);
        void recursiveInorderDisplay(BinaryTreeNode* ptr);
        void recursivePreorderDisplay(BinaryTreeNode* ptr);
        void recursivePostorderDisplay(BinaryTreeNode* ptr);
        BinaryTreeNode* recursiveFind(BinaryTreeNode* ptr,
          const TreeItemType& item);


};

BinaryTree::BinaryTree() : root(NULL)
{}

BinaryTree::~BinaryTree()
{
    clear(root);
}

// Returns the item in the root
TreeItemType BinaryTree::getRootData()
{
    return root->item;
}

// Update the root's item with a new item
// Create a tree node before the update if the tree is empty
void BinaryTree::setRootData(TreeItemType rootItem)
{
    if (root == NULL)
        root = new BinaryTreeNode();

    root->item = rootItem;
}

// Attach a new item to the left child of the root of this tree
void BinaryTree::attachLeft(TreeItemType newItem)
{
    // do nothing if the tree is empty or the left substree exists
    if (root == NULL || root->leftChildPtr != NULL)
    {
        cout << "Error attachLeft(): "
             << "tree is empty OR there's left a subtree." << endl;
    }
    else
    {
        // TODO: Begin practice question 1a
        // (1) Create a new tree node for the right child of root
        root->leftChildPtr = new BinaryTreeNode();
        // (2) Store the new item into the new tree node
        root->leftChildPtr->item = newItem;
    }
}

// Attach a new item to the right child of the root of this tree
void BinaryTree::attachRight(TreeItemType newItem)
{
    // do nothing if the tree is empty or the right subtree exists
    if (root == NULL || root->rightChildPtr != NULL)
    {
        cout << "Error attachRight(): "
             << "tree is empty OR there's a right subtree." << endl;
    }
    else
    {
        // TODO: Begin practice question 1b
        // (1) Create a new tree node for the right child of root
        root->rightChildPtr = new BinaryTreeNode();
        // (2) Store the new item into the new tree node
        root->rightChildPtr->item = newItem;
    }
}

// Attach a tree to the left child of the root of this tree
// The left tree will be made empty after the attachment
void BinaryTree::attachLeftSubTree(BinaryTree& leftTree)
{
    // do nothing if the tree is empty or the left subtree exists
    if (root == NULL || root->leftChildPtr != NULL)
    {
        cout << "Error attachLeftSubTree(): "
             << "tree is empty OR there's a left subtree." << endl;
    }
    else
    {
        // TODO: Begin practice question 2a
        // (1) Assign the root's left child pointer to point to the root of left tree.
        root->leftChildPtr = leftTree.root;
        // (2) Set the root of left tree to null, root of left tree points to nothing
        leftTree.root = NULL;
    }
}

// Attach a tree to the right child of the root of this tree
// The right tree will be made empty after the attachment
void BinaryTree::attachRightSubTree(BinaryTree& rightTree)
{
    // display error message
    // if the tree is empty or the right child exists
    if (root == NULL || root->rightChildPtr != NULL)
    {
        cout << "Error attachRightSubTree(): "
             << "tree is empty OR there's a right subtree." << endl;
    }
    else
    {
        // TODO: Begin practice question 2b
        // (1) Assign the root's right child pointer to point to the root of right tree.
        root->rightChildPtr = rightTree.root;
        // (2) Set the root of right tree to null, root of right tree points to nothing
        rightTree.root = NULL;
    }
}

// Display the content of the tree using inorder traversal
void BinaryTree::inorderDisplay()
{
    // recursively perform inorder display starting from the root node
    recursiveInorderDisplay(root);
}

// Display the content of the tree using inorder traversal
void BinaryTree::preorderDisplay()
{
    recursivePreorderDisplay(root);
}

// Display the content of the tree using inorder traversal
void BinaryTree::postorderDisplay()
{
    recursivePostorderDisplay(root);
}

// recursively perform inorder display starting from the root node
void BinaryTree::recursiveInorderDisplay(BinaryTreeNode* ptr)
{
    if (ptr != NULL)
    {
        recursiveInorderDisplay(ptr->leftChildPtr);
        cout << ptr->item << " ";
        recursiveInorderDisplay(ptr->rightChildPtr);
    }
}

// recursively perform preorder display starting from the root node
void BinaryTree::recursivePreorderDisplay(BinaryTreeNode* ptr)
{
    // TODO: Begin practice question 3
    if (ptr != NULL)
    {
        cout << ptr->item << " ";
        recursivePreorderDisplay(ptr->leftChildPtr);
        recursivePreorderDisplay(ptr->rightChildPtr);
    }
    // End question
}

// recursively perform postorder display starting from the root node
void BinaryTree::recursivePostorderDisplay(BinaryTreeNode* ptr)
{
    // TODO: Begin practice question 4
    if (ptr != NULL)
    {
        recursivePostorderDisplay(ptr->leftChildPtr);
        recursivePostorderDisplay(ptr->rightChildPtr);
        cout << ptr->item << " ";
    }
    // End question
}

// clear the subtree pointed by ptr
// use postorder traversal
void BinaryTree::clear(BinaryTreeNode*& ptr)
{
    if (ptr != NULL)
    {
        clear(ptr->leftChildPtr);
        clear(ptr->rightChildPtr);
        delete ptr;
        ptr = NULL;
    }
}

/*
    Purpose:
        Find an item from the tree

    Parameter:
        item - the item to look for in the tree

    Return:
        returns true if the item is found
 */
bool BinaryTree::find(TreeItemType item)
{
    BinaryTreeNode* ptr = recursiveFind(root, item);

    if (ptr == NULL)
        return false;
    else
        return true;
}

/*
    Purpose:
        Recursively find an item from a tree with 'ptr' as the root

    Parameter:
        ptr     - the root of the tree to be searched
        item    - the item to look for in the tree

    Return:
        returns the address of the node containing item if found
        returns NULL if item is NOT found
 */
BinaryTree::BinaryTreeNode* BinaryTree::recursiveFind(BinaryTreeNode* ptr,
  const TreeItemType& item)
{
    if (ptr == NULL || ptr->item == item)
        return ptr;
    else
    {   // Hint:
        // (1) Find the item on the left subtree
        // (2) If the item is found on the left subtree
        //     (1) Return the address of the node containing item
        // (3) Else
        //     (1)    Find the item on the right subtree
        //     (2)    If the item is found on the right subtree
        //            (1) Return the address of the node containing item
        //     (3)    Otherwise
        //            (1) Return NULL
        BinaryTreeNode* leftNode = recursiveFind(ptr->leftChildPtr, item);
            // first recursion
        if (leftNode != NULL)
            return leftNode;
        else
            return recursiveFind(ptr->rightChildPtr, item);
            // second recursion, if right is null then recursion will stop
    }

}

/*
    Purpose:
        Determine whether 'first' is in the subtree that has 'second'
        as the root item.

    Parameter:
        first   - the item to be searched
        second  - the root item of the subtree

    Return:
        returns true if 'first' is in the subtree that has 'second'
        as the root item.
        returns false otherwise.
 */
bool BinaryTree::isDescendant(TreeItemType first, TreeItemType second)
{
    // Hint:
    // recursiveFind() searches "second tree node ptr" from each left and right items
    // of the tree starting from the root
    BinaryTreeNode* secondNode = recursiveFind(root, second);

    if (secondNode != NULL)  // second node is found
    {
        // start from secondNode as root to find "first string item"
        // or in other words, check if 'first' has 'secondNode' as its root item
        BinaryTreeNode* firstNode = recursiveFind(secondNode, first);

        if (firstNode != NULL) // first node is found
            return true;
        else
            return false;
    }
    else  // secondNode == NULL, cannot find second node
        return false;
}

