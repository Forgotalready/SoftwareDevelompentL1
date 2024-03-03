#ifndef AREA_H
#define AREA_H

#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QShowEvent>
#include <QTimerEvent>
#include <QHideEvent>
#include "myrect.h"
#include "myline.h"

class Area final : public QWidget
{
    int myTimer;
    float alpha;

    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent (QHideEvent *event);
public:
    Area(QWidget *parent = nullptr);
    MyLine *myLine;
    MyRect *myRect;
    ~Area();
};

#endif // AREA_H
