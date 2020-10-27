//
//  StaticQueue.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 22/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//
/*
Base template from: https://nile.northampton.ac.uk/webapps/blackboard/content/listContent.jsp?course_id=_102575_1&content_id=_5625127_1
*/
#ifndef StaticQueue_hpp
#define StaticQueue_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


// Stack template
template <class T>
class StaticQueue
{
private:
   T *queueArray;     // Points to the queue array
   int queueSize;    // The queue size
   int front;        // Subscript of the queue front
   int rear;         // Subscript of the queue rear
   int numItems;     // Number of items in the queue
public:
   // Constructor
   StaticQueue(int);
   
   // Copy constructor
   StaticQueue(const StaticQueue &);
   
   // Destructor
   ~StaticQueue();

   // Queue operations
   void enqueue(T);
   void dequeue(T &);
   bool isEmpty() const;
   bool isFull() const;
   void clear();
// moveNthFront
    void moveNthFront (int);
};

#endif /* StaticQueue_hpp */
