#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QPushButton>
#include "counter.h"

class MainWindow final : public QWidget
{
    Q_OBJECT

private:
    QLabel *label1, *label2;
    Counter *edit1, *edit2;
    QPushButton *calcButton;
    QPushButton *exitButton;

    void generateGUI() noexcept;
public:
    MainWindow(QWidget *parent = nullptr);
};
#endif // MAINWINDOW_H
