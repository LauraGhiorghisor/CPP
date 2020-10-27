//
//  LinkedList.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 22/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.

/* All but the get and [] overloading methods from: https://nile.northampton.ac.uk/webapps/blackboard/content/listContent.jsp?course_id=_102575_1&content_id=_5625126_1
 */

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
class ListNode
{
public:
   T value;           // Node value
   ListNode<T> *next; // Pointer to the next node

   // Constructor
   ListNode (T nodeValue)
      { value = nodeValue;
        next = NULL;}
};

//*********************************************
// LinkedList class                           *
//*********************************************

template <class T>
class LinkedList
{
private:
   ListNode<T> *head;   // List head pointer

public:
   // Constructor
   LinkedList()
      { head = NULL; }
      
   // Destructor
   ~LinkedList();
      
   // Linked list operations
   void appendNode(T);
   void insertNode(T);
   void deleteNode(T);
   void displayList() const;
    
// Get method - returns T value at index
       T get(int pos) const;

//Operator overloading
        T operator [] (int i) const {
            return get(i);
        }
    };
#endif /* LinkedList_hpp */
