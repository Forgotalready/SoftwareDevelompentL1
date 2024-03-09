#include "mainwindow.h"
#include <QHBoxLayout>

void MainWindow::generateGUI()
{
    setWindowTitle("Счетчик");
    label1 = new QLabel("Счет по 1", this);
    label2 = new QLabel("Счет по 5", this);

    edit1 = new Counter("0", this);
    edit2 = new Counter("0", this);
    edit1 -> setReadOnly(true);
    edit2 -> setReadOnly(true);

    calcButton = new QPushButton("+1", this);
    exitButton = new QPushButton("Выход", this);

    QHBoxLayout *layout1 = new QHBoxLayout();
    layout1 -> addWidget(label1);
    layout1 -> addWidget(label2);

    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2 -> addWidget(edit1);
    layout2 -> addWidget(edit2);

    QHBoxLayout *layout3 = new QHBoxLayout();
    layout3 -> addWidget(calcButton);
    layout3 -> addWidget(exitButton);

    QVBoxLayout *layout4 = new QVBoxLayout(this);
    layout4 -> addLayout(layout1);
    layout4 -> addLayout(layout2);
    layout4 -> addLayout(layout3);
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    generateGUI();

    connect(
        calcButton,
        SIGNAL(clicked(bool)),
        edit1,
        SLOT(add_one())
    );
    connect(
        edit1,
        SIGNAL(tick_signal()),
        edit2,
        SLOT(add_one())
    );
    connect(
        exitButton,
        SIGNAL(clicked(bool)),
        this,
        SLOT(close())
    );
}

