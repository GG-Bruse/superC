#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include"LinkList.h"

void menu()
{
	printf("--------------------------------------------------\n");
	printf("                    ͨѶ¼����                    \n");
	printf("                                                  \n");
	printf("                1.ͨѶ¼����Ľ���                \n");
	printf("                2.ͨѶ�߽��Ĳ���                \n");
	printf("                3.ͨѶ�߽��Ĳ�ѯ                \n");
	printf("                4.ͨѶ�߽���ɾ��                \n");
	printf("                5.ͨѶ¼��������                \n");
	printf("                0.�˳�����ϵͳ                    \n");
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
		printf("��ѡ����Ҫʵ�ֵĹ���(0-5):");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			printf("���˳�ϵͳ\n");
			break;
		case 1: break;
		case 2:
			printf("���뽫���������Ϣ(��š��������Ա𡢵绰����ַ)\n");
			scanf("%s%s%s%s%s", &temp.num, &temp.name, &temp.sex, &temp.phone, &temp.addr);
			SListPushBack(&head,temp);
			break;
		case 3:
			printf("������Ҫ��ѯ�Ľ��ı��\n");
			scanf("%s", &find_num);
			pos = SListFind(head, find_num);
			printf("��ţ�%s  ������%s  �Ա�%s  �绰��%s  ��ַ��%s\n", pos->data.num, pos->data.name, pos->data.sex, pos->data.phone, pos->data.addr);
			break;
		case 4:
			printf("������Ҫɾ���Ľ��ı��\n");
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

