//
//  Ship.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 20/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#ifndef Ship_hpp
#define Ship_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Ship
{
private:
    string name;
    int year;
    
public:
// Default constructor
    Ship()
    {
        year= 0;
        name = "";
    };
    
// Constructor
    Ship(string n, int y) : name(n), year(y) {};

// Accessors
    string getName() {return name;}
    int getYear() {return year;}
    
// Mutators
    void setName(string s) {name =s;}
    void setYear(int y) {year = y;}
   
// Virtual print method
   virtual void print()
    {
        cout<<"The ship "<<name<<" was built in "<<year<<endl;
    }
};


#endif /* Ship_hpp */
