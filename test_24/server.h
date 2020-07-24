#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <tcpsocket.h>
#include <tcpserver.h>
#include <QList>

class Server : public QObject
{
    Q_OBJECT
public:
    //获取服务器
    static Server *getServerInstance();

    //启动服务器
    void start(quint16 port);

    //关闭服务器
    void stop();

    //添加
    void addClient(TcpSocket *c);

    //获取socket
    QList<TcpSocket *> getClients();
private:
    explicit Server(QObject *parent = nullptr);
    TcpServer *pTcpServer;
    QList<TcpSocket *> clients;
};

#endif // SERVER_H
