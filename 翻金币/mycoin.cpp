#include "mycoin.h"


MyCoin::MyCoin(QString imgPath)
{
    QPixmap pix;
    bool ret = pix.load(imgPath);
    pix = pix.scaled(pix.width()*2,pix.height()*2);
    if(!ret)
    {
        qDebug()<<"加载失败"<<endl;
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //创建两个定时器
    time1 = new QTimer(this);
    time2 = new QTimer(this);
    //监听两个定时器的timeout信号
    //金币翻银币
    connect(time1,&QTimer::timeout,[=](){
        QString str = QString(":/图片资源/Coin000%1").arg(min++);
        QPixmap pix;
        bool ret = pix.load(str);
        pix = pix.scaled(pix.width()*2,pix.height()*2);
        if(!ret)
        {
            qDebug()<<"加载失败"<<endl;
            return;
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(min>max)
        {
            this->min = 1;//还原最小值
            this->isAnimation = false;//标志动画停止
            time1->stop();//定时器停止
        }
    });
    //银币翻金币
    connect(time2,&QTimer::timeout,[=](){
        QString str = QString(":/图片资源/Coin000%1").arg(max--);
        QPixmap pix;
        bool ret = pix.load(str);
        pix = pix.scaled(pix.width()*2,pix.height()*2);
        if(!ret)
        {
            qDebug()<<"加载失败"<<endl;
            return;
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(min>max)
        {
            this->max = 8;//还原最小值
            this->isAnimation = false;//标志动画停止
            time2->stop();//定时器停止
        }
    });


}



//改变硬币的状态
void MyCoin::changeFlag()
{
    if(this->flag == true)
    {
        //启动金币翻银币的定时器
        time1->start(30);
        this->isAnimation = true;//正在完成动画
        this->flag = false;
    }
    else
    {
        //启动银币翻金币的定时器
        time2->start(30);
        this->isAnimation = true;//正在完成动画
        this->flag = true;

    }

}

//重写鼠标按下的事件
void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->isWin)
    {
        return;//若正在完成动画。期间不响应点击事件
    }
    else
    {
        QPushButton::mousePressEvent(e);//抛给父类
    }
}



