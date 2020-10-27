//
//  DynamicQueue.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 22/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//
/*
Base template from: https://nile.northampton.ac.uk/webapps/blackboard/content/listContent.jsp?course_id=_102575_1&content_id=_5625127_1
*/

#include "DynamicQueue.hpp"
#include <iostream>
using namespace std;


//********************************************
// The constructor creates an empty queue.   *
//********************************************
template <class T>
DynamicQueue<T>::DynamicQueue()
{
   front = NULL;
   rear = NULL;
   numItems = 0;
}

//********************************************
// Destructor                                *
//********************************************
template <class T>
DynamicQueue<T>::~DynamicQueue()
{
   clear();
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
template <class T>
void DynamicQueue<T>::enqueue(T item)
{
   QueueNode *newNode;

   // Create a new node and store num there.
   newNode = new QueueNode;
   newNode->value = item;
   newNode->next = NULL;

   // Adjust front and rear as necessary.
   if (isEmpty())
   {
      front = newNode;
      rear = newNode;
   }
   else
   {
      rear->next = newNode;
      rear = newNode;
   }

   // Update numItems.
   numItems++;
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
template <class T>
void DynamicQueue<T>::dequeue(T &item)
{
   QueueNode *temp;

   if (isEmpty())
   {
      cout << "The queue is empty.\n";
   }
   else
   {
      // Save the front node value in num.
      item = front->value;

      // Remove the front node and delete it.
      temp = front;
      front = front->next;
      delete temp;

      // Update numItems.
      numItems--;
   }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
template <class T>
bool DynamicQueue<T>::isEmpty() const
{
    bool status;

    if (numItems > 0)
       status = false;
    else
       status = true;
    return status;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************
template <class T>
void DynamicQueue<T>::clear()
{
    T value;   // Dummy variable for dequeue

    while(!isEmpty())
       dequeue(value);
}

template <class T>
void DynamicQueue<T>::moveNthFront(int pos)
{
        DynamicQueue<T> temp = DynamicQueue<T>(); // Stores the temporary queue (with the pos element removed)
       T value = 0; // Stores the value of element on pos.
           T pop; // Used for dequeue.
               
           int count = 1; // Counts the number of elements in the queue.
           while (!isEmpty()) // While end of queue not reached.
           {
               if (count == pos) // If the desired position has been reached.
               {
                   dequeue(pop); // Remove the pos element.
                   value = pop;  // Store the popped value.
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

