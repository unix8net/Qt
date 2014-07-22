#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sqlthread.h"
#include <QDebug>
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(SQLThread&, QWidget *parent = 0);
    ~MainWindow();\
    void init()
    {

        //qDebug()<<"准备连接到数据库";
        sqlthread.connectDb("myTestDB", "root", "778855");
        //qDebug()<<"准备建表";
        sqlthread.creatTable("tooome");
    }
    void dotask()
    {
        sqlthread.insertData("tooome", 12, 23);
        sqlthread.insertData("tooome", 13, 29);
        sqlthread.insertData("tooome", 14, 23);
        sqlthread.insertData("tooome", 15, 22);
        sqlthread.insertData("tooome", 16, 27);
        sqlthread.insertData("tooome", 17, 23);

    }
    void insertdata()
    {
        sqlthread.insertData("tooome", 72, 23);
        sqlthread.insertData("tooome", 33, 29);
        sqlthread.insertData("tooome", 74, 23);
        sqlthread.insertData("tooome", 15, 22);
        sqlthread.insertData("tooome", 76, 27);
        sqlthread.insertData("tooome", 37, 23);
    }

private:
    Ui::MainWindow *ui;
    SQLThread& sqlthread;
private Q_SLOTS:
     void printInfo(QString s)
     {
         qDebug()<<"AHa: "<<s;
     }
     void mydata(MyVector& vec, int)
     {
        qDebug()<<"size = "<<vec.size();
     }
};

#endif // MAINWINDOW_H
