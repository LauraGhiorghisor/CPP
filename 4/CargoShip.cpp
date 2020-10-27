//
//  CargoShip.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 20/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include "CargoShip.hpp"
#include <iostream>

using namespace std;



void CargoShip::print(){
    cout<<"The ship "<<this->getName()<<" has a capacity of "<<tonnage<<" tons on board."<<endl;
}
