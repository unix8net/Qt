#ifndef CWIDGETB_H
#define CWIDGETB_H

#include <QWidget>

namespace Ui {
    class CWidgetB;
}

class CWidgetB : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetB(QWidget *parent = 0);
    ~CWidgetB();

private:
    Ui::CWidgetB *ui;
};

#endif // CWIDGETB_H
