//
//  CruiseShip.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 20/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include "CruiseShip.hpp"
#include <iostream>
using namespace std;



void CruiseShip::print(){
    cout<<"The ship "<<this->getName()<<" has a capacity for "<<maxPassengers<<" people on board."<<endl;
}
