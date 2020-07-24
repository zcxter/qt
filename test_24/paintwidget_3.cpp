#include "paintwidget_3.h"
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QColor>
#include <mainwindow.h>

PaintWidget_3::PaintWidget_3(QWidget *parent) : QWidget(parent)
{
    this->resize(800,800);
    pix_=new QPixmap(this->width(),this->height());
    pix_->fill(Qt::black);

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(refreshPixmap()));
    timer->start(10);
}

static unsigned wavaData[500];
void PaintWidget_3::refreshPixmap()
{
    int i=0,w=3;
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE","device_connection");

    //设置数据库名
    db.setDatabaseName("C:/Users/40209/Documents/qt/test_23/monitor-cloude.db");

    if(!db.open())
    {
        return;
    }

    QByteArray ba;
    unsigned char ch;

    QSqlQuery query(db);
    QString sql="select * from sample;";
    query.exec(sql);
    while(query.next())
    {
        query.value(0).toInt();
        query.value(1).toInt();
        query.value(3).toDateTime().toString("yyyy-MM-dd HH:mm:ss");
        ba=query.value(2).toByteArray();
        if(w==1)
        {
            i+=2;
        }
        else if(w==2)
        {
            i+=1;
        }
        else
        {
            w=2;
        }
        if(i==2)
        {
            break;
        }
    }
    unsigned short usValue =0;
    int cnt=0;
    for(int i=0;i<ba.size();i+=2)
    {
        usValue=0;
        ch=ba.at(i);
        usValue |= (ch << 8);
        ch=ba.at(i+1);
        usValue |= ch&0xff;

        wavaData[cnt++]=usValue;
    }

    static int index;
    static int ecgWaveIndex;

    QPainter painter(pix_);
    painter.setPen(QPen(QColor(0,255,0),2));

    painter.save();
    painter.setPen(Qt::black);
    painter.drawLine(index,0,index,pix_->height());
    painter.drawLine(index+1,0,index+1,pix_->height());
    painter.drawLine(index+2,0,index+2,pix_->height());
    painter.drawLine(index+3,0,index+3,pix_->height());
    painter.restore();

    index=index+2;
    if(index>pix_->width())
    {
        index=2;
    }

    QPoint lineStart;
    QPoint lineEnd;
    lineStart.setX(index-2);
    lineEnd.setX(index);

    lineStart.setY((round((double)pix_->height()/2 - (((double)wavaData[ecgWaveIndex] - 2048)/600 * pix_->height()/2)))/200+60);

    ecgWaveIndex+=10;
    if(ecgWaveIndex>=sizeof(wavaData)/sizeof(int))
    {
        ecgWaveIndex=0;
    }

    lineEnd.setY((round((double)pix_->height()/2 - (((double)wavaData[ecgWaveIndex] - 2048)/600 * pix_->height()/2)))/200+60);

    painter.drawLine(lineStart,lineEnd);

    this->update();
}

void PaintWidget_3::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix_->width(),pix_->height(),*pix_);
}
