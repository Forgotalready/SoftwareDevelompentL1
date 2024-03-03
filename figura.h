#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>

class Figura
{
protected:
    int x, y, halflen, dx, dy, r;
    virtual void draw(QPainter *painter) = 0;
public:
    Figura(int x, int y, int halflen);

    void move(float Alpha, QPainter *painter);
};

#endif // FIGURA_H
