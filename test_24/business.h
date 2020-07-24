#ifndef BUSINESS_H
#define BUSINESS_H

#include <QObject>
#include <database.h>
#include <QDebug>

class Business : public QObject
{
    Q_OBJECT
public:
    explicit Business(QObject *parent = nullptr);
    int deviceLogin(QString phone, QString code);
};

#endif // BUSINESS_H
