#ifndef PAINTWIDGET_3_H
#define PAINTWIDGET_3_H

#include <QWidget>
#include <QTimer>
#include <QPixmap>

class PaintWidget_3 : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget_3(QWidget *parent = nullptr);
public slots:
    void refreshPixmap();
protected:
    void paintEvent(QPaintEvent *event);
private:
     QPixmap* pix_;
};

#endif // PAINTWIDGET_H
