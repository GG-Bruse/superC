#include<iostream>
#include<string>
#include"StackArray.h"
using namespace std;
bool isLeft(char ch)
{
	return ch == '(';
}
bool isRight(char ch)
{
	return ch == ')';
}
void printError(char* str, string errMsg, char* pos)
{
	cout << "������Ϣ:" << errMsg << endl;
	cout << str << endl;
	int num = pos - str;
	for (int i = 0; i < num; ++i)
	{
		cout << " ";
	}
	cout << "~" << endl;
}
int main()
{
	char* str = (char*)"5 + 5 * (6) + 9 / 3 * 1 - ( 1 + 310";
	char* p = str;
	Stack sk;
	while (*p != '\0')
	{
		if (isLeft(*p))
		{
			sk.top_back(p);
		}
		if (isRight(*p))
		{
			if (sk.size() > 0)
			{
				sk.pop_back();
			}
			else
			{
				printError(str, "������û��ƥ�䵽��Ӧ��������", p);
			}
		}
		++p;
	}
	while (sk.size() > 0)
	{
		printError(str, "������û��ƥ�䵽������", (char*)sk.top());
		sk.pop_back();
	}
	return 0;
}