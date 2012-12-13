//
//  Surrogate.cpp
//  SK_CPlusPlus
//
//  Created by shum saki on 12-12-7.
//  Copyright (c) 2012年 招商局物流集团. All rights reserved.
//

#include "Surrogate.h"

Automobile::Automobile():mWeight(6.0f) {}

double Automobile::weight() const
{
    return mWeight;
}

void Automobile::start()
{
    cout<<"Start"<<endl;
}

Automobile* Automobile::copy() const
{
    return new Automobile(*this);
}

VehicleSurrogate::VehicleSurrogate(): vp(0) {}

VehicleSurrogate::VehicleSurrogate(const Vehicle& v)
:vp(v.copy()) {} /// Every time the virtual call 

VehicleSurrogate::~VehicleSurrogate()
{
    delete vp;
}

VehicleSurrogate::VehicleSurrogate(const VehicleSurrogate& v)
:vp(v.vp? v.vp->copy() : 0) {} /// Non-zero detection for v.vp

VehicleSurrogate&
VehicleSurrogate::operator=(const VehicleSurrogate& v)
{
    if (this != &v) {
        delete vp;
        /// Assignment operator detection
        vp = (v.vp ? v.vp->copy() : 0);
    }
    return *this;
}

double VehicleSurrogate::weight()
{
    if (vp == 0) {
        throw "Empty VehicleSurrogate.weight()";
    }
    return vp->weight();
}

void VehicleSurrogate::start()
{
    if (vp == 0) {
        throw "Empty VehicleSurrogate.start()";
    }
    return vp->start();
}



