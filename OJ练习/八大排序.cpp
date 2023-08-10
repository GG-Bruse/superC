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
			int tmp = v[end + gap];//记录要插入的数据
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
void SelectSortPlus(vector<int>& v)
{
	for (int begin = 0, end = v.size() - 1; begin < end; ++begin, --end)
	{
		int minIndex = begin, maxIndex = begin;
		for (int j = begin + 1; j <= end; ++j)
		{
			if (v[j] < v[minIndex]) minIndex = j;
			if (v[j] > v[maxIndex]) maxIndex = j;
		}
		if (minIndex != begin) swap(v[begin], v[minIndex]);
		if (begin == maxIndex) maxIndex = minIndex;//上一行的交换可能改变了最大值的位置
		if (maxIndex != end) swap(v[end], v[maxIndex]);
	}
}










/***************************************************** 堆排序 ****************************************************************/
void AdjustDown(vector<int>& v, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && v[child + 1] > v[child]) ++child;//大堆
		if (v[child] > v[parent]) {
			swap(v[child], v[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}
void HeapSort(vector<int>& v)
{
	for (int i = v.size()/2 - 1; i >= 0; --i) {
		AdjustDown(v, v.size(), i);
	}
	for (int i = v.size() - 1; i > 0; --i) {
		swap(v[0], v[i]);
		AdjustDown(v, i, 0);
	}
}










/**************************************************** 冒泡排序 ************************************************************/
void BubbleSort(vector<int>& v) 
{
	for (int i = 0; i < v.size() - 1; ++i) //一共n - 1趟
	{
		bool exchange = false;
		for (int j = 0; j < v.size() - i - 1; ++j)//最大是 小于v.size() - i
		{
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				exchange = true;
			}
		}
		if (!exchange) break;//一趟下来没有进行任何交换，即已有序
	}
}






/***************************************************** 测试 ***************************************************************/
//int main()
//{
//	vector<int> v1{ 10,9,8,7,6,5,4,3,2,1 };
//	vector<int> v2{ 4,8,1,7,2,5,6,3,10,9 };
//	BubbleSort(v1);
//	BubbleSort(v2);
//	for (auto& it : v1) cout << it << " ";
//	cout << endl;
//	for (auto& it : v2) cout << it << " ";
//	cout << endl;
//	return 0;
//}