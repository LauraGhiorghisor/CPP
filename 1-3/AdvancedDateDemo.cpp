//
//  AdvancedDateDemo.cpp
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
//++
    Date incrementDate = Date(2020,12,12);
    Date prefixDate = ++incrementDate;
    cout<<"Date with prefix: "<<prefixDate.getDay()<<"; Regular date: "<<incrementDate.getDay()<<endl;
    Date postfixDate = incrementDate++;
    cout<<"Date with postfix: "<<postfixDate.getDay()<<"; Regular date: "<<incrementDate.getDay()<<endl;

//--
    Date decrementDate = Date(2020,12,12);
    Date prefixDate1 = --decrementDate;
    cout<<"Date with prefix: "<<prefixDate1.getDay()<<"; Regular date: "<<decrementDate.getDay()<<endl;
    Date postfixDate1 = decrementDate--;
    cout<<"Date with postfix: "<<postfixDate1.getDay()<<"; Regular date: "<<decrementDate.getDay()<<endl;

//Show difference -
    Date date1 = Date(2020,12,12);
    Date date2 = Date(2020,12,12);
    int diff = date1-date2;
    cout<<"The difference is "<<diff<<" days."<<endl;

// << and >>
        try
        {
        Date newDate;
        cin>>newDate;
        cout<<newDate<<endl;
        }
        catch (string exception)
        {
         cout<< exception<<endl;
        }




    return 0;
}
