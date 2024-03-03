#include "mainwindow.h"
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Обработка событий");
    area = new Area(this);
    btn = new QPushButton("Завершить", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout -> addWidget(area);
    layout -> addWidget(btn);

    connect(
        btn,
        SIGNAL(clicked(bool)),
        this,
        SLOT(close())
    );
}


