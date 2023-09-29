#include "easyppm.h"
#include "easyppm.c"
#include "vec3.h"
#include "Ray.h"
#include "RayHit.h"
#include "Scene.h"
#include <string>

using namespace std;

class Camera
{
public:
    vec3 origin;
    vec3 direction;
    int width;
    int height;

    Camera(vec3 origin, vec3 direction, int width, int height):
        origin{origin},
        direction{direction},
        width{width},
        height{height}
    {}

    void render(Scene scene, const char* img_name) 
    {
        PPM ppm = easyppm_create(width, height, IMAGETYPE_PPM);
        for(int x = 0; x < width; x++)
        {
            for(int y = 0; y < height; y++)
            {
                const Ray r(origin + vec3(x - width/2, y - height/2, 0), direction);
                
                float min_dist = INFINITY;
                for(auto &sphere : scene.objects){
                    RayHit rh = sphere.check_ray(r);
                    if(rh.hit)
                    {
                        float dist = (rh.hitPoint - origin).length();
                        if(min_dist > dist)
                        {

                            vec3 to_light = scene.light.origin - rh.hitPoint;

                            to_light.make_unit_vector();

                            min_dist = dist;
                            float coef_light = max((float)0.2,dot(to_light, sphere.get_normal(rh.hitPoint)));

                            Ray shadow_ray(rh.hitPoint + 0.001*to_light, to_light);

                            for(auto &sphere2 : scene.objects){
                                if(sphere2 == sphere)
                                {
                                    continue;
                                }
                                RayHit rh2 = sphere2.check_ray(shadow_ray);
                                if(rh2.hit){
                                    coef_light = 0.2;
                                    break;
                                }
                            }

                            vec3 color = sphere.get_color(rh.hitPoint) * coef_light;
                            easyppm_set(&ppm, x, y, easyppm_rgb(color.x(),color.y(),color.z())); 
                        }
                    }
                }
                if(min_dist == INFINITY)
                {
                    easyppm_set(&ppm, x, y, easyppm_rgb(83, 83, 83));
                }
            }
        }
        easyppm_write(&ppm, img_name);
    }
};