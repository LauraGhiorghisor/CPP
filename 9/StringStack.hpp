//
//  StringStack.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 22/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#ifndef StringStack_hpp
#define StringStack_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


class StringStack
{
private:
   char *stackArray;  // Pointer to the stack array
   char stackSize;    // The stack size
   char top;          // Indicates the top of the stack

public:
   // Constructor
   StringStack(int);

   // Copy constructor
   StringStack(const StringStack &);

   // Destructor
   ~StringStack();
   
   // Stack operations
   void push(char);
   void pop(char &);
   bool isFull() const;
   bool isEmpty() const;
    int size() const {return stackSize;}
};
#endif /* StringStack_hpp */
