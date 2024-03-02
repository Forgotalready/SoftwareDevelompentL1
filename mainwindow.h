#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class MainWindow final : public QWidget
{
    Q_OBJECT
private:
    QFrame *frame;
    QLabel *inputLabel;
    QLineEdit *inputEdit;
    QLabel *outputLabel;
    QLineEdit *outputEdit;
    QPushButton *nextButton;
    QPushButton *exitButton;

    void generateUI();
public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void begin();
    void calc();
};
#endif // MAINWINDOW_H
