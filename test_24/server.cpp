#include "server.h"

void Server::start(quint16 port)
{
    //启动监听
    if(!pTcpServer->listen(QHostAddress::Any,port))
    {
        qDebug() << "监听失败：" << pTcpServer->errorString();
    }
    else
    {
        qDebug() << "监听成功";
    }
}

void Server::stop()
{
    //清空连接通信socket
    clients.clear();

    //关闭服务器
    pTcpServer->close();
}

void Server::addClient(TcpSocket *c)
{
    clients.append(c);
}

QList<TcpSocket *> Server::getClients()
{
    return clients;
}

//获取服务器
Server *Server::getServerInstance()
{
    static Server ser;
    return &ser;
}

Server::Server(QObject *parent) : QObject(parent)
{
    pTcpServer=new TcpServer(this);
}
