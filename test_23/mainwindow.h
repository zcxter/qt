#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlRelationalTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
#include <QSqlRelation>
#include <QSqlRelationalDelegate>
#include <patientmodel.h>
#include <business.h>
#include <tcpsocket.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_patientButton_clicked();

    void on_deviceButton_clicked();

    void on_bindButton_clicked();

    void on_waveButton_clicked();

    void on_historyButton_clicked();

    void on_binonButton_clicked();

    void on_bindonButton_2_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_selectButton_clicked();

    void on_addButton_2_clicked();

    void on_deleteButton_2_clicked();

    void on_selectButton_2_clicked();

    void on_pushButton_clicked();

    void on_selectButton_4_clicked();

    void on_deleteButton_4_clicked();

    void on_sumButton_clicked();

    void on_selectButton_3_clicked();

    void on_deleteButton_3_clicked();

    void on_connectButton_clicked();

    void sendEcgWave();

    void displayMessage(QString content);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    QSqlQueryModel *model_2;
    QSqlQueryModel *model_3;
    QSqlQueryModel *model_4;
    QSqlQueryModel *patientComboBoxModel;
    QSqlQueryModel *deviceComboBoxModel;
    QSqlRelationalTableModel *patientDeviceModel;
    Business *bs;
    TcpSocket *socket;
    QTimer *timer;
};
#endif // MAINWINDOW_H
