#ifndef SQL_H
#define SQL_H

#include <QVector>
#include <QPointF>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
/*==================================================================
 *    作者：Creater
 *    简介： 数据库操作接口
 *    主页： unix8.net
 *    日期：2014-04-27
/*==================================================================*/



typedef QVector<QPointF> MyVector;
Q_DECLARE_METATYPE(MyVector)


class SQL
{
private:
    QSqlDatabase db;
    //当前的表
    QString table;
    QString dbname;
    MyVector vec;
public:

    ~SQL(){db.close();}
    SQL(){ db = QSqlDatabase::addDatabase("QMYSQL");}
    void setDb(QString db_name, QString user, QString pw);
    bool openDb();
    bool changeDb(QString db_name);
    bool createDb(QString db_name);
    bool createTable(QString table_);
    bool insertData(QString table_, long t, float d);
    MyVector& selectTable(QString table, int& s);
    MyVector&  getResult();
    SQL(QSqlDatabase& db_):db(db_){ vec.reserve(1441);}
};

#endif

