//
//  CargoShip.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 20/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#ifndef CargoShip_hpp
#define CargoShip_hpp

#include "Ship.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
class CargoShip : public Ship
{
private:
    int tonnage;
    
public:
//    Constructors
    CargoShip(): tonnage(0) {};
    CargoShip (int n): tonnage(n) {};
    CargoShip (string s, int y, int n) : Ship(s,y), tonnage(n){};

// Accessors
    int getTonnage() {return tonnage;}
// Mutators
    void setTonnage(int n) {tonnage = n;}
    
// Overriden function
    void print();
    
};
#endif /* CargoShip_hpp */
