#ifndef UDP2_H
#define UDP2_H

#include <QWidget>
#include<QUdpSocket>

namespace Ui {
class Udp2;
}

class Udp2 : public QWidget
{
    Q_OBJECT

public:
    explicit Udp2(QWidget *parent = 0);
    ~Udp2();

private:
    Ui::Udp2 *ui;
public:
    QUdpSocket* udp;
};

#endif // UDP2_H
