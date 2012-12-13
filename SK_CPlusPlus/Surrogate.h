//
//  Surrogate.h
//  SK_CPlusPlus
//
//  Created by shum saki on 12-12-7.
//  Copyright (c) 2012年 招商局物流集团. All rights reserved.
//

#ifndef __SK_CPlusPlus__Surrogate__
#define __SK_CPlusPlus__Surrogate__

#include <iostream>

using namespace std;

class Vehicle {
public:
    virtual double weight() const = 0;
    virtual void start() = 0;
    virtual Vehicle* copy() const = 0;
    virtual ~Vehicle() {}
    /// ...
}; 

class Automobile : public Vehicle {
    double mWeight;
public:
    Automobile();
    virtual double weight() const;
    virtual void start();
    virtual Automobile* copy() const;
    virtual ~Automobile() {}
};

class VehicleSurrogate {
     Vehicle* vp;
    
public:
    VehicleSurrogate();
    VehicleSurrogate(const Vehicle&);
    ~VehicleSurrogate();
    VehicleSurrogate(const VehicleSurrogate&);
    VehicleSurrogate& operator=(const VehicleSurrogate&);
    
    /// From the operation of the Vicle
    double weight();
    void start();
    /// ...
};

#endif /* defined(__SK_CPlusPlus__Surrogate__) */
