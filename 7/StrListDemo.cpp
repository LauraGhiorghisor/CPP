 //
 //  StrListDemo.cpp
 //  SE2
 //
 //  Created by Laura Ghiorghisor on 21/04/2020.
 //  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
 //

 #include <stdio.h>

 #include "StringList.hpp"
 #include <iostream>
 using namespace std;

 int main()
 {

    StringList list1;
 //  Append new values
    string string1 = "str1";
    string string2 = "str2";
    string string3 = "str3";
    string string4 = "str4";
    string string5 = "str5";
    string string6 = "str6";
    list1.appendNode(string1);
    list1.appendNode(string3);
    list1.appendNode(string4);
    list1.appendNode(string6);

 //  Display current list
    cout<<"List after appends:"<<endl;
    list1.displayList();
    cout<<endl;

 //  Insert new nodes
    list1.insertNode(string2);
    list1.insertNode(string5);

 //  Display current list
    cout<<"List after inserts:"<<endl;
    list1.displayList();
    cout<<endl;

 //    Delete
    cout<<endl<<"List after deleting - string:"<<endl;
    list1.deleteNode("str5");
 //  Display current list
    list1.displayList();
    cout<<endl;

//    Remove - pos given as string
    cout<<endl<<"List after removing by position with string:"<<endl;
    list1.removeByPosition("3");
//  Display current list
    list1.displayList();
    cout<<endl;

//    Remove - pos given as int
    cout<<endl<<"List after removing by position with int :"<<endl;
    list1.removeByPosition(4);
//  Display current list
    list1.displayList();
    cout<<endl;


 //  Delete head
    list1.removeByPosition("1");
 //  Display current list
    cout<<endl<<"List after deleting head:"<<endl;
    list1.displayList();
    cout<<endl;

 //  addAll()

 //  Create a new empty list
    StringList emptyList;
    cout<<"List after adding empty list:"<<endl;
    list1.addAll(emptyList);// Nothing to add!
    list1.displayList(); //Same list
    cout<<endl;

 //  Create New list to add.
    string string7 = "str7";
    string string8 = "str8";
    string string9 = "str9";
    string string10 = "str10";

    StringList addList = StringList();
    addList.appendNode(string7);
    addList.appendNode(string8);
    addList.appendNode(string9);
    addList.appendNode(string10);
    addList.appendNode(string1);
    addList.appendNode(string2);
    addList.appendNode(string3);
 //  Add the new list
    list1.addAll(addList);
    cout<<"List after adding another list:"<<endl;
    list1.displayList();
    cout<<endl;

 // Remove all
 // Create list to be removed;
    StringList removeList = StringList();
    removeList.appendNode(string9);
    removeList.appendNode(string10);
    removeList.appendNode(string6);
    list1.removeAll(removeList);
 //  Display list after removal
    cout<<"List after removing:"<<endl;
    list1.displayList();
    cout<<endl;

 // Retain all
 // Empty list
    StringList emptyRetainList = StringList();
    cout<<"List after retaining with empty list:"<<endl;
    list1.retainAll(emptyRetainList);
    list1.displayList();
    cout<<endl;

 // Create list to be retained.
    StringList retainList = StringList();
    retainList.appendNode(string1);
    retainList.appendNode(string2);
    retainList.appendNode(string3);
    retainList.appendNode(string4);
    retainList.appendNode(string5);
    retainList.appendNode(string8);
    list1.retainAll(retainList);
 //  Display list after retaing
     cout<<"List after retaining :"<<endl;
     list1.displayList();
     cout<<endl;

 // Do not retain head
    StringList retainList1 = StringList();
    retainList1.appendNode(string2);
    retainList1.appendNode(string3);
    retainList1.appendNode(string4);
    list1.retainAll(retainList1);
 // Display list after retaing
    cout<<"List after retain + deleting its head:"<<endl;
    list1.displayList();
    cout<<endl;
    return 0;
 }
