//
//  BinaryTree.hpp
//  Assessment2
//
//  Created by Laura Ghiorghisor on 23/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


template <class T>
class BinaryTree
{
private:
   struct TreeNode
   {
      T value;
      TreeNode *left;
      TreeNode *right;
   };

   TreeNode *root;
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(T, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *);
   void displayPreOrder(TreeNode *);
   void displayPostOrder(TreeNode *);
   int countNodes(TreeNode *&);
    
   int countLeaves(TreeNode *&);
   int height(TreeNode *&);
   void displayPreOrderAndInsert(TreeNode *, BinaryTree<T> &);
   void displayPostOrderAndInsert(TreeNode *, BinaryTree<T> &);

public:
   BinaryTree()      // Constructor
      { root = NULL; }
   ~BinaryTree()  // Destructor
      { destroySubTree(root); }
   void insertNode(T);
   bool searchNode(T);
   void remove(T);
   void displayInOrder()
      {  displayInOrder(root); }
   void displayPreOrder()
      {  displayPreOrder(root); }
   void displayPostOrder()
      {  displayPostOrder(root); }
   int numNodes();
    
   int countLeaves();
   int height();
   void publicDisplayPreOrderAndInsert(BinaryTree<T> &tree ){
        displayPreOrderAndInsert(root, tree);
    };
   void publicDisplayPostOrderAndInsert(BinaryTree<T> &tree){
        displayPostOrderAndInsert(root, tree);
    };
};

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == NULL)
      nodePtr = newNode; // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);  // Search the left branch
   else
      insert(nodePtr->right, newNode); // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

template <class T>
void BinaryTree<T>::insertNode(T num)
{
   TreeNode *newNode;      // Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->value = num;
   newNode->left = newNode->right = NULL;
   // Insert the node.
   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
//   if (nodePtr->left)
//      destroySubTree(nodePtr->left);
//   if (nodePtr->right)
//      destroySubTree(nodePtr->right);
//   delete nodePtr;
}
   
//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

template <class T>
bool BinaryTree<T>::searchNode(T num)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value == num)
         return true;
      else if (num < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

template <class T>
void BinaryTree<T>::remove(T num)
{
   deleteNode(num, root);
}


//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

template <class T>
void BinaryTree<T>::deleteNode(T num, TreeNode *&nodePtr)
{
   if (num < nodePtr->value)
      deleteNode(num, nodePtr->left);
   else if (num > nodePtr->value)
      deleteNode(num, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
   TreeNode *tempNodePtr;  // Temporary pointer, used
                           // in reattaching the left
                           // subtree.

   if (nodePtr == NULL)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left; // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right; // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);
      displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

//****************************************************************
// The numNodes function returns the number of nodes in the tree.*
//****************************************************************

template <class T>
int BinaryTree<T>::numNodes()
{
    return countNodes(root);
}

//****************************************************************
// The countNodes function uses recursion to count the nodes in  *
// the tree. This function is called by the public member        *
// function numNodes.                                            *
//****************************************************************

template <class T>
int  BinaryTree<T>::countNodes(TreeNode *&nodePtr)
{
    if (nodePtr == NULL)
        return 0;
    else
        return 1 + countNodes(nodePtr->left) + countNodes(nodePtr->right);
}

//Post order + insert
template <class T>
void BinaryTree<T>::displayPostOrderAndInsert(TreeNode *nodePtr, BinaryTree<T> &other)
{
   if (nodePtr)
   {
      displayPostOrderAndInsert(nodePtr->left, other);
      displayPostOrderAndInsert(nodePtr->right, other);
      cout << nodePtr->value << endl;
       other.insertNode(nodePtr->value);
   }
}

//Pre order + insert
template <class T>
void BinaryTree<T>::displayPreOrderAndInsert(TreeNode *nodePtr, BinaryTree<T> &other)
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      other.insertNode(nodePtr->value);
      displayPreOrderAndInsert(nodePtr->left, other);
      displayPreOrderAndInsert(nodePtr->right, other);
   }
}

//Height
template <class T>
int BinaryTree<T>::height()
{
    return height(root);
}

template <class T>
int  BinaryTree<T>::height(TreeNode *&nodePtr)
{
    if (nodePtr == NULL)
        return 0;
    else
    {
        return max(height(nodePtr->left), height(nodePtr->right)) +1;
    }
}


// Number of leaves
template <class T>
int BinaryTree<T>::countLeaves()
{
    return countLeaves(root);
}

template <class T>
int  BinaryTree<T>::countLeaves(TreeNode *&nodePtr)
{
    if (nodePtr == NULL)
        return 0;
    else
    {
        if (nodePtr->left == NULL && nodePtr->right == NULL) return 1;
        else return countLeaves(nodePtr->left) + countLeaves(nodePtr->right);
        
    }
}
#endif /* BinaryTree_hpp */
