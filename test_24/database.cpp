#include "database.h"


DataBase::DataBase(QObject *parent) : QObject(parent)
{
    //判断数据库是否已经添加
    if(QSqlDatabase::contains("device_connection"))
    {
        db=QSqlDatabase::database("device_connection");
    }
    else
    {
        //加载驱动
        db=QSqlDatabase::addDatabase("QSQLITE","device_connection");

        //设置数据库名
        db.setDatabaseName("C:/Users/40209/Documents/qt/test_23/monitor-cloude.db");
    }
}

DataBase *DataBase::getDataBaseInstance()
{
    static DataBase database;
    return &database;
}

int DataBase::queryDeviceBySerial(QString phone, QString code)
{
    int ret=0;
    //打开数据库
    if(!db.open())
    {
        return ret;
    }

    //执行sql
    QString sql="select * from doctor where phone = :phone;";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":phone",QVariant(phone));
    if(!query.exec())
    {
        qDebug() << "select fail:" << query.lastError().text();
        ret=0;
        db.close();
        return ret;
    }
    if(!query.next())
    {
        ret=1;
        db.close();
        return ret;
    }

    QString sql_2="select * from doctor where code = :code;";
    QSqlQuery query_2(db);
    query_2.prepare(sql_2);
    query_2.bindValue(":code",QVariant(code));
    if(!query_2.exec())
    {
        qDebug() << "select fail:" << query_2.lastError().text();
        ret=0;
        db.close();
        return ret;
    }
    if(!query_2.next())
    {
        ret=2;
        db.close();
        return ret;
    }
    ret=3;
    //关闭数据库
    db.close();
    return ret;
}

bool DataBase::insertDevice(QString serial)
{
    bool ret=true;
    //打开数据库
    if(!db.open())
    {
        return false;
    }
    //执行sql
    QString sql="insert into device values(NULL, :serial, datetime('now','localtime'));";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":serial", QVariant(serial));
    if (!query.exec())
    {
        qDebug() << "insert fail:" << query.lastError().text();
        ret = false;
    }

    // 关闭数据库
    db.close();
    return ret;
}

bool DataBase::updateDeviceRefresh(QString serial)
{
    bool ret=true;
    //打开数据库
    if(!db.open())
    {
        return false;
    }
    //执行sql
    QString sql="update device set refresh = datetime('now','localtime') where dev_serial= :serial;";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":serial", QVariant(serial));
    if (!query.exec())
    {
        qDebug() << "insert fail:" << query.lastError().text();
        ret = false;
    }

    // 关闭数据库
    db.close();
    return ret;
}
