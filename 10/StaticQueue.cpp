//
//  StaticQueue.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 22/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//
/*
 Base template from: https://nile.northampton.ac.uk/webapps/blackboard/content/listContent.jsp?course_id=_102575_1&content_id=_5625127_1
 */
#include "StaticQueue.hpp"
#include <iostream>
using namespace std;


//***************************************************************
// This constructor creates an empty queue of a specified size. *
//***************************************************************
template <class T>
StaticQueue<T>::StaticQueue(int s)
{
   queueArray = new T[s];
   queueSize = s;
   front = -1;
   rear = -1;
   numItems = 0;
}

//***************************************************************
// Copy constructor                                             *
//***************************************************************
template <class T>
StaticQueue<T>::StaticQueue(const StaticQueue &obj)
{
   // Allocate the queue array.
   queueArray = new T[obj.queueSize];
   
   // Copy the other object's attributes.
   queueSize = obj.queueSize;
   front = obj.front;
   rear = obj.rear;
   numItems = obj.numItems;
   
   // Copy the other object's queue array.
   for (int count = 0; count < obj.queueSize; count++)
      queueArray[count] = obj.queueArray[count];
}

//***************************************************************
// Destructor                                                   *
//***************************************************************
template <class T>
StaticQueue<T>::~StaticQueue()
{
   delete [] queueArray;
}

//***************************************************************
// Function enqueue inserts a value at the rear of the queue.   *
//***************************************************************
template <class T>
void StaticQueue<T>::enqueue(T item)
{
   if (isFull())
      cout << "The queue is full.\n";
   else
   {
      // Calculate the new rear position
      rear = (rear + 1) % queueSize;
      // Insert new item
      queueArray[rear] = item;
      // Update item count
      numItems++;
   }
}

//***************************************************************
// Function dequeue removes the value at the front of the queue *
// and copies t into num.                                       *
//***************************************************************
template <class T>
void StaticQueue<T>::dequeue(T &item)
{
   if (isEmpty())
      cout << "The queue is empty.\n";
   else
   {
      // Move front
      front = (front + 1) % queueSize;
      // Retrieve the front item
      item = queueArray[front];
      // Update item count
      numItems--;
   }
}

//***************************************************************
// isEmpty returns true if the queue is empty, otherwise false. *
//***************************************************************
template <class T>
bool StaticQueue<T>::isEmpty() const
{
   bool status;

   if (numItems)
      status = false;
   else
      status = true;

   return status;
}

//***************************************************************
// isFull returns true if the queue is full, otherwise false.   *
//***************************************************************
template <class T>
bool StaticQueue<T>::isFull() const
{
   bool status;

   if (numItems < queueSize)
      status = false;
   else
      status = true;

   return status;
}

//*****************************************************************
// clear sets the front and rear indices, and sets numItems to 0. *
//*****************************************************************
template <class T>
void StaticQueue<T>::clear()
{
   front = queueSize - 1;
   rear = queueSize - 1;
   numItems = 0;
}


// moveNthFront
template <class T>
void StaticQueue<T>::moveNthFront (int pos)
{
    StaticQueue<T> temp = StaticQueue<T>(numItems); // Stores the temporary queue (with the pos element removed)
    T value = 0; // Stores the value of element on pos.
        T pop; // Used for dequeue.
            
        int count = 1; // Counts the number of elements in the queue.
        while (!isEmpty()) // While end of queue not reached.
        {
            if (count == pos) // If the desired position has been reached.
            {
                dequeue(pop); // Remove the pos element.
                value = pop;  // Store the front of the queue.
            }
            else
            {
    //          Save all other elements and their number in the temporary queue.
                dequeue(pop);
                temp.enqueue(pop);
            }
            count++;
        }
    
    //   Queue is now empty.
    //   Add the element on position pos as first element
        enqueue(value);

    //   Move all the elements from the temporary queue back into the current queue, after the element on pos (which is now on first position).
        while(!temp.isEmpty())
        {
              temp.dequeue(pop);
              enqueue(pop);

        }
}
