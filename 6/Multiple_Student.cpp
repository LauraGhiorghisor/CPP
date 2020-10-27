//
//  Multiple_Student.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 21/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "InternalExamMarks.hpp"
#include "ExternalExamMarks.hpp"
#include "StudentMarksInfo.hpp"
#include "Student.hpp"
using namespace std;

int main(){
//  Create students and marks
    InternalExamMarks internal1 = InternalExamMarks("A", "A");
    ExternalExamMarks external1 = ExternalExamMarks("B", "C");
    StudentMarksInfo marks1 = StudentMarksInfo(internal1, external1);
    Student student1 = Student("Andrew Collins", "1234HIA", "Computer Science", marks1);
    Student student2 = Student("Gemma Collins", "1235HIb", "Mathematics", marks1);
    
    InternalExamMarks internal2 = InternalExamMarks("B", "A");
    ExternalExamMarks external2 = ExternalExamMarks("A", "C");
    StudentMarksInfo marks2 = StudentMarksInfo(internal2, external2);
    Student student3 = Student("Michael Hammock", "3333BBB", "Arts", marks2);
    
//  Print marks
    cout<<student1.getName()<<" has the following marks: "<<endl;
    student1.getStudentMarks().printMarks();
    
    cout<<student2.getName()<<" has the following marks: "<<endl;
    student2.getStudentMarks().printMarks();
    
    cout<<student3.getName()<<" has the following marks: "<<endl;
    student3.getStudentMarks().printMarks();
    
//    Using base class methods in child
    cout<<endl<<"Using base class methods :"<<endl;
    cout<<endl<<student1.getName()<<endl<<"First subject marks : ";
    cout<<student1.getStudentMarks().getiMark1()<<" "<<student1.getStudentMarks().geteMark1();
    cout<<endl<<"Second subject marks : ";
    cout<<student1.getStudentMarks().getiMark2()<<" "<<student1.getStudentMarks().geteMark2()<<endl;
    
//    Default constructor
    cout<<endl<<"Default constructor :"<<endl;
    InternalExamMarks internal3 = InternalExamMarks();
    ExternalExamMarks external3 = ExternalExamMarks();
    StudentMarksInfo marks3 = StudentMarksInfo();
    Student student4 = Student("Thomas Collins", "1234HIA", "Computer Science", marks3);
    cout<<endl<<student4.getName()<<" has the following marks: "<<endl;
    student4.getStudentMarks().printMarks();
    return 0;
}
