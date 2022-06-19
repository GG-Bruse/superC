#include <iostream>
#include<string>
#include<vector>
#include<Windows.h>

#include"Buyer.h"
#include"Ordinary_users.h"
#include"member.h"
#include"vip.h"
#include"Book.h"

using namespace std;
/*
本例预留三个账号,分别为
张三 普通用户 999
李四 三星会员 1999
王五 折扣率百分之四十 贵宾 2999

本例依题意假设所有用户已经选择了两本书
*/
int main()
{
	Buyer* objZ = new Ordinary_users("张三",999,"贺州学院",0);
	Buyer* objL = new member("李四", 1999, "广西", 0, 3);
	Buyer* objW = new vip("王五", 2999, "湖南", 0, 0.4);
	vector<Buyer*>arr = { objZ,objL,objW };

	Book b1("Effective C++", "2130622004_1", "Scott Meyers","电子工业出版社_1", 65.0);
	Book b2("C++ Primer", "2130622004_2", "many prople", "电子工业出版社_2", 128.0);
	vector<Book*>book_arr = { &b1,&b2 };

	string name = "";
	int ID = 0 ,input = 0;

	do
	{
		cout << "欢迎进行网上购书" << endl;
		cout << "请输入您的姓名以及会员号:" << endl;
		cin >> name >> ID;
		if ((name == arr[0]->GetName()) || (name == arr[1]->GetName()) || (name == arr[2]->GetName()))
		{
			int temp = 4;
			if (ID == 999)
				temp = 0;
			else if (ID == 1999)
				temp = 1;
			else if (ID == 2999)
				temp = 2;
			else
			{
				cout << "无该会员号" << endl;

			}
			if (temp == 0 || temp == 1 || temp == 2)
			{
				arr[temp]->print_img();
				arr[temp]->calculation_cost((book_arr[0]->GetPrice()) + (book_arr[1]->GetPrice()));
				book_arr[0]->print_img();
				book_arr[1]->print_img();
				cout << "购书人应付总费用为:" << arr[temp]->GetCost() << endl;
			}
		}
		else
		{
			cout << "系统中暂无该账号" << endl;
		}
		cout << endl << "输入1重新网上购书,输入0退出程序" << endl;
		cin >> input;
		system("cls");
	} while (input);

	return 0;
}
