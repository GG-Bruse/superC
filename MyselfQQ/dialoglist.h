#ifndef DIALOGLIST_H
#define DIALOGLIST_H

#include <QWidget>
#include<QToolButton>
#include "widget.h"
#include<QMessageBox>

namespace Ui {
class DialogList;
}

class DialogList : public QWidget
{
    Q_OBJECT

public:
    explicit DialogList(QWidget *parent = 0);
    ~DialogList();
    QVector<bool> isShow;//标识窗口是否被打开

private:
    Ui::DialogList *ui;
};

#endif // DIALOGLIST_H
