#include<iostream>
#include<easyx.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib") 
using namespace std;
int main()
{
	//����
	initgraph(640, 480);//���
	//ˢ��
	cleardevice();//����豸

	//1.��������ɫʹ�ú� �ơ���YELLOW ����
	
	//2.����������ɫʹ��RGB(r,g,b)�ϳ�
	RGB(250, 147, 255);

	//���� ����ͷ�ļ�mmsystem.h ���ļ�winmm.lib
	mciSendString("open �տ���Ҳ.mp3", 0, 0, 0);
	mciSendString("play �տ���Ҳ.mp3", 0, 0, 0);
	mciSendString("pause �տ���Ҳ.mp3", 0, 0, 0);
	mciSendString("close �տ���Ҳ.mp3", 0, 0, 0);

	//����
	settextcolor(RGB(250, 147, 255));
	settextstyle(72, 0, "����");//�ߣ���(��������)������
	outtextxy(50,100,"hahaha");//��ָ����λ���������

	//ͼƬ
	/*
	1.��ͨ��ͼ
	*/
	IMAGE bkimg;//����һ��ͼƬ
	loadimage(&bkimg, "pika.jpg");
	putimage(0, 0, &bkimg);
	/*
	2.͸����ͼ
	*/
	
	while (1);
	return 0;
}

