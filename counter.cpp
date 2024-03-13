#include "counter.h"
#include <limits>
#include <QMessageBox>

Counter::Counter(const QString &contents, QWidget *parent)
    : QLineEdit(contents, parent){}

void Counter::add_one()
{
    QString str = text(); // Обращаемся к методу унаследованному от QLineEdit
    int r = str.toInt();
    r++;
    if(r == std::numeric_limits<int>::max()){
        QMessageBox msgBox(
            QMessageBox::Information,
            "Счётчик",
            "Значение переполнило целочисленный тип, будет сброшено",
            QMessageBox::Ok
        );
        msgBox.exec();

        str.setNum(0);
        setText(str);
        return;
    }
    if(r != 0 && r%5 == 0)
        emit tick_signal();
    str.setNum(r);
    setText(str);
}

