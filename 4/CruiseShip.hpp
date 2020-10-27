//
//  CruiseShip.hpp
//  SE2
//
//  Created by Laura Ghiorghisor on 20/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#ifndef CruiseShip_hpp
#define CruiseShip_hpp

#include "Ship.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
class CruiseShip : public Ship
{
private:
    int maxPassengers;
    
public:
//    Constructors
    CruiseShip(): maxPassengers(0) {};
    CruiseShip (int n): maxPassengers(n) {};
    CruiseShip (string s, int y, int m) : Ship(s,y), maxPassengers(m){};

// Accessors
    int getNumberPassengers() {return maxPassengers;}
// Mutators
    void setNumberPassengers(int n) {maxPassengers = n;}
    
// Overriden function
    void print();
    
};

#endif /* CruiseShip_hpp */
