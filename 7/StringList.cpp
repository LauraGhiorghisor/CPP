//
//  StringList.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 21/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//
/*
Regular linked list methods from:
https://nile.northampton.ac.uk/webapps/blackboard/content/listContent.jsp?course_id=_102575_1&content_id=_5625126_1
*/
#include "StringList.hpp"
#include <iostream>
using namespace std;


// Append Node
void StringList::appendNode(string s)
{
    ListNode *newNode;  // To point to a new node
    ListNode *nodePtr;  // To move through the list
    
// Allocate a new node and store s there.
    newNode = new ListNode;
    newNode->value = s;
    newNode->next = NULL;
    
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


// Insert node
void StringList::insertNode(string s)
{
    ListNode *newNode;             // A new node
       ListNode *nodePtr;             // To traverse the list
       ListNode *previousNode = NULL; // The previous node
    
       // Allocate a new node and store s there.
       newNode = new ListNode;
       newNode->value = s;
       
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
    
          // Skip all nodes whose value is less than s.
          while (nodePtr != NULL && nodePtr->value < s)
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



// Delete node
    void StringList::deleteNode(string s)
{
       ListNode *nodePtr;       // To traverse the list
    ListNode *previousNode = nullptr;  // To point to the previous node
    
       // If the list is empty, do nothing.
       if (!head)
          return;
       
       // Determine if the first node is the one.
       if (head->value == s)
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
          while (nodePtr != NULL && nodePtr->value != s)
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


// Display list
    void StringList::displayList() const
{
       ListNode *nodePtr;  // To move through the list
    
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
    


//Destructor
StringList::~StringList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

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



// Delete node at specified position
    void StringList::removeByPosition(string pos)
{
    ListNode *nodePtr;             // To traverse the list
    ListNode *previousNode = NULL; // The previous node
    try
    {
    int num = stoi(pos);
        
    if (!head)
    {
        cout<<"List is empty";
        return;
    }
    if (num==1)
    {
       nodePtr = head->next;
       delete head;
       head = nodePtr;
    }
    else  // Otherwise, delete node
    {
        // Position nodePtr at the head of list.
        nodePtr = head;
        
        // Initialize previousNode to NULL.
        previousNode = NULL;
        int i=1;
        // Skip all nodes whose value is less than num.
        while (nodePtr != NULL && i<num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
            i++;
        }
        if (nodePtr)
        {
           previousNode->next = nodePtr->next;
           delete nodePtr;
        
        }
    }
    }
    catch(invalid_argument const &e)
    {
        cout<< "Invalid"<<endl;
    }
    catch (out_of_range const & e)
    {
        cout<<"Out of range"<<endl;
    }
}


// Delete node at specified position - given as int
    void StringList::removeByPosition(int pos)
{
    ListNode *nodePtr;             // To traverse the list
    ListNode *previousNode = NULL; // The previous node
    
    if (!head)
    {
        cout<<"List is empty";
        return;
    }
    if (pos==1)
    {
       nodePtr = head->next;
       delete head;
       head = nodePtr;
    }
    else  // Otherwise, delete node
    {
        // Position nodePtr at the head of list.
        nodePtr = head;
        
        // Initialize previousNode to NULL.
        previousNode = NULL;
        int i=1;
        // Skip all nodes whose value is less than num.
        while (nodePtr != NULL && i<pos)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
            i++;
        }
        if (nodePtr)
        {
           previousNode->next = nodePtr->next;
           delete nodePtr;
        
        }
    }
    
}

// Add the elements in otherList to this list (no duplicates)
    void StringList::addAll(const StringList &otherList)
{
    ListNode *nodePtr;             // To traverse the otherList
    ListNode *searchPtr;           // To traverse the main list
    
    if (!otherList.head)
    {
        cout<<"Nothing to add!"<<endl;
        return;
    }
    else
    {
        // Position nodePtr at the head of list to be searched for.
              nodePtr = otherList.head;
        
              // Navigate through the list
              while (nodePtr != NULL)
              {
                  //Look for the current node value in the main list. If not found, add it.
                  bool found = false;
                  //Position the search node at the head of the current/main list.
                  searchPtr = head;
                  while (searchPtr != NULL && found != true)
                  {
                      if (nodePtr->value == searchPtr->value) found = true;
                      searchPtr = searchPtr->next;
                  }
                  // If the element is not in the main list, insert it.
                  if (found == false) insertNode(nodePtr->value);
                  nodePtr = nodePtr->next;
              }
    }
}


// Remove all the elements in otherList from this list
    void StringList::removeAll(const StringList &otherList)
{
    ListNode *nodePtr;             // To traverse the otherList
    ListNode *searchPtr;           // To traverse the main list
    ListNode *previousNode = NULL; // To store previous node value for traversing
    
    if (!otherList.head)
    {
        cout<<"Nothing to remove!"<<endl;
        return;
    }
    else
    {
        // Position nodePtr at the head of list to be searched for.
              nodePtr = otherList.head;
        
              // Navigate through the list
              while (nodePtr != NULL)
              {
                  //Look for the current node value in the main list. If not found, add it.
                  bool found = false;
                  //Position the search node at the head of the current/main list.
                  searchPtr = head;
                  while (searchPtr != NULL && found != true)
                  {
                      if (nodePtr->value == searchPtr->value)
                      {
                        // If element is found, delete it and exit the loop.
                          found = true;
                          previousNode->next = searchPtr->next;
                          delete searchPtr;
                      }
                      else
                    // Keep searching
                      {
                          previousNode = searchPtr;
                          searchPtr = searchPtr->next;
                      }
                  }
                nodePtr = nodePtr->next;
              }
    }
}


// Retain the elements in this list if they are also in the otherList.
    void StringList::retainAll(const StringList &otherList)
{
       ListNode *nodePtr;             // To traverse the main list
       ListNode *searchPtr;           // To traverse the other list
       ListNode *previousNode = NULL; // To store previous node value for traversing
       
       if (!otherList.head)
       {
           cout<<"List is empty!"<<endl;
           return;
       }
       else
       {
           // Position nodePtr at the head of list to traverse it.
                 nodePtr = head;
           
                 // Navigate through the list
                 while (nodePtr != NULL)
                 {
                     //Look for the current node value in the other list.
                     bool found = false;
                     //Position the search node at the head of the other list.
                     searchPtr = otherList.head;
                     while (searchPtr != NULL && found != true)
                     {
                         // If the value is found, exit the loop.
                         if (nodePtr->value == searchPtr->value) found = true;
                         searchPtr = searchPtr->next;
                     }
                     // If the value was not found, delete the element from the main list.
                         if (!found)
                         {
                             deleteNode(nodePtr->value);
                             nodePtr = nodePtr->next;
                             
                         }
                     // If the value is found, the element is kept. Move unto the next element.
                         else
                         {
                            previousNode = nodePtr;
                            nodePtr = nodePtr->next;
                         }
                 }
       }
}
