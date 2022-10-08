#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include"LinkList.h"

void menu()
{
	printf("--------------------------------------------------\n");
	printf("                    通讯录管理                    \n");
	printf("                                                  \n");
	printf("                1.通讯录链表的建立                \n");
	printf("                2.通讯者结点的插入                \n");
	printf("                3.通讯者结点的查询                \n");
	printf("                4.通讯者结点的删除                \n");
	printf("                5.通讯录链表的输出                \n");
	printf("                0.退出管理系统                    \n");
	printf("--------------------------------------------------\n");
}

int main()
{
	int choice = 0;
	SLDataType temp;
	char find_num[5] = { 0 };
	menu();
	do
	{
		printf("请选择你要实现的功能(0-5):");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			printf("已退出系统\n");
			break;
		case 1: break;
		case 2:
			printf("输入将插入结点的信息(编号、姓名、性别、电话、地址)\n");
			scanf("%s%s%s%s%s", &temp.num, &temp.name, &temp.sex, &temp.phone, &temp.addr);
			SListPushBack(&head,temp);
			break;
		case 3:
			printf("输入你要查询的结点的编号\n");
			scanf("%s", &find_num);
			pos = SListFind(head, find_num);
			printf("编号：%s  姓名：%s  性别：%s  电话：%s  地址：%s\n", pos->data.num, pos->data.name, pos->data.sex, pos->data.phone, pos->data.addr);
			break;
		case 4:
			printf("输入你要删除的结点的编号\n");
			scanf("%s", &find_num);
			pos = SListFind(head, find_num);
			SListErase(&head, pos);
			break;
		case 5:
			SListPrint(head);
			break;
		}
	} while (choice);
	return 0;
}

