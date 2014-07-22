#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//ǰ��������������
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
