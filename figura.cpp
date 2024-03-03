#include "figura.h"
#include <cmath>
Figura::Figura(int x, int y, int halflen)
    : x(x), y(y), halflen(halflen){}

void Figura::move(float Alpha, QPainter *painter)
{
    dx = halflen * cos(Alpha);
    dy = halflen * sin(Alpha);
    draw(painter);
}
