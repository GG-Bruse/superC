#include<iostream>
#include<string>
#include"realize.h"
#include"Student.h"
using namespace std;
void menu()
{
	cout << "**********************************************" << endl;
	cout << "**********1.添加学生****2.删除学生************" << endl;
	cout << "*****  3.查看学生信息****4.修改学生信息   ****" << endl;
	cout << "******************0.退出*******************" << endl;
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
			cout << "退出" << endl;
			break;
		default:
			cout << "请重新输入" << endl;
			break;
		}
	} while (num);
}
int main()
{
	test();
	return 0;
}


































