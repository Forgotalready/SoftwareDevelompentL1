#include "counter.h"

Counter::Counter(const QString &contents, QWidget *parent)
    : QLineEdit(contents, parent){}

void Counter::add_one()
{
    QString str = text(); // Обращаемся к полю унаследованному от QLineEdit
    int r = str.toInt();
    if(r != 0 && (r + 1)%5 == 0)
        emit tick_signal();
    r++;
    str.setNum(r);
    setText(str);
}

