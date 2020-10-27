//
//  DynamicQueue.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 22/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//
/*
Base template from: https://nile.northampton.ac.uk/webapps/blackboard/content/listContent.jsp?course_id=_102575_1&content_id=_5625127_1
*/

#ifndef DynamicQueue_hpp
#define DynamicQueue_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


// DynamicQueue template
template <class T>
class DynamicQueue
{
private:
   // Structure for the queue nodes
   struct QueueNode
   {
      T value;       // Value in a node
      QueueNode *next; // Pointer to the next node
   };

   QueueNode *front;  // The front of the queue
   QueueNode *rear;   // The rear of the queue
   int numItems;      // Number of items in the queue
public:
   // Constructor
   DynamicQueue();

   // Destructor
   ~DynamicQueue();

   // Queue operations
   void enqueue(T);
   void dequeue(T &);
   bool isEmpty() const;
   bool isFull() const;
   void clear();
    
    
// moveNthFront
   void moveNthFront (int);
};

#endif /* DynamicQueue_hpp */
