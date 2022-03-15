#include "chooselevelscene.h"
#include<QDebug>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //菜单栏
    QMenuBar* bar = menuBar();
    QMenu* startMenu = bar->addMenu("开始");//菜单
    QAction* quitAction = startMenu->addAction("退出");//菜单项
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });


    //窗口基本设置
    this->setWindowTitle("大帅哥的游戏");//设置主窗口标题

    this->setFixedSize(620,888);//设置窗口固定大小

    this->setWindowIcon(QIcon(":/图片资源/Coin0008.png"));//设置主窗口图标


    //音效的准备
    QSound* chooseSound = new QSound(":/图片资源/TapButtonSound.wav",this);
    QSound* backSound = new QSound(":/图片资源/BackButtonSound.wav",this);

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


    //创建二十个选择关卡的小按钮
    for(int i = 0;i < 20;i++)
    {
        MyPushButton* menuBtn = new MyPushButton(":/图片资源/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(90+(i%4)*120,200+(i/4)*120);

        //创建显示具体关卡号的label
        QLabel* Label = new QLabel;
        Label->setParent(this);
        Label->setFixedSize(menuBtn->width(),menuBtn->height());
        Label->setText(QString::number(i+1));
        Label->move(90+(i%4)*120,200+(i/4)*120);
        Label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//水平并垂直居中
        Label->setAttribute(Qt::WA_TransparentForMouseEvents);//设置鼠标穿透

        connect(menuBtn,&MyPushButton::clicked,[=](){
            chooseSound->play();//播放音效

            playScene = new PlatScene(i+1);

            //设置游戏场景的位置
            this->playScene->setGeometry(this->geometry());

            this->playScene->show();
            this->hide();

            //监听在游戏场景中点击了返回发送的自定义信号
            connect(this->playScene,&PlatScene::chooseSceneBack,[=](){
                this->setGeometry(this->playScene->geometry());
                delete this->playScene;
                this->playScene = NULL;
                this->show();
            });
        });
    }








}

void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //背景
    QPixmap pix(":/图片资源/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //标题
    pix.load(":/图片资源/Title.png");
    pix = pix.scaled(pix.width()*2,pix.height()*1.7);
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
}



