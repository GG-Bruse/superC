#include "widget.h"
#include <QApplication>
#include"dialoglist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogList dia;
    dia.show();
    return a.exec();
}
