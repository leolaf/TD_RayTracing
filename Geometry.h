#include "Material.h"

class Geometry
{
public:
    Material mat;

    Geometry() : mat{Material(vec3(255,255,255))} {};
    Geometry(Material mat) : mat{mat} {};

    // virtual vec3 get_color(vec3 point);
    // virtual vec3 get_normal(vec3 point);
    // virtual RayHit check_ray(Ray r);
};