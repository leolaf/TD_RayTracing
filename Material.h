#pragma once
#include "vec3.h"

class Material 
{
public:
    vec3 color;

    Material(vec3 color): color{color} {};
};