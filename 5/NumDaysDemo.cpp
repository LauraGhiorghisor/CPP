//
//  NumDaysDemo.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 21/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include <stdio.h>
#include "NumDays.hpp"
#include <iostream>
using namespace std;

int main(){
    
    //Addition +
    NumDays num1 = NumDays(405);
    NumDays num2 = NumDays(300);
    NumDays sum = num1+num2;
    cout<<"The sum is "<<sum.getHours()<<" hours or "<<sum.getDays()<<" days."<<endl;
    
    // Multiple addition
    NumDays n1 = NumDays(405);
    NumDays n2 = NumDays(300);
    NumDays sum1 = n1+n2+n1;
    cout<<"The sum is "<<sum1.getHours()<<" hours or "<<sum1.getDays()<<" days."<<endl;

    //Difference -
    NumDays num3 = NumDays(405);
    NumDays num4 = NumDays(300);
    NumDays diff = num3-num4;
    cout<<"The difference is "<<diff.getHours()<<" hours or "<<diff.getDays()<<" days."<<endl;
    
    
    //++
        NumDays incrementNumDays = NumDays(20);
        NumDays prefixNumDays = ++incrementNumDays;
        cout<<"After: hours - "<<prefixNumDays.getHours()<<", days - "<<prefixNumDays.getDays()<<"; Before : hours - "<<incrementNumDays.getHours()<<", days - "<<incrementNumDays.getDays()<<endl;
    
        NumDays postfixNumDays = incrementNumDays++;
        cout<<"After: hours - "<<postfixNumDays.getHours()<<", days - "<<postfixNumDays.getDays()<<"; Before : hours - "<<incrementNumDays.getHours()<<", days - "<<incrementNumDays.getDays()<<endl;
    
    //--
        NumDays decrementNumDays = NumDays(25);
        NumDays prefixNumDays1 = --decrementNumDays;
        cout<<"After: hours - "<<prefixNumDays1.getHours()<<", days - "<<prefixNumDays1.getDays()<<"; Before : hours - "<<decrementNumDays.getHours()<<", days - "<<prefixNumDays1.getDays()<<endl;
        
        NumDays postfixNumDays1 = decrementNumDays--;
        cout<<"After: hours - "<<postfixNumDays1.getHours()<<", days - "<<postfixNumDays1.getDays()<<"; Before : hours - "<<decrementNumDays.getHours()<<", days - "<<decrementNumDays.getDays()<<endl;
    
    return 0;
}
