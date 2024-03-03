#include "myrect.h"

void MyRect::draw(QPainter *painter)
{
    painter -> drawLine(x+dx, y+dy, x+dy, y - dx);
    painter -> drawLine(x + dy, y - dx, x - dx, y - dy);
    painter -> drawLine(x - dx, y - dy, x - dy, y + dx);
    painter -> drawLine(x - dy, y + dx, x + dx, y + dy);
}

MyRect::MyRect(int x, int y, int halflen)
    :Figura(x, y, halflen){}
