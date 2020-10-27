//
//  DateDemo.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 20/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include "Date.hpp"
#include <iostream>

using namespace std;

int main () {
    int year, month, day;
    bool Exception = true;
    int version;
    
    while (Exception)
    {
        Exception = false;
        try
        {
            cout<<"Enter 1 if you'd like tyour date to be in the format dd/mm/yyy; \nEnter 2 if you'd like your date to be in the format Month dd, yyyy; \nEnter 3 if you'd like your date to be in the format yy month yyy.\nEnter:";
            cin>> version;
            cout<<endl<<"Enter year : ";
            cin>> year;
            cout<<"Enter month : ";
            cin>>month;
            cout<<"Enter day : ";
            cin>>day;
            Date date = Date(year, month, day);
/*
 Based on the user selection, generates the desired date via the switch. If the
 selection is not valid, sets the flag so that it goes into yet another cycle of the
 while loop.
*/
            switch (version) {
                case 1:
                    date.printVersion1();
                    break;
                case 2:
                date.printVersion2();
                    break;
                case 3:
                date.printVersion3();
                break;
                default:
                    {
                        cout<<"Not a valid selection, please try again!"<<endl;
                        Exception = true;
                    }
                    break;
            }
        }
//Print the thrown exception. Also sets the flag boolean to true.
        catch(string exception)
        {
            cout<< exception<<endl;
            Exception = true;
            
        }
//Exit the while if no exception is found.
        if (Exception == false) break;
    }
    
    return 0;
}
