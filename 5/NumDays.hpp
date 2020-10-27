//
//  NumDays.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 21/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#ifndef NumDays_hpp
#define NumDays_hpp

#include <stdio.h>

class NumDays
{
    private:
    double hours;
    double days;
    void updateDays();
    
    public:
// Constructors
    NumDays() : hours(0), days(0){};
    NumDays(double h) : hours(h) {};
  
    
// Accessors
    double getHours() {return hours;}
    double getDays() {return days;}
    
// Mutators
    void setHours(double h){hours = h;}
    void setDays(double d){days = d;}
    
//Operator overloading methods 
    NumDays operator ++ (int);
    NumDays operator ++ ();
    NumDays operator -- (int);
    NumDays operator -- ();
    NumDays operator - (const NumDays &);
    NumDays operator + (const NumDays &);
};


#endif /* NumDays_hpp */
