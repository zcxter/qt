#include "mainwindow.h"

#include <QApplication>

MainWindow *pw;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    pw=&w;
    w.show();
    return a.exec();
}
