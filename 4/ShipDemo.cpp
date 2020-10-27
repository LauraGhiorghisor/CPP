//
//  ShipDemo.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 21/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Ship.hpp"
#include "CargoShip.hpp"
#include "CruiseShip.hpp"
using namespace std;

int main(){
    Ship *ships[6];
//  Different constructors being used
    ships[0] = new Ship("Ship0", 1920);
    ships[1] = new Ship("Ship1", 1920);
    ships[2] = new CargoShip(25000); ships[2]->setName("Ship2"); ships[2]->setYear(1890);
    ships[3] = new CargoShip(245000); ships[3]->setName("Ship3"); ships[3]->setYear(1930);
    ships[4] = new CruiseShip(3500); ships[4]->setName("Ship4");
    ships[5] = new CruiseShip("Ship5", 1999, 4000);
//  The print() method is called for each class.
    for (int i=0; i<6; i++)
        ships[i]->print();

    return 0;
}
