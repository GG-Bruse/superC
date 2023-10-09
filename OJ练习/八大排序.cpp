/********************************************************插入排序**********************************************************/

#include <iostream>
#include <vector>
#include <stack>
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
	for (int i = v.size()/2 - 1; i >= 0; --i) {//从最后一个非叶子结点开始进行向下调整，建堆
		AdjustDown(v, v.size(), i);
	}
	for (int i = v.size() - 1; i > 0; --i) {//根节点与当前未排序的最后一个进行交换，交换完后的新根节点向下调整
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
		for (int j = 0; j < v.size() - i - 1; ++j)//j + 1, 最大是 小于v.size()
		{
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				exchange = true;
			}
		}
		if (!exchange) break;//一趟下来没有进行任何交换，即已有序
	}
}














/***************************************************** 快速排序（Hoare）******************************************************/
void QuickSort_1(vector<int>& v, int left, int right)
{
	if (left >= right) return;

	int begin = left, end = right;
	int keyIndex = begin;
	while (begin < end)//若选用最左边的值为key，一定要right先进行移动；若选用最右边的值为key,一定要left先动
	{
		while (begin < end && v[end] >= v[keyIndex]) --end;//找小
		while (begin < end && v[begin] <= v[keyIndex]) ++begin;//找大
		swap(v[begin], v[end]);
	}
	swap(v[begin], v[keyIndex]);
	QuickSort_1(v, left, begin - 1);
	QuickSort_1(v, begin + 1, right);
}
















/****************************************************** 快速排序（挖坑法）****************************************************/
void QuickSort_2(vector<int>& v, int left, int right)
{
	if (left >= right) return;

	int begin = left, end = right;
	int keyValue = v[begin];
	while (begin < end)
	{
		while (begin < end && v[end] >= keyValue) --end;
		v[begin] = v[end];
		while (begin < end && v[begin] <= keyValue) ++begin;
		v[end] = v[begin];
	}
	v[begin] = keyValue;
	QuickSort_2(v, left, begin - 1);
	QuickSort_2(v, begin + 1, right);
}
















/************************************************** 快速排序（前后指针法）****************************************************/
//通过current指针找到所有比key小的值，通过prev指针一个个放在前面
void QuickSort_3(vector<int>& v, int left, int right)
{
	if (left >= right) return;

	int keyIndex = left;
	int current = left + 1, prev = left;
	while (current <= right)
	{
		if (v[current] < v[keyIndex] && ++prev != current) swap(v[current], v[prev]);
		++current;
	}
	swap(v[prev], v[keyIndex]);
	QuickSort_3(v, left, prev - 1);
	QuickSort_3(v, prev + 1, right);
}












/***************************************************** 快速排序（非递归）*****************************************************/
int GetMid(vector<int>& v, int left, int right);

void QuickSort_4(vector<int>& v)
{
	stack<int> sk;
	sk.push(v.size() - 1);
	sk.push(0);

	while (!sk.empty())
	{
		int left = sk.top();
		sk.pop();
		int right = sk.top();
		sk.pop();

		//单趟挖坑法
		swap(v[left], v[GetMid(v, left, right)]);
		int begin = left, end = right;
		int keyValue = v[begin];
		while (begin < end)
		{
			while (begin < end && v[end] >= keyValue) --end;
			v[begin] = v[end];
			while (begin < end && v[begin] <= keyValue) ++begin;
			v[end] = v[begin];
		}
		v[begin] = keyValue;

		if (left < begin - 1) {//左区间加入
			sk.push(begin - 1);
			sk.push(left);
		}
		if (right > begin + 1) {//右区间加入
			sk.push(right);
			sk.push(begin + 1);
		}
	}
}














/**********************************************************三数取中优化*******************************************************/
int GetMid(vector<int>& v, int left, int right)
{
	int mid = (left + right) >> 1;
	if (v[left] < v[mid])
	{
		if (v[mid] < v[right]) return mid;
		else if (v[left] > v[right]) return left;
		else return right;
	}
	else//v[left] > v[mid]
	{
		if (v[mid] > v[right]) return mid;
		else if (v[right] > v[left]) return left;
		else return right;
	}
}










/********************************************************** 归并排序 *********************************************************/
void _MergeSort(vector<int>& v, int left, int right, vector<int>& tmp)
{
	if (left >= right) return;
	//分解
	int mid = (left + right) >> 1;
	_MergeSort(v, left, mid, tmp);
	_MergeSort(v, mid + 1, right, tmp);
	//合并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (v[begin1] < v[begin2]) tmp[index++] = v[begin1++];
		else tmp[index++] = v[begin2++];
	}
	while (begin1 <= end1) tmp[index++] = v[begin1++];
	while (begin2 <= end2) tmp[index++] = v[begin2++];
	//将归并好的数据拷贝回原vector
	for (int i = left; i <= right; ++i) v[i] = tmp[i];
}
void MergeSort(vector<int>& v)
{
	vector<int> tmp(v.size());
	_MergeSort(v, 0, v.size() - 1, tmp);
}











/*********************************************************** 归并排序（非递归）**********************************************************/
void MergeSort_S(vector<int>& v)
{
	vector<int> tmp(v.size());

	int gap = 1;//每组数据个数
	while (gap < v.size())
	{
		for (int i = 0; i < v.size(); i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int current = i;

			if (end1 >= v.size()) {
				end1 = v.size() - 1;
				begin2 = v.size();//右区间不合法
				end2 = v.size() - 1;
			}
			else if (begin2 >= v.size()) {
				begin2 = v.size();//右区间不合法
				end2 = v.size() - 1;
			}
			else if (end2 >= v.size()) end2 = v.size() - 1;

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (v[begin1] < v[begin2]) tmp[current++] = v[begin1++];
				else tmp[current++] = v[begin2++];
			}
			while (begin1 <= end1) tmp[current++] = v[begin1++];
			while (begin2 <= end2) tmp[current++] = v[begin2++];
		}
		for (int j = 0; j < v.size(); ++j) v[j] = tmp[j];
		gap *= 2;
	}
}











/******************************************************* 计数排序 *********************************************************/
void CountSort(vector<int>& v)
{
	int max = v[0];
	int min = v[0];
	for (auto it : v) {
		if (it > max) max = it;
		if (it < min) min = it;
	}

	int range = max - min + 1;
	vector<int> count(range, 0);
	for (int i = 0; i < v.size(); ++i) ++count[v[i] - min];

	int current = 0;
	for (int i = 0; i < range; ++i) {
		while (count[i]--) v[current++] = i + min;
	}
}










/***************************************************** 测试 ***************************************************************/
//int main()
//{
//	vector<int> v1{ 10,9,8,7,6,5,4,3,2,1 };
//	vector<int> v2{ 4,8,1,7,2,5,6,3,10,9 };
//	vector<int> v3{ 5,2,3,1 };
//	vector<int> v4{ -4, 0, 7, 4, 9, -5, -1, 0, -7, -1 };
//	MerageSortx(v1);
//	MerageSortx(v2);
//	MerageSortx(v3);
//	MerageSortx(v4);
//	for (auto& it : v1) cout << it << " ";
//	cout << endl;
//	for (auto& it : v2) cout << it << " ";
//	cout << endl;
//	for (auto& it : v3) cout << it << " ";
//	cout << endl;
//	for (auto& it : v4) cout << it << " ";
//	cout << endl;
//	return 0;
//}