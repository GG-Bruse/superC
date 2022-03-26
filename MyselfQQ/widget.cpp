#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent,QString name) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //初始化
    udpSocket = new QUdpSocket(this);
    uName = name;
    this->port = 9999;
    //绑定端口号
    udpSocket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);//共享地址与断线重连
    //发送新用户进入
    sndMsg(UsrEnter);

    //点击发送按钮
    connect(ui->sendBtn,&QPushButton::clicked,[=](){
       sndMsg(Msg);
    });
    //监听他人发送的数据
    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::ReceiveMessage);

    //点击退出
    connect(ui->exitBtn,&QPushButton::clicked,[=](){
        this->close();
    });





    /*******************************辅助功能设置**************************/
    //字体
    connect(ui->fontCbx,&QFontComboBox::currentFontChanged,[=](const QFont &f){
            ui->msgTxtEdit->setCurrentFont(f);
            ui->msgTxtEdit->setFocus();
        });


    //字号
    void (QComboBox:: *cbxsignal)(const QString &text) = &QComboBox::currentIndexChanged;
        connect(ui->sizeCbx,cbxsignal,[=](const QString &text){
            ui->msgTxtEdit->setFontPointSize(text.toDouble());
            ui->msgTxtEdit->setFocus();
        });


        //加粗
        connect(ui->boldTBtn,&QToolButton::clicked,[=](bool isBold){
            if(isBold)
            {
               ui->msgTxtEdit->setFontWeight(QFont::Bold);
            }
            else
            {
                ui->msgTxtEdit->setFontWeight(QFont::Normal);
            }
        });


        //倾斜
        connect(ui->italicTBtn,&QToolButton::clicked,[=](bool isItalic){
            ui->msgTxtEdit->setFontItalic(isItalic);
        });


        //下划线
        connect(ui->underlineTBtn,&QToolButton::clicked,[=](bool isUnderline){
            ui->msgTxtEdit->setFontUnderline(isUnderline);
        });


        //字体颜色
        connect(ui->colorTBtn,&QToolButton::clicked,[=](){
            QColor color = QColorDialog::getColor(Qt::red);
            ui->msgTxtEdit->setTextColor(color);
        });


        //清空聊天记录
        connect(ui->clearTBtn,&QToolButton::clicked,[=](){
            ui->msgBrowser->clear();
        });


        //保存聊天记录
        connect(ui->saveTBtn,&QToolButton::clicked,[=](){
            if(ui->msgBrowser->document()->isEmpty())
            {
                QMessageBox::warning(this,"警告","内容不能为空");
                return;
            }
            else
            {
                QString path = QFileDialog::getSaveFileName(this,"保存记录","聊天记录","(*.txt)");
                if(path.isEmpty())
                {
                    QMessageBox::warning(this,"警告","路径不能为空");
                    return;
                }
                else
                {
                    QFile file(path);
                    //打开模式加换行操作
                    file.open(QIODevice::WriteOnly|QIODevice::Text);
                    QTextStream stream(&file);
                    stream<<ui->msgBrowser->toPlainText();
                    file.close();
                }
             }
        });


}

//处理用户加入
void Widget::usrEnter(QString username)//处理新用户加入
{
    //更新右侧Table Widget

    bool isEmpty = ui->usrTblWidget->findItems(username,Qt::MatchExactly).isEmpty();
    if(isEmpty)
    {
        QTableWidgetItem* usr = new QTableWidgetItem(username);
        //插入行
        ui->usrTblWidget->insertRow(0);
        ui->usrTblWidget->setItem(0,0,usr);
        //追加聊天记录
        ui->msgBrowser->setTextColor(Qt::gray);
        ui->msgBrowser->append(QString("%1 上线了").arg(username));

        //在线人数更新
        ui->usrNumLbl->setText(QString("在线用户 ：%1 人").arg(ui->usrTblWidget->rowCount()));

        //把自身信息广播出去
        sndMsg(UsrEnter);
    }
}
//处理用户离开
void Widget::usrLeft(QString username,QString time)
{
    bool isEmpty = ui->usrTblWidget->findItems(username,Qt::MatchExactly).isEmpty();
        if(!isEmpty)
        {
            int row = ui->usrTblWidget->findItems(username,Qt::MatchExactly).first()->row();
            ui->usrTblWidget->removeRow(row);

            //追加聊天信息
            ui->msgBrowser->setTextColor(Qt::gray);
            ui->msgBrowser->append(QString("%1于%2离开").arg(username).arg(time));
            //更新在线人数
            ui->usrNumLbl->setText(QString("在线用户 ：%1 人").arg(ui->usrTblWidget->rowCount()));

        }
}

//接收udp消息
void Widget::ReceiveMessage()
{
    qint64 size = udpSocket->pendingDatagramSize();//获取长度
    QByteArray array = QByteArray(size,0);
    udpSocket->readDatagram(array.data(),size);

    QDataStream stream(&array,QIODevice::ReadOnly);

    int msgType;
    stream>>msgType;//读取到类型

    QString usrName;
    QString msg;
    //获取当前时间
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    switch (msgType) {
    case Msg://普通聊天
        stream>>usrName>>msg;

        //追加聊天记录
        ui->msgBrowser->setTextColor("blue");
        ui->msgBrowser->append("["+usrName+"]"+time);
        ui->msgBrowser->append(msg);
        break;
    case UsrEnter:
        stream>>usrName;
        usrEnter(usrName);
        break;
    case UsrLeft:
        stream>>usrName;
        usrLeft(usrName,time);
        break;
    default:
        break;
    }
}

//发送消息
void Widget::sndMsg(MsgType type)
{
    //发送的数据需做分段处理
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    stream<<type<<getUsr();
    switch (type) {
    case Msg://普通消息
        if(ui->msgTxtEdit->toPlainText()=="")
        {
            QMessageBox::warning(this,"警告","发送内容不可为空");
            return;
        }
        stream<<getMsg();
        break;
    case UsrEnter://用户进入
        break;
    case UsrLeft://用户离开
        break;
    default:
        break;
    }
    //书写报文 广播发送
    udpSocket->writeDatagram(array,QHostAddress::Broadcast,port);
}
//获取聊天信息
QString Widget::getMsg()
{
    QString str = ui->msgTxtEdit->toHtml();
    ui->msgTxtEdit->clear();//清空
    ui->msgTxtEdit->setFocus();//光标返回
    return str;
}
//获取用户名
QString Widget::getUsr()
{
    return this->uName;
}



Widget::~Widget()
{
    delete ui;
}

void Widget::closeEvent(QCloseEvent *event)
{
    emit this->closeWidget();
    sndMsg(UsrLeft);
    //关闭并销毁套接字
    udpSocket->close();
    udpSocket->destroyed();

    QWidget::closeEvent(event);
}
