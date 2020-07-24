#ifndef PAINTWIDGET_2_H
#define PAINTWIDGET_2_H

#include <QWidget>
#include <QTimer>
#include <QPixmap>

class PaintWidget_2 : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget_2(QWidget *parent = nullptr);
public slots:
    void refreshPixmap();
protected:
    void paintEvent(QPaintEvent *event);
private:
     QPixmap* pix_;
};

#endif // PAINTWIDGET_2_H
