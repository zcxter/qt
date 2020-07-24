#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>

class TcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpSocket(QObject *parent = nullptr);
    bool connectToServer(QString strIp,quint16 port);
    void sendMessage(QString content);
public slots:
    void receiveMessage();
signals:
    void dealMessage(char *buffer);
private:
    int length;
    char *buffer;
};

#endif // TCPSOCKET_H
