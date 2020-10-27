//
//  ExternalExamMarks.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 21/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#ifndef ExternalExamMarks_hpp
#define ExternalExamMarks_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class ExternalExamMarks
{
protected:
    string eMark1;
    string eMark2;
public:
    ExternalExamMarks() : eMark1("N/A"), eMark2("N/A"){};
    ExternalExamMarks(string m1, string m2) : eMark1(m1), eMark2(m2){};
    
//    Accessors
    string geteMark1() {return eMark1;}
    string geteMark2() {return eMark2;}
    
//    Mutators
    void seteMark1(string m1) {eMark1 = m1;}
    void seteMark2(string m2) {eMark2 = m2;}
};
#endif /* ExternalExamMarks_hpp */
