//
//  ExceptionDateDemo.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 20/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include <stdio.h>
#include "Date.hpp"
#include <iostream>

using namespace std;

int main()
{
    try {
        Date date1 = Date(12,12,12,true); //no exception
        cout<<date1;
    } catch (InvalidDay exception) {
        cout<<exception.getMessage()<<endl;
    }
    try {
        Date date1 = Date(12,12,100,true); //invalid day
        cout<<date1;
    } catch (InvalidDay exception) {
        cout<<exception.getMessage()<<endl;
    }
    try {
        Date date1 = Date(12,45,12,true); //invalid month
        cout<<date1;
    } catch (InvalidMonth exception) {
        cout<<exception.getMessage()<<endl;
    }
    try {
        Date date1 = Date(-12,12,12,true); //invalid year
        cout<<date1;
    } catch (InvalidYear exception) {
        cout<<exception.getMessage()<<endl;
    }
}
