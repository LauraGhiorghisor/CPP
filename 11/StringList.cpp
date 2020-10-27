//
//  StringList.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 23/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "StringList.hpp"
using namespace std;


// Get value at position
string StringList::getValueAtPosition(int pos) const
{
        ListNode *nodePtr;       // To traverse the list
        ListNode *previousNode = nullptr;  // To point to the previous node
        
           // If the list is empty, do nothing.
           if (!head)
           {
               string exception = "Out of bounds exception";
               throw exception;
           }
              // Initialize nodePtr to head of list
              nodePtr = head;
         int i = 0;
              
             // Skip all nodes until NULL or position found.
             while (nodePtr != NULL && i<pos)
             {
                previousNode = nodePtr;
                 i++;
                nodePtr = nodePtr->next;
             }
              //If traversing the list has not yet found the position.
             if (!nodePtr && i<pos)
              {
                  string exception =  "Out of bounds exception\n";
                  throw exception;
              }
              // Return previous node value.
              else return previousNode->value;
    }
    
bool StringList::isEmpty() const
{
    if (!head) return true;
    else return false;
}

int StringList::size() const
{
    ListNode *nodePtr;       // To traverse the list

    // If the list is empty, size is 0.
    if (!head) return 0;

    // Initialize nodePtr to head of list
    nodePtr = head;
    
    int size = 0;
    // Traverse nodes
    while (nodePtr != NULL)
    {
        nodePtr = nodePtr->next;
        size++;
    }
           
    return size;
}
