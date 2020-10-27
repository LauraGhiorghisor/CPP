//
//  StringStack.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 22/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

/*
 Regular stack methods from:
 https://nile.northampton.ac.uk/webapps/blackboard/content/listContent.jsp?course_id=_102575_1&content_id=_5625127_1
*/

#include "StringStack.hpp"
#include <iostream>
using namespace std;


//***********************************************
// Constructor                                  *
// This constructor creates an empty stack. The *
// size parameter is the size of the stack.     *
//***********************************************

StringStack::StringStack(int size)
{
   stackArray = new char[size];
   stackSize = size;
   top = -1;
}

//***********************************************
// Copy constructor                             *
//***********************************************

StringStack::StringStack(const StringStack &obj)
{
   // Create the stack array.
   if (obj.stackSize > 0)
      stackArray = new char[obj.stackSize];
   else
      stackArray = NULL;

   // Copy the stackSize attribute.
   stackSize = obj.stackSize;

   // Copy the stack contents.
   for (int count = 0; count < stackSize; count++)
      stackArray[count] = obj.stackArray[count];

   // Set the top of the stack.
   top = obj.top;
}

//***********************************************
// Destructor                                   *
//***********************************************

StringStack::~StringStack()
{
   delete [] stackArray;
}

//*************************************************
// Member function push pushes the argument onto  *
// the stack.                                     *
//*************************************************

void StringStack::push(char c)
{
   if (isFull())
   {
      cout << "The stack is full.\n";
   }
   else
   {
      top++;
      stackArray[top] = c;
   }
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************

void StringStack::pop(char &c)
{
   if (isEmpty())
   {
//      cout << "The stack is empty.\n";
   }
   else
   {
      c = stackArray[top];
      top--;
   }
}

//***************************************************
// Member function isFull returns true if the stack *
// is full, or false otherwise.                     *
//***************************************************

bool StringStack::isFull() const
{
   bool status;

   if (top == stackSize - 1)
      status = true;
   else
      status = false;

   return status;
}

//****************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************

bool StringStack::isEmpty() const
{
   bool status;

   if (top == -1)
       status = true;
   else
      status = false;

   return status;
}
