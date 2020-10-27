//
//  QueueMoveOperations.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 22/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//
/*
 Part of the solution was inspired by:
 http://www.cplusplus.com/forum/beginner/147435/
 */
#include "StaticQueue.hpp"
#include "DynamicQueue.hpp"
#include "StaticQueue.cpp"
#include "DynamicQueue.cpp"
#include <stdio.h>
#include <iostream>
using namespace std;

int main ()
{
//  User selects the position for the shift.
    int pos;
    cout<<"Please enter the position you'd like to move:"<<endl;
    cin>>pos;

//  Used for dequeuing.
    int pop;
//  Size of the queues.
    int size = 6;

//  STATIC QUEUE
    cout<<"STATIC QUEUE: "<<endl;
//  Create a static queue.
    StaticQueue<int> sQueue = StaticQueue<int>(size);
    sQueue.enqueue(5);
    sQueue.enqueue(11);
    sQueue.enqueue(34);
    sQueue.enqueue(67);
    sQueue.enqueue(43);
    sQueue.enqueue(55);

//  Run the method
    sQueue.moveNthFront(pos);
//  Print the queue.
    for (int i=1; i<=size; i++)
    {
        sQueue.dequeue(pop);
        cout<<pop<<endl;

    }

//      DYNAMIC QUEUE
        cout<<"DYNAMIC QUEUE: "<<endl;
//      Create a dynamic queue.
        DynamicQueue<int> dQueue = DynamicQueue<int>();
        dQueue.enqueue(5);
        dQueue.enqueue(11);
        dQueue.enqueue(34);
        dQueue.enqueue(67);
        dQueue.enqueue(43);
        dQueue.enqueue(55);

//      Run the method.
        dQueue.moveNthFront(pos);
//      Print the queue.
        for (int i=1; i<=size; i++)
        {
            dQueue.dequeue(pop);
            cout<<pop<<endl;
        }

    return 0;
}
