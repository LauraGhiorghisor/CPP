//
//  Date.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 20/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
#include <iostream>

using namespace std;


class Date;
// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const Date &);
istream &operator >> (istream &, Date &);

class Date
{
private:
    int year;
    int month;
    int day;
    void simplify();
public:
//Default constructor
    Date()
    {
        year= 0;
        month = 0;
        day = 0;
    };
//Constructor
    Date(int, int, int);
    Date(int, int, int, bool);
    
//Accessors
    void setYear(int y) {year = y;}
    void setMonth(int m) {month = m;}
    void setDay(int d) {day = d;}
        
// Mutators
    double getDay() const { return day;};
    double getMonth() const {return month;}
    double getYear() const { return year;}

//Methods - Exercise 1
    void printVersion1();
    void printVersion2();
    void printVersion3();


//Operator overloading methods - Exercise 2
    Date operator ++ (int);
    Date operator ++ ();
    Date operator -- (int);
    Date operator -- ();
    int operator - (const Date &);
    friend ostream &operator << (ostream &, const Date &);
    friend istream &operator >> (istream &, Date &);

};

//Classes to be used for exceptions - Exercise 3

class InvalidDay
{
    private:
        string message;
    public:
        InvalidDay(){}
        InvalidDay(string message) : message(message){};
        string getMessage() const {return message;}

};

class InvalidMonth
{
    private:
            string message;
        public:
            InvalidMonth(){}
            InvalidMonth(string message) : message(message){};
            string getMessage() const {return message;}

    };

class InvalidYear
{
    private:
            string message;
        public:
            InvalidYear(){}
            InvalidYear(string message) : message(message){};
            string getMessage() const {return message;}

    };

#endif /* Date_hpp */



