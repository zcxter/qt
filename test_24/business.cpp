#include "business.h"

Business::Business(QObject *parent) : QObject(parent)
{

}

//设备登录
int Business::deviceLogin(QString phone,QString code)
{
    //查询当前设备是否存在
    DataBase *db=DataBase::getDataBaseInstance();
    int ret= db->queryDeviceBySerial(phone,code);

    return ret;
}
