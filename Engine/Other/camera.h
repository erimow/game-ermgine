#ifndef CAMERA_H
#define CAMERA_H

#include <stdint.h>
#include "../Core/constants.h"

typedef struct Camera{
    float x,y,z;
    uint16_t w,h;
}Camera;

void camera_init(Camera *camera);
void camera_set_position(Camera *camera, float x, float y);
void camera_set_size(Camera *camera, uint16_t width, uint16_t height);
void camera_set_z(Camera *camera, float z);
void camera_transform(Camera *camera, float xtransform, float ytransform);

#endif