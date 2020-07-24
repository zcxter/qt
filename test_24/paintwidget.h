#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPixmap>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);
public slots:
    void refreshPixmap();
protected:
    void paintEvent(QPaintEvent *event);
private:
     QPixmap* pix_;
};

#endif // PAINTWIDGET_H
