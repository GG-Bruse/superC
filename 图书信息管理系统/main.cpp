#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include "handle_information.h"



enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT1,
	SORT2,
	STA,
	FIND,
	CLEAR,
	LOAD,
	SAVE
};
void menu()
{
	cout << "\t\t\t\t\t\t************************************************************************" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                          ͼ����Ϣ����ϵͳ                          **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t************************************************************************" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                           1.���ͼ����Ϣ                           **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                        2.��ISBN��ɾ��ͼ����Ϣ                      **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                        3.��ISBN�����ͼ����Ϣ                      **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                           4.�޸�ͼ����Ϣ                           **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                         5.�鿴����ͼ����Ϣ                         **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                    6.������ͼ����Ϣ��ISBN����������                **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t************************************************************************" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                    7.������ͼ����Ϣ��ISBN�뽵������                **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                      8.ͳ�������鼮�����뵥���ܺ�                  **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                           9.�ؼ��ֲ���                             **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                         10.�������ͼ����Ϣ                        **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                         11.��������ͼ����Ϣ                        **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                         12.��������ͼ����Ϣ                        **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                       0.�˳�ͼ����Ϣ����ϵͳ                       **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t************************************************************************" << endl;
}

void full_screen()//�̶�����
{
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);           
	int cy = GetSystemMetrics(SM_CYSCREEN);           
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);  
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_THICKFRAME );
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}
void Update_interface() {//ˢ�½���
	int ret = 0;
	while (true) {
		cout << endl << "����0��������:";
		cin >> ret;
		if (ret == 0) {
			system("cls");
			break;
		}
		else cout << "�����������������!" << endl;
	}
	
}

int main()
{
	full_screen();

	int input = 0;
	vector<book> v;
	load_information(v);
	do {
		menu();
		cout << "���������ѡ��:";
		cin >> input;
		char ch = getchar();//��ջ�����

		book bk;
		string tmp;
		int pos = 0;
		int temp = 0;
		bool res;
		vector<int> total;
		pair<size_t, double> ret;

		switch (input) {
		case EXIT:
			save(v);
			break;

		case ADD:
			cout << "��ʼ¼��ѧ����Ϣ" << endl;
			cout << "��������IBSN��:";
			cin >> bk.ISBN;
			cout << "������������:";
			cin >> bk.name;
			cout << "�������ĳ�����:";
			cin >> bk.supplier;
			cout << "������������:";
			cin >> bk.author;
			cout << "������������:";
			cin >> bk._quantity;
			cout << "�������ļ۸�:";
			cin >> bk._price;
			cout << "��������Ҫ�����λ��:";
			cin >> temp;
			
			pos = search(v, bk.ISBN);
			if (pos == -1) {
				if (res = add_book(v, bk, temp - 1)) {
					cout << "¼��ɹ�!" << endl;
				}
			}
			else {
				cout << endl << "¼��ʧ�� , ��ISBN���Ѿ�����!!!" << endl;
			}
			
			Update_interface();
			break;

		case DEL:
			cout << "��������ɾ�������IBSN��:";
			cin >> tmp;
			pos = search(v, tmp);
			if (pos == -1) cout << "δ�ҵ��������Ϣ" << endl;
			else {
				v.erase(v.begin() + pos);
				cout << "ɾ���ɹ�!" << endl;
			}
			Update_interface();
			break;

		case SEARCH:
			cout << "����������ҵ����IBSN��:";
			cin >> tmp;
			pos = search(v, tmp);
			if (pos == -1) cout << "δ�ҵ��������Ϣ" << endl;
			else {
				cout << v[pos] << endl;
			}
			Update_interface();
			break;

		case MODIFY:
			cout << "���������޸ĵ����IBSN��:";
			cin >> tmp;
			pos = search(v, tmp);
			cout << "��ʼ�޸�!" << endl;
			bk.ISBN = v[pos].ISBN;
			cout << "������������:";
			cin >> bk.name;
			cout << "�������ĳ�����:";
			cin >> bk.supplier;
			cout << "������������:";
			cin >> bk.author;
			cout << "������������:";
			cin >> bk._quantity;
			cout << "�������ļ۸�:";
			cin >> bk._price;
			v[pos] = bk;
			cout << "�޸ĳɹ�!" << endl;
			Update_interface();
			break;

		case SHOW:
			show(v);
			Update_interface();
			break;

		case SORT1:
			Sort(v);
			cout << "�������!" << endl;
			Update_interface();
			break;
		case SORT2:
			Sort_2(v);
			cout << "�������!" << endl;
			Update_interface();
			break;

		case STA:
			ret = statistics(v);
			cout << "\t\t\t\t\t\t************************************************************************" << endl;
			cout << "\t\t\t\t\t\t             �鼮�����ۺ�Ϊ     :" << ret.first << endl;
			cout << endl;
			cout << "\t\t\t\t\t\t             �鼮�����ۺ�Ϊ     :" << ret.second << endl;
			cout << "\t\t\t\t\t\t************************************************************************" << endl;
			Update_interface();
			break;
		case FIND:
			cout << "����ؼ���:";
			cin >> tmp;
			total = find_by_key(v, tmp);
			if (total.size() == 0) {
				cout << "δ�ҵ������Ϣ!!!" << endl;
			}
			else {
				for (size_t i = 0; i < total.size(); ++i) {
					cout << v[total[i]];
				}
			}
			Update_interface();
			break;

		case CLEAR:
			v.clear();
			cout << endl << "�ѳɹ����!!!" << endl;
			Update_interface();
			break;

		case SAVE:
			save(v);
			cout << "����ɹ�!!!" << endl;
			Update_interface();
			break;

		case LOAD:
			load_six(v);
			cout << endl << "����ɹ�!!!" << endl;
			Update_interface();
			break;

		default:
			cout << "ѡ�����,����������!" << endl;
			break;
		}
	} while (input);
	save(v);
	return 0;
}