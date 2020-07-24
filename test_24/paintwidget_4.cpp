#include "paintwidget_4.h"

PaintWidget_4::PaintWidget_4(QWidget *parent) : QWidget(parent)
{
    this->resize(800,800);
    pix_=new QPixmap(this->width(),this->height());
    pix_->fill(Qt::black);

}

void PaintWidget_4::refreshPixmap(int datawave[])
{
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

    lineStart.setY((round((double)pix_->height()/2 - (((double)datawave[ecgWaveIndex] - 2048)/600 * pix_->height()/2)))/5);

    ecgWaveIndex+=10;
    if(ecgWaveIndex>=sizeof(datawave)/sizeof(int))
    {
        ecgWaveIndex=0;
    }

    lineEnd.setY((round((double)pix_->height()/2 - (((double)datawave[ecgWaveIndex] - 2048)/600 * pix_->height()/2)))/5);

    painter.drawLine(lineStart,lineEnd);

    this->update();
}

void PaintWidget_4::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix_->width(),pix_->height(),*pix_);
}
