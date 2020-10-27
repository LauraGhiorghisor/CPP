//
//  Date.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 20/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include <stdio.h>
#include "Date.hpp"
#include <iostream>

using namespace std;



//Constructor 1 - Exercise 1
Date::Date (int y, int m, int d)
{
    string exception;
    if (d<1 || d>31 )
    {
        exception = "The day you have entered is not valid!";
        throw exception;
    }
    if (m<1 || m>12)
    {
        exception = "The month you have entered is not valid!";
        throw exception;
    }
    if (y<0)
    {
        exception = "The year you have entered is not valid!";
        throw exception;
    }
    
    year = y;
    month = m;
    day = d;
}



/* Constructor 2 - overloaded constructor.
Uses a boolean  value to distinguish it from the previous one.
Throws class defined exceptions - for Exercise 3.
*/

Date::Date (int y, int m, int d, bool b)
{
//    string exception;
    if (d<1 || d>31 )
    {
        throw InvalidDay("The day you have entered is not valid!");
    }
    if (m<1 || m>12)
    {
        throw InvalidMonth("The month you have entered is not valid!");
    }
    if (y<0)
    {
        throw InvalidYear("The year you have entered is not valid!");
    }
    
    year = y;
    month = m;
    day = d;
    b = true;
}


//Exercise 1

//Method for the first version
void Date::printVersion1(){
    cout<<this->getDay()<<"/"<< this->getMonth() << "/"<< this->getYear()<<endl;
}

//Method for the second version
void Date::printVersion2()
{
    string months [12] = { "January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month = this->getMonth()-1;
    cout<<months[month]<<" "<< this->getDay() << ", "<< this->getYear()<<endl;
}

//Method for the second version
void Date::printVersion3()
{
     string months [12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month = this->getMonth()-1;
    cout<<this->getDay()<<" "<< months[month] << " "<< this->getYear()<<endl;
}


//Exercise 2

//Used to normalize the Date.
void Date::simplify(){
    int months [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    switch (month) {
        case 1:
            if (day==0){year--; day=31; month = 12;}
            break;
        case 12:
            if (day==32) {month=1; day=1; year++;}
        break;
        default: if (day==months[month-1]+1) {month++; day=1;}
            if (day==0) {month--; day=months[month-2];}
            break;
    }
    
}
//Postfix ++
Date Date::operator ++ (int)
{
    Date temp(year, month, day);
    day++;
    simplify();
    return temp;
}

//Prefix ++
Date Date::operator ++ ()
{
    ++day;
    simplify();
    return *this;
}

//Postfix --
Date Date::operator -- (int)
{
    Date temp(year, month, day);
    day--;
    simplify();
    return temp;
}

//Prefix --
Date Date::operator -- ()
{
    --day;
    simplify();
    return *this;
}

//- operator
int Date::operator - (const Date &right)
{
      int months [12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int days, days1, days2;
//Calculates days in first date
    days1= year*365;
    for (int i=0; i<month-1; i++)
        days1 += months[i];
    days1+=day;
        
//Calculates days in second date
    days2= right.year*365;
    for (int i=0; i<right.month-1; i++)
    days2 += months[i];
    days2+=right.day;
//Difference between the two dates.
    days = days1-days2;
    if (days>=0) return days;
        else throw "The operation could not be done.";
}


/// << cout overloaded stream operator
ostream &operator<<(ostream &strm, const Date &obj)
{
//    strm << obj.feet << " feet, " << obj.inches << " inches";
    string months [12] = { "January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month = obj.getMonth()-1;
    strm<<months[month]<<" "<< obj.getDay() << ", "<< obj.getYear()<<endl;

    return strm;
}
    
//>> cin overloaded stream operator
istream &operator >> (istream &strm, Date &obj)
{
    // Prompt the user for the year.
    cout << "Year: ";
    strm >> obj.year;
        
    // Prompt the user for the month.
    cout << "Month: ";
    strm >> obj.month;
        
    // Prompt the user for the day.
    cout << "Day: ";
    strm >> obj.day;
        
    // Normalize the values.
    obj = Date(obj.year, obj.month, obj.day);
    obj.simplify();
        
    return strm;
}
        
