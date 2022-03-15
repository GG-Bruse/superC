#include "mypushbutton.h"

MyPushButton::MyPushButton(QString normarImg,QString pressImg)
{
    this->normalImgPath = normarImg;
    this->pressImgPath = pressImg;

    //QPixmap加载图标
    QPixmap pix;
    bool ret = pix.load(this->normalImgPath);
    if(!ret)
    {
        qDebug()<<"加载失败"<<endl;
        return;
    }
    pix = pix.scaled(pix.width()*1.5,pix.height()*1.5);//图标放大
    //设置区域大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片风格
    this->setStyleSheet("QPushButton{border:0px;}");//0像素
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));

}

void MyPushButton::zoom()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(80);//单位为毫秒
    //设置弹起效果
    animation->setEasingCurve(QEasingCurve::InBounce);
    //设置起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    animation->start(QAbstractAnimation::DeleteWhenStopped);//该参数使得动画完成后，动画对象被释放

}

//重写鼠标按下事件
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath!="")
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret)
        {
            qDebug()<<"加载失败"<<endl;
            return;
        }
        pix= pix.scaled(pix.width()*2,pix.height()*2);
        //设置区域大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片风格
        this->setStyleSheet("QPushButton{border:0px;}");//0像素
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //点击的响应事件抛给父类
    QPushButton::mousePressEvent(e);
}

//重写鼠标释放事件
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgPath!="")
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret)
        {
            qDebug()<<"加载失败"<<endl;
            return;
        }
        pix= pix.scaled(pix.width()*2,pix.height()*2);
        //设置区域大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片风格
        this->setStyleSheet("QPushButton{border:0px;}");//0像素
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //点击的响应事件抛给父类
    QPushButton::mouseReleaseEvent(e);
}













