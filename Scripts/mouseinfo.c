#include "mouseinfo.h"

void mouseinfo_init(MouseInfo *mi){
    mi->xPos = 0;
    mi->yPos = 0;
    mi->xPosOnMousePress = 0;
    mi->yPosOnMousePress = 0;
    mi->isMousePressed = 0;
}