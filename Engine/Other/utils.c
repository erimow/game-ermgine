#include "utils.h"
bool check_collision_FRect(FRect *a, FRect *b){
    if ((((a->x<b->x)&&(a->x+a->w>(b->x)))||(((a->x)>b->x)&&((a->x)<(b->x+b->w))))&&((a->y<b->y&&a->y+a->h>(b->y))||(a->y>b->y&&(a->y<b->y+b->h))))
        return true;
    else
        return false;
}