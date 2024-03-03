#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "area.h"
#include <QPushButton>
class MainWindow final : public QWidget
{
    Q_OBJECT
private:
    Area *area;
    QPushButton *btn;
public:
    MainWindow(QWidget *parent = nullptr);
};
#endif // MAINWINDOW_H
