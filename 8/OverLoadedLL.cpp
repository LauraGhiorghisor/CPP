 //
 //  OverLoadedLL.cpp
 //  SE2
 //
 //  Created by Laura Ghiorghisor on 22/04/2020.
 //  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
 //

 #include <stdio.h>
 #include <iostream>
 #include "LinkedList.hpp"
 #include "LinkedList.cpp"
 using namespace std;

 int main()
 {
 //  INTEGER list
    cout<<"INTEGER list"<<endl;
 LinkedList<int> list1 = LinkedList<int>();
 //  Append new values
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;
    list1.appendNode(n1);
    list1.appendNode(n2);
    list1.appendNode(n3);
    list1.appendNode(n4);
 //  Display list using regular method
    cout<<"List with regular method :"<<endl;
    list1.displayList();
    cout<<endl;
   
 //  Display list using get() method
    cout<<"List with get() method :"<<endl;
    for (int i=0; i<4; i++)
        cout<<list1.get(i)<<" ";
    cout<<endl;
   
 //  Display list using overloaded []
    cout<<endl<<"List with [] :"<<endl;
    for (int i=0; i<4; i++)
    cout<<list1[i]<<" ";
    cout<<endl;
   
 //  STRING list
    cout<<endl<<"STRING list"<<endl;
    LinkedList<string> list2 = LinkedList<string>();
    //  Append new values
        string s1 = "1";
        string s2 = "2";
        string s3 = "3";
        string s4 = "4";
        list2.appendNode(s1);
        list2.appendNode(s2);
        list2.appendNode(s3);
        list2.appendNode(s4);
    //  Display list using regular method
        cout<<"List with regular method :"<<endl;
        list2.displayList();
        cout<<endl;
       
    //  Display list using get() method
        cout<<"List with get() method :"<<endl;
        for (int i=0; i<4; i++)
            cout<<list2.get(i)<<" ";
        cout<<endl;
       
    //  Display list using overloaded []
        cout<<endl<<"List with [] :"<<endl;
        for (int i=0; i<4; i++)
        cout<<list2[i]<<" ";
        cout<<endl<<endl;
   
 // Out of bounds exception for index > size
    try
    {
        cout<<list1[5];
    }
    catch (string exception)
    {
        cout<<exception;
    }
 
   
 // Out of bounds exception for empty list
    try
    {
        LinkedList<string> emptyList = LinkedList<string>();
        cout<<emptyList[0];
    }
    catch (string exception)
    {
        cout<<exception;
    }
  
   
    return 0;
 }
