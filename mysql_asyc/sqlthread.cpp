#include "sqlthread.h"
#include "sql.h"
SQLThread::~SQLThread()
{
    exitFlag = true;
    usedSemaphore.release();
    freeSemaphore.release();
    wait();
}
SQLThread::SQLThread() :
    freeSemaphore(10), usedSemaphore(0)
{
    //10 > 10 + 3
    exitFlag = false;
    rarelyUsed.reserve(3);
    frequentUsed.reserve(10);
}

void SQLThread::run()
{
    bool haveError = false;
    int tryCnt = 3;
    while(true)
    {
        while(rarelyUsed.empty() && frequentUsed.empty())
        {
            usedSemaphore.acquire();
            if(exitFlag)
            {
                rarelyUsed.clear();
                frequentUsed.clear();
                return;
            }
        }

        if(!rarelyUsed.empty())
        {
            //连接数据库
            if( rarelyUsed.front().task == ConnectDb)
            {
                 sql.setDb("test", rarelyUsed.front().user,
                           rarelyUsed.front().passwd);
                 if(!sql.openDb())
                 {
                    emit openError("Can not open the MYSQL database, please cheack...");
                    if(++tryCnt <= 3)
                    {
                        connectDb("test", rarelyUsed.front().user,
                                  rarelyUsed.front().passwd);
                    }
                    else
                        haveError = true;
                    break;
                 }

                 if(!sql.createDb(rarelyUsed.front().name))
                 {
                    emit openError("Create database failure....");
                    break;
                 }

                 if(!sql.changeDb(rarelyUsed.front().name))
                 {
                     emit openError("Change database failure....");
                     break;
                 }

            }
            else if( rarelyUsed.front().task == CreatTable)
            {
                if(! sql.createTable(rarelyUsed.front().name))
                {
                    emit openError("Create table failure....");
                    break;
                }
            }
             else if( rarelyUsed.front().task == SelectData)
            {

                emit getResult(sql.selectTable(rarelyUsed.front().name, cnt), cnt);
            }
            rarelyUsed.pop_front();
            freeSemaphore.release();
            continue;
        }
        //处理第二队列
        if(!frequentUsed.empty())
        {
            sql.insertData(frequentUsed.front().table,
                           frequentUsed.front().id, frequentUsed.front().data);
            frequentUsed.pop_front();
            freeSemaphore.release();
        }
    }
}

//连接数据库
void SQLThread::connectDb(QString db_name, QString user, QString passwd)
{
    freeSemaphore.acquire();
    rarelyUsed.push_back(SQLDataRarelyUsed(db_name,
                                           user, passwd, SQLThread::ConnectDb));
    usedSemaphore.release();

}
//创建表
void SQLThread::creatTable(QString table_)
{
    freeSemaphore.acquire();
    rarelyUsed.push_back(SQLDataRarelyUsed(table_,
                                           SQLThread::CreatTable));
    usedSemaphore.release();

}
void SQLThread::insertData(QString table_, long time_, float data_)
{
    freeSemaphore.acquire();
    frequentUsed.push_back(SQLDataFrequentUsed(
                               table_, time_, data_));
    usedSemaphore.release();

}
void SQLThread::selectTable(QString table_)
{
    freeSemaphore.acquire();
    rarelyUsed.push_back(SQLDataRarelyUsed(table_,
                                           SQLThread::SelectData));
    usedSemaphore.release();
}

