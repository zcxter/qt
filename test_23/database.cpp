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

bool DataBase::queryDeviceBySerial(QString serial)
{
    bool ret=true;
    //打开数据库
    if(!db.open())
    {
        return false;
    }

    //执行sql
    QString sql="select * from device where dev_serial = :serial;";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":serial",QVariant(serial));
    if(!query.exec())
    {
        qDebug() << "select fail:" << query.lastError().text();
        ret=false;
        goto regTag;
    }
    if(!query.next())
    {
        ret=false;
    }
    //关闭数据库
regTag:
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
