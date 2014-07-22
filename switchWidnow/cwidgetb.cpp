#include "cwidgetb.h"
#include "ui_cwidgetb.h"

CWidgetB::CWidgetB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetB)
{
    ui->setupUi(this);
}

CWidgetB::~CWidgetB()
{
    delete ui;
}
