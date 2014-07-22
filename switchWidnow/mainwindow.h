#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//前置声明两个窗体
class CWidgetA;
class CWidgetB;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void showWidgetA();
    void showWidgetB();
private:
    Ui::MainWindow *ui;
    CWidgetA* widgetA;
    CWidgetB* widgetB;
};

#endif // MAINWINDOW_H
