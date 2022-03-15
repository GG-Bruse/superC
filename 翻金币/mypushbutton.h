#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QDebug>
#include<QPropertyAnimation>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //normarImg代表正常显示的图片，pressImg代表按下后显示的图片
    MyPushButton(QString normarImg,QString pressImg = "");
    QString normalImgPath;
    QString pressImgPath;

    //按钮弹起特效
    void zoom();
    //重写鼠标按下事件
    void mousePressEvent(QMouseEvent *e);
    //重写鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
