//
//  NumDays.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 21/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include "NumDays.hpp"
#include <iostream>

using namespace std;


//Used to normalize the hours and days.
void NumDays::updateDays(){
    days = hours/8;
}


//- operator
NumDays NumDays::operator - (const NumDays &right)
{
    NumDays temp;
    temp.hours = hours - right.hours;
    temp.updateDays();
    return temp;
}

//+ operator
NumDays NumDays::operator + (const NumDays &right)
{
    NumDays temp;
    temp.hours = hours + right.hours;
    temp.updateDays();
    return temp;
}

//Postfix ++
NumDays NumDays::operator ++ (int)
{
    NumDays temp(hours);
    hours++;
    updateDays();
    return temp;
}

//Prefix ++
NumDays NumDays::operator ++ ()
{
    ++hours;
    updateDays();
    return *this;
}

//Postfix --
NumDays NumDays::operator -- (int)
{
    NumDays temp(hours);
    hours--;
    updateDays();
    return temp;
}

//Prefix --
NumDays NumDays::operator -- ()
{
    --hours;
    updateDays();
    return *this;
}

     
