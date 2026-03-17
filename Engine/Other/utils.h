#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

typedef struct FRect{
    float x,y,w,h;
} FRect;

bool check_collision_FRect(FRect *a, FRect *b);

#endif