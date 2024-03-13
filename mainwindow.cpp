#include "mainwindow.h"
#include <QHBoxLayout>
#include <QMessageBox>
void MainWindow::generateGUI()
{
    setWindowTitle("Счетчик");
    try{
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
    }catch(std::bad_alloc& ba){
        auto msg = QMessageBox(
            QMessageBox::Critical,
            "Счетчик",
            "Невозможно выделить память",
            QMessageBox::Ok
        );
        exit(1);
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

