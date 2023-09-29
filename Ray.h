#pragma once
#include "vec3.h"

class Ray 
{
public:
    vec3 origin;
    vec3 direction;

    Ray(vec3 origin, vec3 direction): origin{origin}, direction{direction} {};
};