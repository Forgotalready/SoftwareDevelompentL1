#include "myline.h"

void MyLine::draw(QPainter *painter)
{
    painter -> drawLine(x + dx, y + dy, x - dx, y - dy);
}

MyLine::MyLine(int x, int y, int halflen)
    : Figura(x, y, halflen){}

