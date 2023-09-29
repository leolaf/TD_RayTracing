#include "vec3.h"
#include "Sphere.h"
#include "Ray.h"
#include "RayHit.h"
#include "Camera.h"
#include "Scene.h"
#include <iostream>


int main()
{
    int img_w = 1920;
    int img_h = 1080;

    Scene mainScene;
    mainScene.light = PointLight(vec3(img_w/2-200,img_w/2-100,0),1000,vec3(255,255,255));
    mainScene.add_geometry(Sphere(vec3(img_w/2, img_h/2, 400), 40, Material(vec3(250,89,77))));
    mainScene.add_geometry(Sphere(vec3(img_w/2, img_h/2, 340), 10, Material(vec3(187,250,77))));
    mainScene.add_geometry(Sphere(vec3(img_w/2+200, img_h/2+100, 780), 100, Material(vec3(167,77,250))));

    Camera cam{vec3(img_w/2, img_h/2 , 0), vec3(0, 0, 1), img_w, img_h};
    cam.render(mainScene, "image.ppm");
}