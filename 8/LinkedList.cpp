//
//  LinkedList.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 22/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.

/* Regular methods (add, insert, delete, destructor) from: https://nile.northampton.ac.uk/webapps/blackboard/content/listContent.jsp?course_id=_102575_1&content_id=_5625126_1
*/
#include "LinkedList.hpp"
#include <iostream>
using namespace std;



//**************************************************
// appendNode appends a node containing the value  *
// pased into newValue, to the end of the list.    *
//**************************************************

template <class T>
void LinkedList<T>::appendNode(T newValue)
{
   ListNode<T> *newNode;  // To point to a new node
   ListNode<T> *nodePtr;  // To move through the list

   // Allocate a new node and store newValue there.
   newNode = new ListNode<T>(newValue);

   // If there are no nodes in the list
   // make newNode the first node.
   if (!head)
      head = newNode;
   else  // Otherwise, insert newNode at end.
   {
      // Initialize nodePtr to head of list.
      nodePtr = head;

      // Find the last node in the list.
      while (nodePtr->next)
         nodePtr = nodePtr->next;

      // Insert newNode as the last node.
      nodePtr->next = newNode;
   }
}

//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head.          *
//**************************************************

template <class T>
void LinkedList<T>::displayList() const
{
   ListNode<T> *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      cout << nodePtr->value << endl;

      // Move to the next node.
      nodePtr = nodePtr->next;
   }
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

template <class T>
void LinkedList<T>::insertNode(T newValue)
{
   ListNode<T> *newNode;             // A new node
   ListNode<T> *nodePtr;             // To traverse the list
   ListNode<T> *previousNode = NULL; // The previous node

   // Allocate a new node and store newValue there.
   newNode = new ListNode<T>(newValue);
   
   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
      newNode->next = NULL;
   }
   else  // Otherwise, insert newNode
   {
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to NULL.
      previousNode = NULL;

      // Skip all nodes whose value is less than newValue.
      while (nodePtr != NULL && nodePtr->value < newValue)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
      if (previousNode == NULL)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise insert after the previous node.
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
   ListNode<T> *nodePtr;       // To traverse the list
   ListNode<T> *previousNode;  // To point to the previous node

   // If the list is empty, do nothing.
   if (!head)
      return;
   
   // Determine if the first node is the one.
   if (head->value == searchValue)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is
      // not equal to num.
      while (nodePtr != NULL && nodePtr->value != searchValue)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list,
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
   }
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template <class T>
LinkedList<T>::~LinkedList()
{
   ListNode<T> *nodePtr;   // To traverse the list
   ListNode<T> *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != NULL)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}

// Get method
template <class T>
T LinkedList<T>::get(int pos) const
{
   ListNode<T> *nodePtr;             // To traverse the list
   ListNode<T> *previousNode = NULL; // The previous node
   // If there are no nodes in the list, throw out of bounds exception.
   if (!head)
   {
       string exception =  "Out of bounds exception\n";
       throw exception;
   }
   else  // Otherwise, insert newNode
   {
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to NULL.
      previousNode = NULL;
     // Initialize index to 0.
       int i = 0;
       
      // Skip all nodes until NULL or position found.
      while (nodePtr != NULL && i<=pos)
      {
         previousNode = nodePtr;
          i++;
         nodePtr = nodePtr->next;
      }
       //If traversing the list has not yet found the position.
      if (!nodePtr && i<=pos)
       {
           string exception =  "Out of bounds exception\n";
           throw exception;
       }
       // Return previous node value.
       else return previousNode->value;
   }
}

