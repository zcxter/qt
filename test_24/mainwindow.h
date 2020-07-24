#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <business.h>
#include <server.h>
#include <paintwidget.h>
#include <paintwidget_2.h>
#include <paintwidget_3.h>
#include <paintwidget_4.h>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void displayMessage(char *buffer);
private slots:
    void on_setButton_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_waveButton_clicked();

    void on_pushButton_5_clicked();
private:
     QPixmap* pix_;
private:
    Ui::MainWindow *ui;
    Business *bs;
    PaintWidget *ecgWidget;
    PaintWidget_2 *ecgWidget_2;
    PaintWidget_3 *ecgWidget_3;
    int flag_1=0;
};
#endif // MAINWINDOW_H
