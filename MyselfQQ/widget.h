#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include<QDataStream>
#include<QMessageBox>
#include<QDateTime>
#include<QColorDialog>
#include<QFileDialog>
#include<QFile>
#include<QTextStream>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    enum MsgType{Msg,UsrEnter,UsrLeft};//将发送的消息分为三种类型

public:
    explicit Widget(QWidget *parent,QString name);
    ~Widget();

    void closeEvent(QCloseEvent *event);//关闭事件

private:
    Ui::Widget *ui;

signals:
    //关闭窗口后发送信号
    void closeWidget();

public:
    void sndMsg(MsgType type);//广播upd消息
    void usrEnter(QString username);//处理用户加入
    void usrLeft(QString username,QString time);//处理用户离开
    QString getUsr();//获取用户名
    QString getMsg();//获取聊天信息
private:
    QUdpSocket* udpSocket;//udp套接字
    qint16 port;//端口
    QString uName;//用户名

    void ReceiveMessage();//接收udp消息
};

#endif // WIDGET_H
