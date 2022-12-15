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
	cout << "\t\t\t\t\t\t**                          图书信息管理系统                          **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t************************************************************************" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                           1.添加图书信息                           **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                        2.按ISBN码删除图书信息                      **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                        3.按ISBN码查找图书信息                      **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                           4.修改图书信息                           **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                         5.查看所有图书信息                         **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                    6.将所有图书信息按ISBN码升序排列                **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t************************************************************************" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                    7.将所有图书信息按ISBN码降序排列                **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                      8.统计所有书籍数量与单价总和                  **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                           9.关键字查找                             **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                         10.清空所有图书信息                        **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                         11.载入六条图书信息                        **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                         12.保存所有图书信息                        **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                       0.退出图书信息管理系统                       **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t**                                                                    **" << endl;
	cout << "\t\t\t\t\t\t************************************************************************" << endl;
}

void full_screen()//固定满屏
{
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);           
	int cy = GetSystemMetrics(SM_CYSCREEN);           
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);  
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_THICKFRAME );
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}
void Update_interface() {//刷新界面
	int ret = 0;
	while (true) {
		cout << endl << "输入0继续操作:";
		cin >> ret;
		if (ret == 0) {
			system("cls");
			break;
		}
		else cout << "输入错误，请重新输入!" << endl;
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
		cout << "请输入你的选择:";
		cin >> input;
		char ch = getchar();//清空缓存区

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
			cout << "开始录入学生信息" << endl;
			cout << "输入该书的IBSN码:";
			cin >> bk.ISBN;
			cout << "输入该书的名称:";
			cin >> bk.name;
			cout << "输入该书的出版社:";
			cin >> bk.supplier;
			cout << "输入该书的作者:";
			cin >> bk.author;
			cout << "输入该书的数量:";
			cin >> bk._quantity;
			cout << "输入该书的价格:";
			cin >> bk._price;
			cout << "输入你需要插入的位置:";
			cin >> temp;
			
			pos = search(v, bk.ISBN);
			if (pos == -1) {
				if (res = add_book(v, bk, temp - 1)) {
					cout << "录入成功!" << endl;
				}
			}
			else {
				cout << endl << "录入失败 , 该ISBN码已经存在!!!" << endl;
			}
			
			Update_interface();
			break;

		case DEL:
			cout << "输入你需删除的书的IBSN码:";
			cin >> tmp;
			pos = search(v, tmp);
			if (pos == -1) cout << "未找到该书的信息" << endl;
			else {
				v.erase(v.begin() + pos);
				cout << "删除成功!" << endl;
			}
			Update_interface();
			break;

		case SEARCH:
			cout << "输入你需查找的书的IBSN码:";
			cin >> tmp;
			pos = search(v, tmp);
			if (pos == -1) cout << "未找到该书的信息" << endl;
			else {
				cout << v[pos] << endl;
			}
			Update_interface();
			break;

		case MODIFY:
			cout << "输入你需修改的书的IBSN码:";
			cin >> tmp;
			pos = search(v, tmp);
			cout << "开始修改!" << endl;
			bk.ISBN = v[pos].ISBN;
			cout << "输入该书的名称:";
			cin >> bk.name;
			cout << "输入该书的出版社:";
			cin >> bk.supplier;
			cout << "输入该书的作者:";
			cin >> bk.author;
			cout << "输入该书的数量:";
			cin >> bk._quantity;
			cout << "输入该书的价格:";
			cin >> bk._price;
			v[pos] = bk;
			cout << "修改成功!" << endl;
			Update_interface();
			break;

		case SHOW:
			show(v);
			Update_interface();
			break;

		case SORT1:
			Sort(v);
			cout << "排序完成!" << endl;
			Update_interface();
			break;
		case SORT2:
			Sort_2(v);
			cout << "排序完成!" << endl;
			Update_interface();
			break;

		case STA:
			ret = statistics(v);
			cout << "\t\t\t\t\t\t************************************************************************" << endl;
			cout << "\t\t\t\t\t\t             书籍数量综合为     :" << ret.first << endl;
			cout << endl;
			cout << "\t\t\t\t\t\t             书籍单价综合为     :" << ret.second << endl;
			cout << "\t\t\t\t\t\t************************************************************************" << endl;
			Update_interface();
			break;
		case FIND:
			cout << "输入关键字:";
			cin >> tmp;
			total = find_by_key(v, tmp);
			if (total.size() == 0) {
				cout << "未找到相关信息!!!" << endl;
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
			cout << endl << "已成功清空!!!" << endl;
			Update_interface();
			break;

		case SAVE:
			save(v);
			cout << "保存成功!!!" << endl;
			Update_interface();
			break;

		case LOAD:
			load_six(v);
			cout << endl << "载入成功!!!" << endl;
			Update_interface();
			break;

		default:
			cout << "选择错误,请重新输入!" << endl;
			break;
		}
	} while (input);
	save(v);
	return 0;
}