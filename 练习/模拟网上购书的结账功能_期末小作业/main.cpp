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
����Ԥ�������˺�,�ֱ�Ϊ
���� ��ͨ�û� 999
���� ���ǻ�Ա 1999
���� �ۿ��ʰٷ�֮��ʮ ��� 2999

������������������û��Ѿ�ѡ����������
*/
int main()
{
	Buyer* objZ = new Ordinary_users("����",999,"����ѧԺ",0);
	Buyer* objL = new member("����", 1999, "����", 0, 3);
	Buyer* objW = new vip("����", 2999, "����", 0, 0.4);
	vector<Buyer*>arr = { objZ,objL,objW };

	Book b1("Effective C++", "2130622004_1", "Scott Meyers","���ӹ�ҵ������_1", 65.0);
	Book b2("C++ Primer", "2130622004_2", "many prople", "���ӹ�ҵ������_2", 128.0);
	vector<Book*>book_arr = { &b1,&b2 };

	string name = "";
	int ID = 0 ,input = 0;

	do
	{
		cout << "��ӭ�������Ϲ���" << endl;
		cout << "���������������Լ���Ա��:" << endl;
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
				cout << "�޸û�Ա��" << endl;

			}
			if (temp == 0 || temp == 1 || temp == 2)
			{
				arr[temp]->print_img();
				arr[temp]->calculation_cost((book_arr[0]->GetPrice()) + (book_arr[1]->GetPrice()));
				book_arr[0]->print_img();
				book_arr[1]->print_img();
				cout << "������Ӧ���ܷ���Ϊ:" << arr[temp]->GetCost() << endl;
			}
		}
		else
		{
			cout << "ϵͳ�����޸��˺�" << endl;
		}
		cout << endl << "����1�������Ϲ���,����0�˳�����" << endl;
		cin >> input;
		system("cls");
	} while (input);

	return 0;
}
