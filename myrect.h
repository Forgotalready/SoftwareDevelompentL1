#ifndef MYRECT_H
#define MYRECT_H

#include "figura.h"

class MyRect final : public Figura
{
private:
    void draw(QPainter *) override;
public:
    MyRect(int x, int y, int halflen);
};

#endif // MYRECT_H
