#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include"mypushbutton.h"
#include"chooselevelscene.h"
#include<QTimer>
#include<QSound>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //利用绘图事件绘制背景
    void paintEvent(QPaintEvent* event);
    //维护一个选择关卡场景的指针
    ChooseLevelScene* choosescene;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
