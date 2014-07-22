#ifndef CWIDGETA_H
#define CWIDGETA_H

#include <QWidget>

namespace Ui {
    class CWidgetA;
}

class CWidgetA : public QWidget
{
    Q_OBJECT

public:
    explicit CWidgetA(QWidget *parent = 0);
    ~CWidgetA();

private:
    Ui::CWidgetA *ui;
};

#endif // CWIDGETA_H
