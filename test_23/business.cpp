#include "business.h"

Business::Business(QObject *parent) : QObject(parent)
{

}

//设备登录
void Business::deviceLogin(QString devSerial)
{
    //查询当前设备是否存在
    DataBase *db=DataBase::getDataBaseInstance();
    bool ret= db->queryDeviceBySerial(devSerial);

    //数据库打开失败、查询失败可以做其他处理
    if(!ret)
    {
        //不存在，往数据插入设备数据
        db->insertDevice(devSerial);
    }
    else
    {
        //存在，更新在线时间，登录成功
        db->updateDeviceRefresh(devSerial);
    }
    qDebug() << "登陆成功";
}
