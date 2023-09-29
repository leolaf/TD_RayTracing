#pragma once
#include "vec3.h"
#include "Ray.h"
#include "RayHit.h"
#include "Geometry.h"

class Sphere : public Geometry
{
public:
    vec3 center;
    float radius;

    Sphere(vec3 center, float radius): center{center}, radius{radius} {};
    Sphere(vec3 center, float radius, Material mat): center{center}, radius{radius} 
    {
        this->mat = mat;
    };

    vec3 get_color(vec3 point) { return mat.color; };

    vec3 get_normal(vec3 point) {
        vec3 normal = (point - center);
        normal.make_unit_vector();
        return normal;
    };

    RayHit check_ray(Ray r) 
    {
        vec3 center_to_origin = r.origin - center;
        float a = dot(r.direction, r.direction);
        float b = 2.0 * dot(center_to_origin, r.direction);
        float c = dot(center_to_origin, center_to_origin) - radius * radius;
        float discriminant = b * b - 4 * a * c;
        float d = sqrt((b * b) - (4 * a * c));
        float t = (-b - abs(d)) / (2 * a);
        if (discriminant >= 0 && t > 0)
        {
            return RayHit(true,r.origin + t*r.direction);
        }
        return RayHit(false);
    }

    inline bool operator==(const Sphere &s2) {
        return s2.center.x() == center.x() && 
            s2.center.y() == center.y() && 
            s2.center.z() == center.z() && 
            s2.radius == radius;
    }
};