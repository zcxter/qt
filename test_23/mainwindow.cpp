#include "mainwindow.h"
#include "ui_mainwindow.h"

static const unsigned short int Ecg2_500DemoData[] = {
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2008, 2016, 2016, 2016, 2024, 2032, 2048,
    2064, 2064, 2064, 2072, 2080, 2080, 2080, 2088, 2096, 2104,
    2112, 2112, 2112, 2112, 2112, 2112, 2104, 2096, 2088,
    2080, 2080, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2032,
    2032, 2016, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 1992, 1984, 1976,
    1968, 1960, 1952, 1944, 1936, 1944, 1952, 2016, 2080, 2136,
    2192, 2256, 2320, 2376, 2432, 2488, 2544, 2568, 2592, 2536,
    2480, 2424, 2368, 2304, 2240, 2184, 2128, 2072, 2016, 1968,
    1920, 1928, 1936, 1944, 1952, 1960, 1968, 1984, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2008, 2016, 2024, 2032, 2032,
    2032, 2048, 2064, 2064, 2064, 2072, 2080, 2088, 2096, 2104,
    2112, 2112, 2112, 2120, 2128, 2136, 2144, 2152, 2160, 2160,
    2160, 2160, 2160, 2168, 2176, 2176, 2176, 2184, 2192,
    2192, 2192, 2192, 2200, 2208, 2208, 2208, 2208, 2208, 2208,
    2208, 2200, 2192, 2192, 2192, 2184, 2176, 2176, 2176, 2168,
    2160, 2160, 2160, 2144, 2128, 2128, 2128, 2128, 2128, 2112,
    2096, 2088, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2024,
    2016, 2016, 2016, 2008, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000
};

static    const  unsigned  char Spo2_DemoData[248]  =
{
        0x21,  0x21,  0x22,  0x22,  0x23,  0x22,  0x22,  0x21,  0x21,
        0x20,  0x20,  0x1f,  0x1e,  0x1d,  0x1c,  0x1b,  0x1b,  0x1a,
        0x19,  0x18,  0x18,  0x17,  0x16,  0x15,  0x14,  0x13,  0x12,
        0x11,  0x11,  0x10,  0x10,  0x0f,  0x0f,  0x0e,  0x0d,  0x0c,
        0x0c,  0x0b,  0x0a,  0x09,  0x09,  0x08,  0x07,  0x06,  0x06,
        0x05,  0x05,  0x04,  0x04,  0x03,  0x03,  0x02,  0x02,  0x01,
        0x01,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
        0x00,  0x01,  0x03,  0x06,  0x0a,  0x0e,  0x13,  0x18,  0x1d,
        0x23,  0x28,  0x2d,  0x32,  0x37,  0x3b,  0x40,  0x44,  0x49,
        0x4d,  0x51,  0x54,  0x57,  0x58,  0x5a,  0x5a,  0x5a,  0x59,
        0x59,  0x57,  0x55,  0x52,  0x50,  0x4c,  0x49,  0x45,  0x42,
        0x3e,  0x3b,  0x37,  0x34,  0x31,  0x2f,  0x2c,  0x29,  0x26,
        0x24,  0x22,  0x20,  0x1f,  0x1f,  0x1e,  0x1e,  0x1d,  0x1d,
        0x1e,  0x1f,  0x20,  0x21,  0x21,  0x22,  0x22,  0x23,  0x22,
        0x22,  0x21,  0x21,  0x20,  0x20,  0x1f,  0x1e,  0x1d,  0x1c,
        0x1b,  0x1b,  0x1a,  0x19,  0x18,  0x18,  0x17,  0x16,  0x15,
        0x14,  0x13,  0x12,  0x11,  0x11,  0x10,  0x10,  0x0f,  0x0f,
        0x0e,  0x0d,  0x0c,  0x0c,  0x0b,  0x0a,  0x09,  0x09,  0x08,
        0x07,  0x06,  0x06,  0x05,  0x05,  0x04,  0x04,  0x03,  0x03,
        0x02,  0x02,  0x01,  0x01,  0x00,  0x00,  0x00,  0x00,  0x00,
        0x00,  0x00,  0x00,  0x00,  0x01,  0x03,  0x06,  0x0a,  0x0e,
        0x13,  0x18,  0x1d,  0x23,  0x28,  0x2d,  0x32,  0x37,  0x3b,
        0x40,  0x44,  0x49,  0x4d,  0x51,  0x54,  0x57,  0x58,  0x5a,
        0x5a,  0x5a,  0x59,  0x59,  0x57,  0x55,  0x52,  0x50,  0x4c,
        0x49,  0x45,  0x42,  0x3e,  0x3b,  0x37,  0x34,  0x31,  0x2f,
        0x2c,  0x29,  0x26,  0x24,  0x22,  0x20,  0x1f,  0x1f,  0x1e,
        0x1e,  0x1d,  0x1d,  0x1e,  0x1f,  0x20,  0x21,  0x21,  0x22,
        0x22,  0x23,  0x22,  0x22,  0x21
};

const unsigned short int Ibp2_DemoData[] =
{
  0x0f, 0x10, 0x10, 0x11, 0x12, 0x12, 0x12, 0x13, 0x13,
  0x14, 0x14, 0x14, 0x14, 0x15, 0x17, 0x17, 0x17, 0x18,
  0x18, 0x19, 0x19, 0x19, 0x19, 0x1a, 0x19, 0x1a, 0x1a,
  0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1b, 0x1b, 0x1a, 0x1a,
  0x1a, 0x19, 0x19, 0x18, 0x18, 0x18, 0x17, 0x17, 0x15,
  0x15, 0x15, 0x14, 0x15, 0x14, 0x14, 0x14, 0x15, 0x15,
  0x14, 0x14, 0x15, 0x14, 0x14, 0x14, 0x15, 0x17, 0x17,
  0x17, 0x17, 0x18, 0x18, 0x19, 0x19, 0x19, 0x1a, 0x1b,
  0x1c, 0x1d, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x24,
  0x24, 0x26, 0x26, 0x26, 0x26, 0x24, 0x23, 0x23, 0x23,
  0x23, 0x22, 0x21, 0x20, 0x1d, 0x1d, 0x1c, 0x1c, 0x1c,
  0x1c, 0x1c, 0x1c, 0x1c, 0x1b, 0x1c, 0x1b, 0x1a, 0x1a,
  0x19, 0x18, 0x17, 0x15, 0x14, 0x12, 0x12, 0x11, 0x10,
  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f
};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    ui->patientButton->setMinimumHeight(30);
    ui->deviceButton->setMinimumHeight(30);
    ui->bindButton->setMinimumHeight(30);
    ui->waveButton->setMinimumHeight(30);
    ui->historyButton->setMinimumHeight(30);

    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/40209/Documents/qt/test_23/monitor-cloude.db");
    if(!db.open())
    {
        qDebug() << "打开失败";
    }

    patientComboBoxModel=new QSqlQueryModel(this);
    deviceComboBoxModel=new QSqlQueryModel(this);

    ui->patientcomboBox->setModel(patientComboBoxModel);
    ui->devicecomboBox->setModel(deviceComboBoxModel);

    patientComboBoxModel->setQuery("select patientId from patient where patientId not in (select patientId from patient_device);", db);
    deviceComboBoxModel->setQuery("select dev_serial from device where dev_id not in (select devId from patient_device);", db);

    //绑定列表显示
    patientDeviceModel = new QSqlRelationalTableModel(this,db);
    patientDeviceModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    patientDeviceModel->setTable("patient_device");  // 设置模型操作的表。
    patientDeviceModel->setRelation(1, QSqlRelation("patient", "patientId", "name"));
    patientDeviceModel->setRelation(2, QSqlRelation("device", "dev_id", "dev_serial"));
    patientDeviceModel->select();
    ui->tableView->setModel(patientDeviceModel);

    //代理设置
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));


    //创建模型对象
    model=new PatientModel(this,db);

    //关联模型与表格
    model->setQuery("select * from patient;",db);

    //关联模型与视图
    ui->tableView_2->setModel(model);

    //修改视图的显示方式
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID号"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("姓名"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("性别"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("年龄"));


    //创建模型对象
    model_2=new QSqlQueryModel(this);

    //关联模型与表格
    model_2->setQuery("select * from device;",db);

    //关联模型与视图
    ui->tableView_3->setModel(model_2);

    //修改视图的显示方式
    model_2->setHeaderData(0,Qt::Horizontal,QObject::tr("ID号"));
    model_2->setHeaderData(1,Qt::Horizontal,QObject::tr("设备名"));
    model_2->setHeaderData(2,Qt::Horizontal,QObject::tr("更新时间"));


    //创建模型对象
    model_3=new QSqlQueryModel(this);

    //关联模型与表格
    model_3->setQuery("select * from sample;",db);

    //关联模型与视图
    ui->tableView_5->setModel(model_3);

    //修改视图的显示方式
    model_3->setHeaderData(0,Qt::Horizontal,QObject::tr("样本"));
    model_3->setHeaderData(1,Qt::Horizontal,QObject::tr("设备ID"));
    model_3->setHeaderData(2,Qt::Horizontal,QObject::tr("波形数据"));
    model_3->setHeaderData(3,Qt::Horizontal,QObject::tr("更新时间"));


    //创建模型对象
    model_4=new QSqlQueryModel(this);

    //关联模型与表格
    model_4->setQuery("select * from history;",db);

    //关联模型与视图
    ui->tableView_4->setModel(model_4);

    //修改视图的显示方式
    model_4->setHeaderData(0,Qt::Horizontal,QObject::tr("ID号"));
    model_4->setHeaderData(1,Qt::Horizontal,QObject::tr("更新时间"));
    model_4->setHeaderData(2,Qt::Horizontal,QObject::tr("最大值"));
    model_4->setHeaderData(3,Qt::Horizontal,QObject::tr("最小值"));
    model_4->setHeaderData(4,Qt::Horizontal,QObject::tr("平均值"));
    model_4->setHeaderData(5,Qt::Horizontal,QObject::tr("设备ID"));

    socket=new TcpSocket(this);

    connect(socket,&TcpSocket::dealMessage,
            this,&MainWindow::displayMessage);

    ui->iplineEdit->setText("127.0.0.1");


    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,
            this,&MainWindow::sendEcgWave);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_patientButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_deviceButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_bindButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_waveButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_historyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_binonButton_clicked()
{
    // 病人id
    int patientId = ui->patientcomboBox->currentText().toInt();


    // 设备id
    int devId;
    QString serial = ui->devicecomboBox->currentText();
    QSqlQuery query(db);
    query.prepare("select dev_id from device where dev_serial = :serial;");
    query.bindValue(":serial", QVariant(serial));
    if (!query.exec())
    {
        qDebug() << "绑定失败！";
        QMessageBox::warning(this, "提示", "绑定失败", QMessageBox::Ok);
        return;
    }
    if (query.next())
    {
        devId = query.value(0).toInt();
    }

    // 绑定
    query.prepare("insert into patient_device values(null, :patientId, :devId);");
    query.bindValue(":patientId", patientId);
    query.bindValue(":devId", devId);
    if (!query.exec())
    {
        qDebug() << "绑定失败";
        return ;
    }
    qDebug() << "绑定成功";

    // 刷新绑定列表模型

    // 刷新病人comboBox模型 // 刷新设备comboBox模型
    patientComboBoxModel->setQuery("select patientId from patient where patientId not in (select patientId from patient_device);", db);
    deviceComboBoxModel->setQuery("select dev_serial from device where dev_id not in (select devId from patient_device);", db);

}

void MainWindow::on_bindonButton_2_clicked()
{
    patientDeviceModel->submitAll();
}

void MainWindow::on_addButton_clicked()
{
    QString content_1 = ui->namelineEdit->text();
    QString content_2 = ui->agelineEdit->text();
    QString content_3 = ui->sexlineEdit->text();

    QSqlQuery query(db);
    QString sql="insert into patient values(null,:name,:sex,:age);";
    query.prepare(sql);
    query.bindValue(":name",QVariant(content_1));
    query.bindValue(":sex",QVariant(content_3));
    query.bindValue(":age",QVariant(content_2));
    if(query.exec())
    {
        qDebug() << "插入成功";
    }
    else
    {
        qDebug() << "插入失败";
    }

    model->setQuery("select * from patient;", db);
}

void MainWindow::on_deleteButton_clicked()
{
    QString content = ui->namelineEdit->text();

    QSqlQuery query(db);
    QString sql="delete from patient where name = :name;";
    query.prepare(sql);
    query.bindValue(":name",QVariant(content));
    if(query.exec())
    {
        qDebug() << "删除成功";
    }
    else
    {
        qDebug() << "删除失败";
    }

    model->setQuery("select * from patient;", db);
}

void MainWindow::on_selectButton_clicked()
{
    QString content_1 = ui->namelineEdit->text();
    QString content_2 = ui->agelineEdit->text();
    QString content_3 = ui->sexlineEdit->text();

    QString sql;
    if (!content_1.isEmpty())
    {
        sql = QString("select * from patient where name='%1';").arg(content_1);
    }
    if (!content_2.isEmpty())
    {
        sql = QString("select * from patient where age='%1';").arg(content_2);
    }
    if (!content_3.isEmpty())
    {
        sql = QString("select * from patient where sex='%1';").arg(content_3);
    }
    if (content_1.isEmpty()&&content_2.isEmpty()&&content_3.isEmpty())
    {
        sql = "select * from patient;";
    }

    model->setQuery(sql, db);
}

void MainWindow::on_addButton_2_clicked()
{
    QString content = ui->namelineEdit_2->text();
    bs=new Business(this);
    bs->deviceLogin(content);

    model_2->setQuery("select * from device;", db);
}

void MainWindow::on_deleteButton_2_clicked()
{
    QString content = ui->namelineEdit_2->text();

    QSqlQuery query(db);
    QString sql="delete from device where dev_serial = :name;";
    query.prepare(sql);
    query.bindValue(":name",QVariant(content));
    if(query.exec())
    {
        qDebug() << "删除成功";
    }
    else
    {
        qDebug() << "删除失败";
    }

    model_2->setQuery("select * from device;", db);
}

void MainWindow::on_selectButton_2_clicked()
{
    QString content = ui->namelineEdit_2->text();

    QString sql;
    if (content.isEmpty())
    {
        sql = "select * from device;";
    }
    else
    {
        sql = QString("select * from device where dev_serial='%1';").arg(content);
    }

    model_2->setQuery(sql, db);
}

void MainWindow::on_pushButton_clicked()
{
    QString content = ui->namelineEdit_3->text();

    QByteArray ba;
    unsigned char ch;
    for(int i=0;i<sizeof(Ecg2_500DemoData);i++)
    {
        ch=(Ecg2_500DemoData[i] >> 8)&0xff;
        ba.append(ch);
        ch=Ecg2_500DemoData[i]&0xff;
        ba.append(ch);
    }

    QSqlQuery query(db);
    QString sql="insert into sample values(null,:name,:waveData,datetime('now','localtime'));";
    query.prepare(sql);
    query.bindValue(":name",QVariant(content));
    query.bindValue(":waveData",QVariant(ba));
    if(query.exec())
    {
        qDebug() << "插入成功";
    }
    else
    {
        qDebug() << "插入失败";
    }

    model_3->setQuery("select * from sample;", db);
}


void MainWindow::on_selectButton_4_clicked()
{
    QString content = ui->namelineEdit_3->text();

    QString sql;
    if (content.isEmpty())
    {
        sql = "select * from sample;";
    }
    else
    {
        sql = QString("select * from sample where devId ='%1';").arg(content);
    }

    model_3->setQuery(sql, db);
}

void MainWindow::on_deleteButton_4_clicked()
{
    QString content = ui->namelineEdit_3->text();

    QSqlQuery query(db);
    QString sql="delete from sample where devId = :name;";
    query.prepare(sql);
    query.bindValue(":name",QVariant(content));
    if(query.exec())
    {
        qDebug() << "删除成功";
    }
    else
    {
        qDebug() << "删除失败";
    }

    model_3->setQuery("select * from sample;", db);
}

void MainWindow::on_sumButton_clicked()
{
    QString content = ui->namelineEdit_4->text();

    int max=0,min=0,sum=0,flag=0;
    for(int i=0;i<500;i++)
    {
        if(flag==0)
        {
            min=max=Ecg2_500DemoData[0];
            flag=1;
        }
        if(Ecg2_500DemoData[i]>max)
        {
            max=Ecg2_500DemoData[i];
        }
        if(Ecg2_500DemoData[i]<min)
        {
            min=Ecg2_500DemoData[i];
        }
        sum+=Ecg2_500DemoData[i];
    }

    QSqlQuery query(db);
    QString sql="insert into history values(null,datetime('now','localtime'),:max,:min,:avg,:name);";
    query.prepare(sql);
    query.bindValue(":name",QVariant(content));
    query.bindValue(":max",max);
    query.bindValue(":min",min);
    query.bindValue(":avg",sum/500);
    if(query.exec())
    {
        qDebug() << "插入成功";
    }
    else
    {
        qDebug() << "插入失败";
    }

    model_4->setQuery("select * from history;", db);
}

void MainWindow::on_selectButton_3_clicked()
{
    QString content = ui->namelineEdit_4->text();

    QString sql;
    if (content.isEmpty())
    {
        sql = "select * from history;";
    }
    else
    {
        sql = QString("select * from history where devId ='%1';").arg(content);
    }

    model_4->setQuery(sql, db);
}

void MainWindow::on_deleteButton_3_clicked()
{
    QString content = ui->namelineEdit_4->text();

    QSqlQuery query(db);
    QString sql="delete from history where devId = :name;";
    query.prepare(sql);
    query.bindValue(":name",QVariant(content));
    if(query.exec())
    {
        qDebug() << "删除成功";
    }
    else
    {
        qDebug() << "删除失败";
    }

    model_4->setQuery("select * from history;", db);
}

void MainWindow::on_connectButton_clicked()
{
    QString strIp=ui->iplineEdit->text();
    quint16 port=ui->portlineEdit->text().toUInt();
    int ret=socket->connectToServer(strIp,port);
    if(ret)
    {

        qDebug() << "连接成功";
        timer->start(2);
    }
    else
    {
        qDebug() << "连接失败";
    }
}

void MainWindow::sendEcgWave()
{
    QString content = ui->namelineEdit_3->text();
    QString serial_1 = ui->comboBox->currentText();

    QByteArray ba = content.toLatin1();
    char* buffer = new char[1024];
    char* serial = ba.data();

    // 内存处理字节,大小端（忽略）
    memcpy(buffer,serial ,24);
    if(serial_1=="ECG")
    {
        memcpy(buffer+24, Ecg2_500DemoData, 1000);
    }
    else if(serial_1=="SPO")
    {
        memcpy(buffer+24, Spo2_DemoData, 1000);
    }
    else if(serial_1=="IBP")
    {
        memcpy(buffer+24, Ibp2_DemoData, 1000);
    }
    else
    {
        qDebug() << "没有发送任何数据";
    }

    socket->sendMessage(buffer);
}

void MainWindow::displayMessage(QString content)
{

}

void MainWindow::on_pushButton_2_clicked()
{
    QString content = ui->namelineEdit_3->text();

    QByteArray ba;
    unsigned char ch;
    for(int i=0;i<sizeof(Spo2_DemoData)/2;i++)
    {
        ch=Spo2_DemoData[i];
        ba.append(ch);
    }

    QSqlQuery query(db);
    QString sql="insert into sample values(null,:name,:waveData,datetime('now','localtime'));";
    query.prepare(sql);
    query.bindValue(":name",QVariant(content));
    query.bindValue(":waveData",QVariant(ba));
    if(query.exec())
    {
        qDebug() << "插入成功";
    }
    else
    {
        qDebug() << "插入失败";
    }

    model_3->setQuery("select * from sample;", db);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString content = ui->namelineEdit_3->text();

    QByteArray ba;
    unsigned char ch;
    for(int i=0;i<sizeof(Ibp2_DemoData)/2;i++)
    {
        ch=Ibp2_DemoData[i];
        ba.append(ch);
    }

    QSqlQuery query(db);
    QString sql="insert into sample values(null,:name,:waveData,datetime('now','localtime'));";
    query.prepare(sql);
    query.bindValue(":name",QVariant(content));
    query.bindValue(":waveData",QVariant(ba));
    if(query.exec())
    {
        qDebug() << "插入成功";
    }
    else
    {
        qDebug() << "插入失败";
    }

    model_3->setQuery("select * from sample;", db);
}
