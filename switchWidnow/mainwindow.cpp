#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cwidgeta.h"
#include "cwidgetb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //������������ĸ�ָ��Ϊframe
    widgetA = new CWidgetA(ui->frame);
    widgetB = new CWidgetB(ui->frame);
    //�������ô�С
    widgetA->resize(ui->frame->size());
    widgetB->resize(ui->frame->size());

    widgetB->hide();

    connect(ui->pushButtonA,SIGNAL(clicked()),this,SLOT(showWidgetA()));
    connect(ui->pushButtonB,SIGNAL(clicked()),this,SLOT(showWidgetB()));

    //ͻ����ʾ����߿�
    ui->frame->setFrameShape(QFrame::Box);
}


void MainWindow::showWidgetA()
{
    widgetB->hide();
    widgetA->show();
}

void MainWindow::showWidgetB()
{
    widgetB->show();
    widgetA->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
