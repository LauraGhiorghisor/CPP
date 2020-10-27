//
//  StudentMarksInfo.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 21/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#ifndef StudentMarksInfo_hpp
#define StudentMarksInfo_hpp

#include <stdio.h>
#include "InternalExamMarks.hpp"
#include "ExternalExamMarks.hpp"
#include <iostream>
using namespace std;

class StudentMarksInfo : public InternalExamMarks, public ExternalExamMarks
{

public:
//    Constructors
    StudentMarksInfo() : InternalExamMarks(), ExternalExamMarks() {};
    StudentMarksInfo(string im1, string im2, string em1, string em2) : InternalExamMarks(im1, im2), ExternalExamMarks(em1, em2){};
    StudentMarksInfo(InternalExamMarks im, ExternalExamMarks em): InternalExamMarks(im.getiMark1(), im.getiMark2()), ExternalExamMarks(em.geteMark1(), em.geteMark2()){};
    
//  Accessor
    void printMarks(){
        
        cout<<"First subject grades: "<<iMark1<< " "<<eMark1<<endl<<"Second subject grades: "<<iMark2<< " "<<eMark2<<endl<<endl;
    }
};
#endif /* StudentMarksInfo_hpp */
