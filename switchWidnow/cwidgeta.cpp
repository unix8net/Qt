#include "cwidgeta.h"
#include "ui_cwidgeta.h"

CWidgetA::CWidgetA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWidgetA)
{
    ui->setupUi(this);
}

CWidgetA::~CWidgetA()
{
    delete ui;
}
