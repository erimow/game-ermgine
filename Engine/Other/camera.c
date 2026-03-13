#include "camera.h"

void camera_init(Camera *camera){
    camera->x=0;
    camera->y=0;
    camera->z=1;
}
void camera_set_position(Camera *camera, float x, float y){
    camera->x = x;
    camera->y = y;
}
void camera_set_z(Camera *camera, float z){
    camera->z = z;
}
void camera_transform(Camera *camera, float xtransform, float ytransform){
    camera->x=camera->x+xtransform;
    camera->y=camera->y+ytransform;
}