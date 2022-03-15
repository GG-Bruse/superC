#ifndef PLATSCENE_H
#define PLATSCENE_H

#include <QMainWindow>
#include<QMenuBar>
#include<QAction>
#include<QPainter>
#include<QTimer>
#include<QLabel>
#include<mypushbutton.h>
#include<mycoin.h>
#include"dataconfig.h"
#include"mycoin.h"
#include<QPainter>
#include<QSound>

class PlatScene : public QMainWindow
{
    Q_OBJECT
public:
    PlatScene(int levalIndex);
    int levalIndex;//具体选择的关卡号

    //重写绘图事件
    void paintEvent(QPaintEvent *event);

    //二维数组数据
    int gameArray[4][4];

    //硬币按钮数组
    MyCoin* coinBtn[4][4];

    bool isWin = true;//是否胜利

signals:
    void chooseSceneBack();

public slots:
};

#endif // PLATSCENE_H
