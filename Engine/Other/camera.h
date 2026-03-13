#ifndef CAMERA_H
#define CAMERA_H

typedef struct Camera{
    float x,y,z;
}Camera;

void camera_init(Camera *camera);
void camera_set_position(Camera *camera, float x, float y);
void camera_set_z(Camera *camera, float z);
void camera_transform(Camera *camera, float xtransform, float ytransform);

#endif