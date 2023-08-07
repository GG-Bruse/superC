/********************************************************插入排序**********************************************************/

#include <iostream>
#include <vector>
using namespace std;
void InsertSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; ++i)//一共需插入n - 1个
	{
		int end = i;
		int tmp = v[end + 1];//记录要插入的数据
		while (end >= 0)
		{
			if (tmp < v[end]) {
				v[end + 1] = v[end];
				--end;
			}
			else break;//找到数据应该插入的位置
		}
		v[end + 1] = tmp;
	}
}





/*******************************************************希尔排序***********************************************************/

void ShellSort(vector<int>& v)
{
	int gap = v.size();
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < v.size() - gap; ++i)//间隔为gap的为一组进行排序
		{
			int end = i;
			int tmp = v[end + gap];
			while (end >= 0)
			{
				if (tmp < v[end]) {
					v[end + gap] = v[end];
					end -= gap;
				}
				else break;
			}
			v[end + gap] = tmp;
		}
	}
}










/******************************************************* 选择排序 *********************************************************/
void SelectSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < v.size(); ++j) {
			if (v[j] < v[min]) min = j;
		}
		if (min != i) std::swap(v[min], v[i]);
	}
}








/***************************************************** 测试 ***************************************************************/
int main()
{
	vector<int> v1{ 10,9,8,7,6,5,4,3,2,1 };
	vector<int> v2{ 4,8,1,7,2,5,6,3,10,9 };
	SelectSort(v1);
	SelectSort(v2);
	for (auto& it : v1) cout << it << " ";
	cout << endl;
	for (auto& it : v2) cout << it << " ";
	cout << endl;
	return 0;
}