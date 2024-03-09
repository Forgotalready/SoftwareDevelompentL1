#ifndef COUNTER_H
#define COUNTER_H

#include <optional>
#include <QLineEdit>

class Counter final : public QLineEdit
{
    Q_OBJECT
private:
    std::optional<int> counter = std::nullopt;
public:
    Counter(const QString& contents, QWidget *parent = nullptr);
signals:
    void tick_signal();
public slots:
    void add_one();
};

#endif // COUNTER_H
