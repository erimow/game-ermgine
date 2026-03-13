#ifndef MOUSEINFO_H
#define MOUSEINFO_H

#include <stdbool.h>

typedef struct MouseInfo {
 bool isMousePressed;
 float xPos, yPos;
 float xPosOnMousePress, yPosOnMousePress;
} MouseInfo;

void mouseinfo_init(MouseInfo *mi);

#endif