//
//  LinkedListOps.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 22/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include <stdio.h>
#include "StringList.hpp"
#include <iostream>
using namespace std;


void downsize (StringList &list)
{
    list.removeByPosition(2);
}

StringList merge (StringList &list1, StringList &list2)
{
    StringList final;

    if (list1.isEmpty()) final = list2;
    else if (list2.isEmpty()) final = list1;
    else
    {
      if (list1.size() <list2.size())
      {
          for (int i=1; i<=list1.size(); i++)
          {
            final.appendNode(list1.getValueAtPosition(i));
            final.appendNode(list2.getValueAtPosition(i));
          }
        final.addAll(list2);
    }
        else
        {
            for (int i=1; i<=list2.size(); i++)
              {
                final.appendNode(list1.getValueAtPosition(i));
                final.appendNode(list2.getValueAtPosition(i));
              }
            final.addAll(list1);
        }
    }
      return final;
}

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
        list1.appendNode(string2);
        list1.appendNode(string3);
        list1.appendNode(string4);
        list1.appendNode(string5);
        list1.appendNode(string6);

//  Display current list
        cout<<"List after appends:"<<endl;
        list1.displayList();
        cout<<endl;

//    Downsize
        downsize(list1);
//  Display current list
        cout<<"List after downsizing:"<<endl;
        list1.displayList();
        cout<<endl;

//    TEST new methods
//    Get position
        cout<<"Element at position 1 is : "<<list1.getValueAtPosition(4)<<endl;
//    Is empty
        if (list1.isEmpty()) cout<<"List is empty."; else cout<<"List is not empty."<<endl;
//    Size
        cout<<"The size of the list is "<<list1.size()<<endl;


        StringList list2;
    //  Append new values
        string string7 = "str7";
        string string8 = "str8";
        string string9 = "str9";
        string string10 = "str10";
        string string11 = "str91";
        string string12 = "str92";

        list2.appendNode(string7);
        list2.appendNode(string8);
        list2.appendNode(string9);
        list2.appendNode(string10);
        list2.appendNode(string11);
        list2.appendNode(string12);
            
    StringList final = merge(list1, list2);
    cout<<endl<<"Merged list is :"<<endl;
    final.displayList();
    cout<<endl;



    return 0;

}
