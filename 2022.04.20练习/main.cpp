#include<iostream>
#include<string>
#include"realize.h"
#include"Student.h"
using namespace std;
void menu()
{
	cout << "**********************************************" << endl;
	cout << "**********1.���ѧ��****2.ɾ��ѧ��************" << endl;
	cout << "*****  3.�鿴ѧ����Ϣ****4.�޸�ѧ����Ϣ   ****" << endl;
	cout << "******************0.�˳�*******************" << endl;
	cout << "**********************************************" << endl;
}
void test()
{
	int num = 0;
	menu();
	do
	{
		cin >> num;
		switch (num)
		{
		case 1:
			void AddStudent();
			break;
		case 2:
			void DeleteStudent();
			break;
		case 3:
			void SearchStudent();
			break;
		case 4:
			void AmendStudent();
		case 0:
			cout << "�˳�" << endl;
			break;
		default:
			cout << "����������" << endl;
			break;
		}
	} while (num);
}
int main()
{
	test();
	return 0;
}


































