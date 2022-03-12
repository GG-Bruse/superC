#include "udp1.h"
#include <QApplication>
#include "udp2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Udp1 w;
    w.show();
    Udp2 z;
    z.show();
    return a.exec();
}
