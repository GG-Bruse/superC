#include "udp2.h"
#include "ui_udp2.h"

Udp2::Udp2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Udp2)
{
    ui->setupUi(this);
    //初始化属性
    ui->myPort->setText("9999");
    ui->toPort->setText("8888");
    ui->toIp->setText("127.0.0.1");

    //创建套接字
    udp = new QUdpSocket(this);
    //绑定自身端口号
    udp->bind(ui->myPort->text().toInt());
    //点击发送按钮，发送报文
    connect(ui->sendBtn,&QPushButton::clicked,[=](){
        udp->writeDatagram(ui->input->toPlainText().toUtf8(),QHostAddress(ui->toIp->text()),ui->toPort->text().toInt());
        ui->record->append("my say:"+ui->input->toPlainText());//加载入聊天记录
        ui->input->clear();//清空输入框
    });
    //接收数据
    connect(udp,&QUdpSocket::readyRead,[=](){
        //获取报文的长度
        qint64 size = udp->pendingDatagramSize();
        //读取报文
        QByteArray array = QByteArray(size,0);
        udp->readDatagram(array.data(),size);
        //将数据同步到聊天记录中
        ui->record->append(array);
    });
}

Udp2::~Udp2()
{
    delete ui;
}
