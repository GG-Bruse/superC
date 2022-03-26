#include "dialoglist.h"
#include "ui_dialoglist.h"

DialogList::DialogList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogList)
{
    ui->setupUi(this);
    setWindowTitle("包佳毅的QQ");
    setWindowIcon(QPixmap(":/Myself/HeadImage.png"));
    //准备名称
    QList <QString> nameList;
    nameList<<"曾经沧海难为水"<<"除却巫山不是云"<<"愿得一心人"<<"白头不相离"<<"玲珑骰子安红豆"<<"入骨相思知不知"
           <<"只愿君心似我心"<<"定不负相思意"<<"平生不会相思"<<"才会相思"<<"便害相思"<<"十年生死两茫茫"<<"不思量"
          <<"自难忘"<<"山无陵"<<"江水为竭";

    QVector<QToolButton*>vToolButton;

    for(int i = 0;i<16; ++i)
    {
        QToolButton* btn = new QToolButton;
        btn->setText(nameList.at(i));
        QString str = QString(":/Myself/%1.jpg").arg(i+1);
        QPixmap pix(str);
        pix = pix.scaled(pix.height()*2.8,pix.width()*2.8);
        btn->setIcon(pix);
        btn->setIconSize(pix.size());
        btn->setAutoRaise(true);//设置透明的按钮风格
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置按钮的文字和图片一起显示
        //加载到垂直布局中
        ui->vLayout->addWidget(btn);
        //容器保存按钮，便于再次操作
        vToolButton.push_back(btn);
        //16个标识的默认初始化
        isShow.push_back(false);
    }
    for(int i=0;i<vToolButton.size();++i)
    {
        connect(vToolButton[i],&QToolButton::clicked,[=](){
            if(isShow[i])
            {
                QString str = QString("%1的窗口已弹出").arg(vToolButton[i]->text());
                QMessageBox::warning(this,"警告",str);
                return;
            }
            isShow[i] = true;
            //弹出聊天对话框
            Widget* widget = new Widget(0,vToolButton[i]->text());//0以顶层方式弹出，并不依赖某个窗口
            widget->setWindowTitle(vToolButton[i]->text());
            widget->setWindowIcon(vToolButton[i]->icon());
            widget->show();

            connect(widget,&Widget::closeWidget,[=](){
               isShow[i] = false;
            });
        });
    }
}

DialogList::~DialogList()
{
    delete ui;
}
