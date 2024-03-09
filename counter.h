#ifndef COUNTER_H
#define COUNTER_H

#include <optional>
#include <QLineEdit>

class Counter final : public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString& contents, QWidget *parent = nullptr);
    std::optional<int> counter = std::nullopt;
signals:
    void tick_signal();
public slots:
    void add_one();
};

#endif // COUNTER_H
