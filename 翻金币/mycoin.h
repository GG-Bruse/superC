#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include<QDebug>
#include<QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    MyCoin(QString imgPath);//参数为默认显示图片的路径

    int posX;
    int posY;
    bool flag;//正反标志

    void changeFlag();//改变标志，执行翻转效果
    QTimer* time1;//正面翻反面 定时器
    QTimer* time2;//反面翻正面 定时器
    int min = 1;//最小图片
    int max = 8;//最大图片

    bool isAnimation = false;//做翻转动画的标志

    //重写鼠标按下的事件
    void mousePressEvent(QMouseEvent *e);

    bool isWin = false;//是否胜利的状态值


signals:

public slots:
};

#endif // MYCOIN_H
