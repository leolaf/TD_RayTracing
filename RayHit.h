#pragma once
#include "vec3.h"

class RayHit 
{
public:

    vec3 hitPoint;
    bool hit;

    RayHit(bool hit): hit{hit}, hitPoint{vec3()} {};
    RayHit(bool hit, vec3 hitPoint): hit{hit}, hitPoint{hitPoint} {};
};