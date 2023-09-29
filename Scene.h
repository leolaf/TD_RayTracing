#pragma once
#include <vector>
#include "Sphere.h"
#include "PointLight.h"

using namespace std;

class Scene
{
public:
    vector<Sphere> objects;
    PointLight light; 

    Scene(): objects{{}}, light{PointLight()} {};

    void add_geometry(Sphere geometry) { objects.push_back(geometry); };
};