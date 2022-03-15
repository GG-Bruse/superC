#include "mainwindow.h"
#include <QApplication>
#include<dataconfig.h>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //测试配置文件
    dataConfig config;
    for(int i =0;i<4;i++)
    {
        for(int j =0 ;j<4;j++)
        {
            qDebug()<<config.mData[1][i][j];
        }
        qDebug()<<endl;

    }

    return a.exec();
}
