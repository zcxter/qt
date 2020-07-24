#include "tcpsocket.h"
#include <QDebug>
#include <QHostAddress>

TcpSocket::TcpSocket(QObject *parent) : QTcpSocket(parent)
{
    //建立信号槽连接
    connect(this,&TcpSocket::readyRead,
            this,&TcpSocket::receiveMessage);

    //初始化
    length=0;
}

//向服务器发起连接
bool TcpSocket::connectToServer(QString strIp, quint16 port)
{
    bool ret=true;

    //中断当前socket的一切连接，并且复位sokect
    this->abort();

    this->connectToHost(QHostAddress(strIp),port);

    ret=this->waitForConnected();

    return ret;
}

//发送数据
void TcpSocket::sendMessage(QString content)
{
    QByteArray ba=content.toUtf8();
    int nwrite=this->write(ba);
    if(nwrite==-1)
    {
        qDebug() << "send fail";
    }
    else
    {
        qDebug() << "send sucess" << nwrite;
    }
}

//接收数据
void TcpSocket::receiveMessage()
{
    if(length==0)
    {
        //开始接收新的数据包
        buffer=new char[1024];   //申请
        int nread=this->read(buffer,1024);
        length += nread;
    }
    else
    {
        int nread=this->read(buffer+length,1024-length);
        length += nread;
    }

    if(length == 1024)
    {
        //数据包读取结束
        //发送信号
        emit dealMessage(buffer);

        //初始化
        length=0;

        if(this->bytesAvailable()>0)
        {
            //继续解析下一个数据包
            this->receiveMessage();
        }
    }
}
