#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include<QMenuBar>
#include<QAction>
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include<QLabel>
#include<platscene.h>
#include<QSound>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = 0);
    //重写绘图事件
    void paintEvent(QPaintEvent *event);

    //维护一个游戏场景的指针
    PlatScene* playScene = NULL;

signals:
    //点击返回按钮后抛出自定义信号
    void chooseSceneBack();

public slots:
};

#endif // CHOOSELEVELSCENE_H
