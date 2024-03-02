#ifndef STRVALIDATOR_H
#define STRVALIDATOR_H

#include <QObject>
#include <QValidator>
// Определяет действия после нажатия enter в textEdit
class StrValidator final : public QValidator
{
public:
    StrValidator(QObject *parent);
    State validate(QString &str, int &pos) const override;
};

#endif // STRVALIDATOR_H
