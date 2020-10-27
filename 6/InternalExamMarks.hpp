//
//  InternalExamMarks.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 21/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#ifndef InternalExamMarks_hpp
#define InternalExamMarks_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class InternalExamMarks
{
protected:
    string iMark1;
    string iMark2;
public:
// Constructors
    InternalExamMarks() : iMark1("N/A"), iMark2("N/A"){};
    InternalExamMarks(string m1, string m2) : iMark1(m1), iMark2(m2){};
    
//    Accessors
    string getiMark1() {return iMark1;}
    string getiMark2() {return iMark2;}
    
//    Mutators
    void setiMark1(string m1) {iMark2 = m1;}
    void setiMark2(string m2) {iMark2 = m2;}
};
#endif /* InternalExamMarks_hpp */
