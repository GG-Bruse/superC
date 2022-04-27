#include<iostream>
#include<easyx.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib") 
using namespace std;
int main()
{
	//窗口
	initgraph(640, 480);//宽高
	//刷新
	cleardevice();//清除设备

	//1.常见的颜色使用宏 黄——YELLOW ……
	
	//2.不常见的颜色使用RGB(r,g,b)合成
	RGB(250, 147, 255);

	//音乐 包含头文件mmsystem.h 库文件winmm.lib
	mciSendString("open 空空如也.mp3", 0, 0, 0);
	mciSendString("play 空空如也.mp3", 0, 0, 0);
	mciSendString("pause 空空如也.mp3", 0, 0, 0);
	mciSendString("close 空空如也.mp3", 0, 0, 0);

	//文字
	settextcolor(RGB(250, 147, 255));
	settextstyle(72, 0, "仿宋");//高，宽(无需设置)，字体
	outtextxy(50,100,"hahaha");//在指定的位置输出文字

	//图片
	/*
	1.普通绘图
	*/
	IMAGE bkimg;//定义一张图片
	loadimage(&bkimg, "pika.jpg");
	putimage(0, 0, &bkimg);
	/*
	2.透明绘图
	*/
	
	while (1);
	return 0;
}

