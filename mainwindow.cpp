#include "mainwindow.h"
#include "strvalidator.h"
#include <QVBoxLayout>
#include <QMessageBox>

void MainWindow::generateUI()
{
    setWindowTitle("Возведение в квадрат");

    frame = new QFrame(this);
    frame -> setFrameShadow(QFrame::Raised);
    frame -> setFrameShape(QFrame::Panel);

    inputLabel = new QLabel("Введите число", this);
    // Здесь и далее параметром указывается this,
    // это делается, чтобы при удаление окна автоматически удалялись и эти элементы, следовательно деструктор не нужен
    inputEdit = new QLineEdit("", this);
    StrValidator *v = new StrValidator(inputEdit);
    inputEdit -> setValidator(v);

    outputLabel = new QLabel("Результат:", this);
    outputEdit = new QLineEdit("", this);

    nextButton = new QPushButton("Следующее", this);
    exitButton = new QPushButton("Выход", this);

    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1 -> addWidget(inputLabel);
    vLayout1 -> addWidget(inputEdit);
    vLayout1 -> addWidget(outputLabel);
    vLayout1 -> addWidget(outputEdit);
    vLayout1->addStretch();

    QVBoxLayout *vLayout2 = new QVBoxLayout();

    vLayout2 -> addWidget(nextButton);
    vLayout2 -> addWidget(exitButton);
    vLayout2 -> addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);

    hLayout -> addWidget(frame);
    hLayout -> addLayout(vLayout2);
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    generateUI();
    begin();
    connect(
        exitButton,
        SIGNAL(clicked(bool)),
        this,
        SLOT(close())
    );
    connect(
        nextButton,
        SIGNAL(clicked(bool)),
        this,
        SLOT(begin())
    );
    connect(
        inputEdit,
        SIGNAL(returnPressed()),
        this,
        SLOT(calc())
    );
}

void MainWindow::begin()
{
    inputEdit -> clear();
    nextButton -> setEnabled(false);
    inputEdit -> setEnabled(true);
    outputLabel -> setVisible(false);
    outputEdit -> setVisible(false);
    outputEdit -> setEnabled(false);
    inputEdit -> setFocus(); // Устанвливаем курсор клавиратуры в этот элемент
}

void MainWindow::calc()
{
    bool Ok = true;
    float r,a;
    QString str = inputEdit -> text();
    a = str.toDouble(&Ok); // В Ok будет храниться маркер того, было ли чтение завершенно без ошибок
    if(Ok){
        r = a*a;
        str.setNum(r);
        outputEdit -> setText(str);
        inputEdit -> setEnabled(false);
        outputLabel -> setVisible(true);
        outputEdit -> setVisible(true);
        nextButton -> setDefault(true);
        nextButton -> setEnabled(true);
        nextButton -> setFocus();
    }else{
        if(!str.isEmpty()){
            QMessageBox msgBox(
                QMessageBox::Information,
                "Возведение в квадрат",
                "Введено неверное значение",
                QMessageBox::Ok
            );
            msgBox.exec(); //Вызов окна, отличается от show тем, что блокирует всё остальное приложение
        }
    }
}
