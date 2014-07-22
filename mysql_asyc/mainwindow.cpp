#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlthread.h"
MainWindow::MainWindow(SQLThread &s, QWidget *parent) : sqlthread(s),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect(&sqlthread,SIGNAL(openError(QString)),
              this,SLOT(printInfo(QString)));
    connect(&sqlthread,SIGNAL(getResult(MyVector&, int)),
              this,SLOT(mydata(MyVector&, int))/*, Qt::DirectConnection*/);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
