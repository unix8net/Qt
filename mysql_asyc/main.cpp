#include "mainwindow.h"
#include <QApplication>
#include <QMetaType>

#include "sqlthread.h"
#include <windows.h>
#include "sql.h"
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    qRegisterMetaType<MyVector>("MyVector");
    qRegisterMetaType<MyVector>("MyVector&");
    SQLThread sqlthread;
    sqlthread.start();
    Sleep(1000);
    MainWindow w(sqlthread);
    w.init();
    w.dotask();
    w.insertdata();
    w.show();
    sqlthread.selectTable("tooome");
    /*
    SQL sql;
    sql.setDb("test", "root", "778855");
    if(!sql.openDb())
    {
        qDebug()<<"4";
    }
    if(!sql.createDb("myTestDb"))
    {
        qDebug()<<"2";
    }
    if(!sql.changeDb("myTestDb"))
    {
        qDebug()<<"3";
    }
*/

    return a.exec();
}
