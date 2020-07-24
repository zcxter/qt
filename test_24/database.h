#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <header.h>

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    static DataBase* getDataBaseInstance();

    //查询序列号
    int queryDeviceBySerial(QString phone,QString code);
    //插入设备
    bool insertDevice(QString serial);

    //更新在线时间
    bool updateDeviceRefresh(QString serial);
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
