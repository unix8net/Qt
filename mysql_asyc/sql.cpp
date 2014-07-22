#include "sql.h"
void SQL::setDb(QString db_name, QString user, QString pw)
{
    dbname = db_name;
    db.setDatabaseName(db_name);
    db.setHostName("localhost");
    db.setUserName(user);
    db.setPassword(pw);
}

bool SQL::openDb()
{
    return db.open();
}

bool SQL::changeDb(QString db_name)
{
    QSqlQuery query;
    dbname = db_name;
    QString s = "use  "+ db_name;
    return query.exec(s);
}

bool SQL::createDb(QString db_name)
{
     QSqlQuery query;
    dbname = db_name;
    QString s = "Create Database If Not Exists  " + db_name;
    return query.exec(s);
}

bool SQL::createTable(QString table_)
{
    QSqlQuery query;
    table = table_;
    QString s = "CREATE TABLE   If Not Exists "+ table+ "(id INTEGER PRIMARY KEY, data float )";
    return query.exec(s);
}
bool SQL::insertData(QString table_, long t, float d)
{
    QSqlQuery query;
    QString s = "INSERT INTO " + table_+"(id, data) VALUES (:id, :data)";
    query.prepare(s);
    query.bindValue(":id", QString("%1").arg(t));
    query.bindValue(":data", d);
    return query.exec();
}
MyVector& SQL::selectTable(QString table, int& cnt)
{
    QSqlQuery query;
    QString s = "SELECT id, data FROM " + table;
    query.exec(s);
    cnt = s.size();
    vec.clear();
    while (query.next())
    {
        vec.push_back(QPointF(query.value(0).toInt(),query.value(1).toFloat()));
       // qDebug()<<"id("<<query.value(0).toInt()<<")  data:"<<query.value(1).toFloat();
    }
    return vec;
}
MyVector& SQL::getResult()
{
    return vec;
}
