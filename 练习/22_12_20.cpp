#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

typedef struct book{
	string ISBN;
	string name;
	string supplier;
	string author;

	bool operator>(const book& bk)const {
		return atoi(ISBN.c_str()) > atoi(bk.ISBN.c_str());
	}
	bool operator==(const book& bk)const {
		return atoi(ISBN.c_str()) == atoi(bk.ISBN.c_str());
	}
}book;


typedef book SQDataType;
typedef struct SeqList
{
	SQDataType* arr;
	int size;
	int capacity;
}SL;

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size >= ps->capacity)
	{
		SQDataType* temp = (SQDataType*)new SQDataType[ps->capacity * 2];
		if (temp == NULL)
		{
			return;
		}
		else
		{
			for (int i = 0; i < ps->size; ++i) {
				temp[i] = ps->arr[i];
			}
			ps->arr = temp;
			ps->capacity *= 2;
		}
	}
}

void SeqListInit(SL* ps)
{
	ps->arr = (SQDataType*)new SQDataType[10];
	if (ps->arr == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = 10;
}

void SeqListDestory(SL* ps)
{
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListInsert(SL* ps, int pos, SQDataType data)
{
	if (pos > ps->size)
	{
		return;
	}
	SeqListCheckCapacity(ps);
	for (int i = ps->size; i > pos; --i)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = data;
	++ps->size;
}

void SeqListErase(SL* ps, int pos)
{
	if (pos >= ps->size)
	{
		return;
	}
	for (int i = pos; i < ps->size - 1; ++i)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	--ps->size;
}

void SeqListPushFront(SL* ps, SQDataType data)
{
	SeqListInsert(ps, 0, data);
}

void SeqListPushBack(SL* ps, SQDataType data)
{
	SeqListInsert(ps, ps->size, data);
}

void SeqListPopFront(SL* ps)
{
	SeqListErase(ps, 0);
}

void SeqListPopBack(SL* ps)
{
	SeqListErase(ps, ps->size - 1);
}

int SeqListFind(SL* ps, SQDataType data)
{
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->arr[i] == data)
		{
			return i;
		}
	}
	return -1;
}


void Swap(book* a, book* b)
{
	book temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(SL* ps, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int exchange = 0;
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (ps->arr[j] > ps->arr[j + 1])
			{
				Swap(&ps->arr[j], &ps->arr[j + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}



void show(const book& bk) {
	cout << endl;
	cout << "                   书名为     :" << bk.name << endl;
	cout << "                   ISNBN码为  :" << bk.ISBN << endl;
	cout << "                   出版社为   :" << bk.supplier << endl;
	cout << "                   作者为     :" << bk.author << endl;
	cout << endl;
}




void test(){
	cout << "||                           1.添加图书信息                           ||" << endl;
	cout << "||                                                                    ||" << endl;
	cout << "||                           2.删除图书信息                           ||" << endl;
	cout << "||                                                                    ||" << endl;
	cout << "||                           3.查找图书信息                           ||" << endl;
	cout << "||                                                                    ||" << endl;
	cout << "||                         4.查看所有图书信息                         ||" << endl;
	cout << "||                                                                    ||" << endl;
	cout << "||                         5.按ISBN码升序排列                         ||" << endl;
	cout << endl;
}
int main()
{
	int input = 0;
	SL sl;
	SeqListInit(&sl);
	do {
		test();
		cout << "请输入你的选择:";
		cin >> input;
		char ch = getchar();//清空缓存区
		int temp;
		book bk;
		switch (input) {
		case 0:
			break;
		case 1:
			cout << "输入IBSN码:";
			cin >> bk.ISBN;
			cout << "输入名称:";
			cin >> bk.name;
			cout << "输入出版社:";
			cin >> bk.supplier;
			cout << "输入作者:";
			cin >> bk.author;
			cout << "输入需要插入的位置:";
			cin >> temp;
			SeqListInsert(&sl, temp - 1, bk);
			cout << endl << "插入成功" << endl;
			break;
		case 2:
			cout << "输入IBSN码:";
			cin >> bk.ISBN;
			temp = SeqListFind(&sl, bk);
			if (temp != -1) 
			{
				SeqListErase(&sl, temp);
				cout << "删除成功" << endl;
			}
			else 
			{
				cout << "不存在该ISBN码的书" << endl;
			}
			break;

		case 3:
			cout << "输入你需查找的书的IBSN码:";
			cin >> bk.ISBN;
			temp = SeqListFind(&sl,bk);
			if (temp == -1)
			{
				cout << "不存在该ISBN码的书" << endl;
			}
			else {
				show(sl.arr[temp]);
			}
			break;

		case 4:
			for (int i = 0; i < sl.size; ++i) {
				show(sl.arr[i]);
			}
			break;
		case 5:
			BubbleSort(&sl, sl.size);
			break;
		}
	} while (input);
	return 0;
}