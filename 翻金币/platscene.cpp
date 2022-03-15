#include "platscene.h"
#include<QDebug>

PlatScene::PlatScene(int levalIndex)
{
    this->levalIndex =levalIndex;
    qDebug()<<"用户选择的是第"<<levalIndex<<"关"<<endl;

    //菜单栏
    QMenuBar* bar = menuBar();
    QMenu* startMenu = bar->addMenu("开始");//菜单
    QAction* quitAction = startMenu->addAction("退出");//菜单项
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });


    //窗口基本设置
    this->setWindowTitle("请开始你的表演");//设置主窗口标题

    this->setFixedSize(620,888);//设置窗口固定大小

    this->setWindowIcon(QIcon(":/图片资源/Coin0008.png"));//设置主窗口图标


    //准备音效
    QSound* backSound = new QSound(":/图片资源/BackButtonSound.wav",this);
    QSound* filpSound = new QSound(":/图片资源/ConFlipSound.wav",this);
    QSound* winSound = new QSound(":/图片资源/LevelWinSound.wav",this);



    //返回按钮
    QPixmap pix(":/图片资源/BackButton.png");
    MyPushButton* backbtn = new MyPushButton(":/图片资源/BackButton.png",":/图片资源/BackButtonSelected.png");
    backbtn->setParent(this);

    pix= pix.scaled(pix.width()*2,pix.height()*2);
    backbtn->setFixedSize(pix.width(),pix.height());
    //设置不规则图片风格
    backbtn->setStyleSheet("QPushButton{border:0px;}");//0像素
    //设置图标
    backbtn->setIcon(pix);
    //设置图标大小
    backbtn->setIconSize(QSize(pix.width(),pix.height()));

    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());
    connect(backbtn,&MyPushButton::clicked,[=](){
        backSound->play();
        //延时发送信号
        QTimer::singleShot(150,this,[=](){
            emit this->chooseSceneBack();
        });
    });




    //创建具体用户选择关卡的标签
    QLabel* Label = new QLabel;
    Label->setParent(this);
    QString str =QString("Leavel:%1").arg(this->levalIndex);
    Label->setText(str);
    //设置位置和大小
    Label->setGeometry(QRect(30,this->height()-100,200,120));
    //设置字号和字号
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    Label->setFont(font);



    //初始化二维数组
    dataConfig config;
    for(int i = 0;i<4;i++)
    {
        for(int j =0;j<4;j++)
        {
            this->gameArray[i][j] = config.mData[this->levalIndex][i][j];
        }
    }


    //准备胜利图片
    QLabel* winLabel = new QLabel;
    QPixmap tmpPix(":/图片资源/LevelCompletedDialogBg.png");
    tmpPix = tmpPix.scaled(tmpPix.width()*2,tmpPix.height()*2);
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move(this->width()-tmpPix.width()*1.13,-170);




    //创建金币背景图片
    for(int i = 0;i < 4;i++)
    {
        for(int j =0 ;j < 4;j++)
        {
            QPixmap pix(":/图片资源/BoardNode.png");
            pix = pix.scaled(pix.width()*2,pix.height()*2);
            QLabel* lb = new QLabel;
            lb->setGeometry(0,0,pix.width(),pix.height());//设置区域
            lb->setPixmap(pix);
            lb->setParent(this);
            lb->move(115+i*pix.width(),260+j*pix.height());


            //初始化关卡
            QString str;
            if(this->gameArray[i][j] == 1)
            {
                str = ":/图片资源/Coin0001.png";
            }
            else
            {
                str = ":/图片资源/Coin0008.png";
            }
            //创建硬币
            MyCoin* coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(118+i*pix.width(),268+j*pix.height());


            //金币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];

            //将硬币放入二维数组中
            coinBtn[i][j] = coin;

            //监听点击硬币的信号
            connect(coin,&MyCoin::clicked,[=](){
                filpSound->play();
                //将所有按钮屏蔽
                for(int i = 0; i<4;i++)
                {
                    for(int j = 0;j<4;j++)
                    {
                        coinBtn[i][j]->isWin = true;
                    }
                }
                coin->changeFlag();
                //同步二维数组，若以后有保存需求，可以利用数组还原
                this->gameArray[i][j] = this->gameArray[i][j] == 1?0:1;

                //延时翻转周围硬币
                QTimer::singleShot(300,this,[=](){
                    //翻转周围的硬币
                    if(coin->posX+1 <= 3)//检测右侧的硬币是否可以翻转
                    {
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY] == 1?0:1;//同步
                    }
                    if(coin->posX-1 >= 0)//检测左侧的硬币是否可以翻转
                    {
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY] == 1?0:1;
                    }
                    if(coin->posY+1 <= 3)//检测下侧的硬币是否可以翻转
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1] = this->gameArray[coin->posX][coin->posY+1] == 1?0:1;
                    }
                    if(coin->posY-1 >= 0)//检测下侧的硬币是否可以翻转
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1] = this->gameArray[coin->posX][coin->posY-1] == 1?0:1;
                    }

                    //开启硬币可以点击的状态
                    for(int i = 0; i<4;i++)
                    {
                        for(int j = 0;j<4;j++)
                        {
                            coinBtn[i][j]->isWin = false;
                        }
                    }

                    //检测是否胜利
                    isWin = true;
                    for(int i = 0; i<4;i++)
                    {
                        for(int j = 0;j<4;j++)
                        {
                            if(coinBtn[i][j]->flag ==false)//有一个硬币为银币的状态即没有胜利
                            {
                                isWin = false;
                                break;
                            }
                        }
                    }
                    if(isWin)
                    {
                        qDebug()<<"游戏胜利"<<endl;
                        winSound->play();
                        winSound->setLoops(-1);//-1为循环播放
                        for(int i = 0; i<4;i++)
                        {
                            for(int j = 0;j<4;j++)
                            {
                                coinBtn[i][j]->isWin = true;
                            }
                        }
                        //将胜利的图片做成动画
                        QPropertyAnimation* animation = new QPropertyAnimation(winLabel,"geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+224,winLabel->width(),winLabel->height()));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start(QAbstractAnimation::DeleteWhenStopped);
                    }
                });
            });



        }
    }


}


 void PlatScene::paintEvent(QPaintEvent *event)
 {
     QPainter painter(this);
     QPixmap pix(":/图片资源/PlayLevelSceneBg.png");
     painter.drawPixmap(0,0,this->width(),this->height(),pix);
     //加载标题图片
     pix.load(":/图片资源/Title.png");
     pix = pix.scaled(pix.width()*1.2,pix.height()*1.2);
     painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
 }










