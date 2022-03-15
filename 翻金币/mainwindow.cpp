#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //主场景的基本配置
    this->setWindowTitle("包佳毅的翻金币游戏");//设置主窗口标题

    this->setFixedSize(620,888);//设置窗口固定大小

    this->setWindowIcon(QIcon(":/图片资源/Coin0001.png"));//设置主窗口图标

    //点击菜单中的退出实现退出游戏
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });




    //创建选择关卡的场景
    choosescene = new ChooseLevelScene;

    //监听选择关卡场景中的返回按钮的自定义信号
    connect(choosescene,&ChooseLevelScene::chooseSceneBack,[=](){
        this->setGeometry(choosescene->geometry());
        this->show();
        choosescene->hide();
    });



    //开始音效的准备
    QSound* startSound = new QSound(":/图片资源/TapButtonSound.wav",this);



    //开始按钮
    MyPushButton* startBtn = new MyPushButton(":/图片资源/MenuSceneStartButton.png");
    startBtn->move(this->width()*0.5 -startBtn->width()*0.5,this->height()*0.7);
    startBtn->setParent(this);//依赖

    connect(startBtn,&MyPushButton::clicked,[=](){
        startSound->play();//播放音效
        startBtn->zoom();
        QTimer::singleShot(260,this,[=](){//延时，避免用户无法观测到按钮弹起的特效
            choosescene->setGeometry(this->geometry());//设置选择关卡场景的位置
            this->hide();//主场景隐藏
            choosescene->show();//选择关卡场景显示
        });
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPixmap pix(":/图片资源/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题图片
    pix.load(":/图片资源/Title.png");
    pix = pix.scaled(pix.width()*1.5,pix.height()*1.5);
    painter.drawPixmap(10,30,pix);
}
