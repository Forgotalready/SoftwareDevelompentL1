#include "strvalidator.h"


StrValidator::StrValidator(QObject *parent)
    : QValidator(parent){}

QValidator::State StrValidator::validate(QString &str, int &pos) const
{
    return Acceptable;
}
