#ifndef PAINTWIDGET_4_H
#define PAINTWIDGET_4_H

#include <QWidget>
#include <QPainter>
#include <QColor>

class PaintWidget_4 : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget_4(QWidget *parent = nullptr);
public:
    void refreshPixmap(int datawave[]);
protected:
    void paintEvent(QPaintEvent *event);
private:
     QPixmap* pix_;
};

#endif // PAINTWIDGET_4_H
