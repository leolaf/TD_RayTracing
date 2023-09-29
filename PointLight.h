#pragma once

#include "vec3.h"

class PointLight
{
public:
    vec3 origin;
    float power;
    vec3 color;

    PointLight():
        origin{vec3(0,0,0)},
        power{10.0},
        color{vec3(255,255,255)}
    {};

    PointLight(vec3 origin, float power, vec3 color):
        origin{origin},
        power{power},
        color{color}
    {};
};