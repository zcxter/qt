#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    ecgWidget=new PaintWidget;
    ecgWidget_2=new PaintWidget_2;
    ecgWidget_3=new PaintWidget_3;

 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setButton_clicked()
{
    QString content_1 = ui->phonelineEdit->text();
    QString content_2 = ui->codelineEdit->text();
    bs=new Business(this);

    int ret=bs->deviceLogin(content_1,content_2);


    //数据库打开失败、查询失败可以做其他处理
    if(ret==0)
    {
        //数据库打开失败
        ui->messagelabel->setText("数据库打开失败");
    }
    else if(ret==1)
    {
        //不存在此用户
        ui->messagelabel->setText("不存在此用户");
    }
    else if(ret==2)
    {
        //密码错误
        ui->messagelabel->setText("密码错误");
    }
    else
    {
        //登陆成功
        qDebug() << "登陆成功";
        ui->messagelabel->setText("登陆成功");
        ui->stackedWidget->setCurrentIndex(1);
    }
}

static unsigned ecgData[500];
void MainWindow::displayMessage(char *buffer)
{
    char serial[24] = {0};
    memcpy(serial, buffer, 24);
    memcpy(ecgData, buffer+24, 1000);
    delete[] buffer;
    if(flag_1==0)
    {
        qDebug() << serial;
        flag_1=1;
        ui->messagelabel_2->setText("已接收");
    }
}

void MainWindow::on_startButton_clicked()
{
    //获取服务器对象
    Server *ser=Server::getServerInstance();
    quint16 port=ui->portlineEdit->text().toUInt();
    ser->start(port);

    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
}

void MainWindow::on_stopButton_clicked()
{
    Server *ser=Server::getServerInstance();
    ser->stop();

    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

static unsigned short wavaData[500];
void MainWindow::on_waveButton_clicked()
{
    QString serial = ui->comboBox->currentText();
    int w=0,i=0;
    if(serial=="ECG")
    {
        w=1;
    }
    else if(serial=="IBP")
    {
        w=2;
    }
    else if(serial=="SPO")
    {
        w=3;
    }
    else
    {
        return;
    }

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
        qDebug() << query.value(0).toInt();
        qDebug() << query.value(1).toInt();
        qDebug() << query.value(3).toDateTime().toString("yyyy-MM-dd HH:mm:ss");
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
    qDebug() << "end..";
}

void MainWindow::on_pushButton_5_clicked()
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(ecgWidget);
    layout->addWidget(ecgWidget_2);
    layout->addWidget(ecgWidget_3);
    layout->setStretchFactor(ecgWidget,1);
    layout->setStretchFactor(ecgWidget_2,1);
    layout->setStretchFactor(ecgWidget_3,1);
    ui->wavewidget->setLayout(layout);
}
