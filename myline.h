#ifndef MYLINE_H
#define MYLINE_H

#include "figura.h"

class MyLine final : public Figura
{
private:
    void draw(QPainter *painter) override;
public:
    MyLine(int x, int y, int halflen);
};

#endif // MYLINE_H
