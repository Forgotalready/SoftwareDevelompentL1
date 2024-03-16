#include "mainwindow.h"
#include <QHBoxLayout>
#include <QMessageBox>
void MainWindow::generateGUI() noexcept
{
    setWindowTitle("Счетчик");
    label1 = new(std::nothrow) QLabel("Счет по 1", this);
    label2 = new(std::nothrow) QLabel("Счет по 5", this);

    edit1 = new(std::nothrow) Counter("0", this);
    edit2 = new(std::nothrow) Counter("0", this);


    calcButton = nullptr;//new(std::nothrow) QPushButton("+1", this);
    exitButton = new(std::nothrow) QPushButton("Выход", this);

    QHBoxLayout *layout1 = new(std::nothrow) QHBoxLayout();
    QHBoxLayout *layout2 = new(std::nothrow) QHBoxLayout();
    QHBoxLayout *layout3 = new(std::nothrow) QHBoxLayout();

    if(label1 && label2 && edit1 && edit2 && calcButton && exitButton && layout1 && layout2 && layout3){
        edit1 -> setReadOnly(true);
        edit2 -> setReadOnly(true);

        layout1 -> addWidget(label1);
        layout1 -> addWidget(label2);


        layout2 -> addWidget(edit1);
        layout2 -> addWidget(edit2);

        layout3 -> addWidget(calcButton);
        layout3 -> addWidget(exitButton);
    }
    QVBoxLayout *layout4 = new(std::nothrow) QVBoxLayout(this);
    if(layout4){
        layout4 -> addLayout(layout1);
        layout4 -> addLayout(layout2);
        layout4 -> addLayout(layout3);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    generateGUI();

    connect(
        calcButton,
        &QPushButton::clicked,
        edit1,
        &Counter::add_one
    );
    connect(
        edit1,
        &Counter::tick_signal,
        edit2,
        &Counter::add_one
    );
    connect(
        exitButton,
        &QPushButton::clicked,
        this,
        &MainWindow::close
    );
}

