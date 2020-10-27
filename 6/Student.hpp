//
//  Student.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 21/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>
#include "StudentMarksInfo.hpp"

using namespace std;

class Student
{
private:
    string name;
    string rollNumber;
    string stream;
    StudentMarksInfo studentMarks;
    
public:
//    Constructors
    Student(): name(""), rollNumber(""), stream(""), studentMarks(StudentMarksInfo()){};
    Student(string n, string r, string s, StudentMarksInfo smi): name(n), rollNumber(r), stream(s), studentMarks(smi){};

    
//    Accessors
    string getName() {return name;}
    string getRollNumber() {return rollNumber;}
    string getStream() {return stream;}
    StudentMarksInfo getStudentMarks() {return studentMarks;}
    
//    Mutators
    void setName(string n) { name = n;}
    void setRollNumber(string r) {rollNumber = r;}
    void setStream(string s) {stream = s;}
    void setStudentMarks(StudentMarksInfo smi) {studentMarks = smi;}
    
};
#endif /* Student_hpp */
