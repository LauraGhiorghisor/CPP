//
//  StringList.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 21/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//
/*
 Regular linked list methods from:
 https://nile.northampton.ac.uk/webapps/blackboard/content/listContent.jsp?course_id=_102575_1&content_id=_5625126_1
 */
#ifndef StringList_hpp
#define StringList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class StringList
{
private:
// Declare a structure for the list
   struct ListNode
   {
      string value;           // The node value
      struct ListNode *next;  // Pointer to next node
   };

   ListNode *head;            // List head pointer

public:
// Constructor
   StringList()
      { head = NULL; }

// Destructor
    ~StringList();
    
// Linked list operations
   void appendNode(string);
   void insertNode(string);
   void deleteNode(string);
   void displayList() const;
    
// Delete node at specified position
   void removeByPosition(string pos);
// Delete node at specified position - given as int
   void removeByPosition(int pos);
// Add the elements in otherList to this list (no duplicates)
   void addAll(const StringList &otherList);
// Remove all the elements in otherList from this list
   void removeAll(const StringList &otherList);
// Retain the elements in this list if they are also in the otherList.
   void retainAll(const StringList &otherList);
};
#endif /* StringList_hpp */
