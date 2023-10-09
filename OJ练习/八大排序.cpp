/********************************************************��������**********************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void InsertSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; ++i)//һ�������n - 1��
	{
		int end = i;
		int tmp = v[end + 1];//��¼Ҫ���������
		while (end >= 0)
		{
			if (tmp < v[end]) {
				v[end + 1] = v[end];
				--end;
			}
			else break;//�ҵ�����Ӧ�ò����λ��
		}
		v[end + 1] = tmp;
	}
}









/*******************************************************ϣ������***********************************************************/

void ShellSort(vector<int>& v)
{
	int gap = v.size();
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < v.size() - gap; ++i)//���Ϊgap��Ϊһ���������
		{
			int end = i;
			int tmp = v[end + gap];//��¼Ҫ���������
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













/******************************************************* ѡ������ *********************************************************/
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
		if (begin == maxIndex) maxIndex = minIndex;//��һ�еĽ������ܸı������ֵ��λ��
		if (maxIndex != end) swap(v[end], v[maxIndex]);
	}
}














/***************************************************** ������ ****************************************************************/
void AdjustDown(vector<int>& v, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && v[child + 1] > v[child]) ++child;//���
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
	for (int i = v.size()/2 - 1; i >= 0; --i) {//�����һ����Ҷ�ӽ�㿪ʼ�������µ���������
		AdjustDown(v, v.size(), i);
	}
	for (int i = v.size() - 1; i > 0; --i) {//���ڵ��뵱ǰδ��������һ�����н��������������¸��ڵ����µ���
		swap(v[0], v[i]);
		AdjustDown(v, i, 0);
	}
}












/**************************************************** ð������ ************************************************************/
void BubbleSort(vector<int>& v) 
{
	for (int i = 0; i < v.size() - 1; ++i) //һ��n - 1��
	{
		bool exchange = false;
		for (int j = 0; j < v.size() - i - 1; ++j)//j + 1, ����� С��v.size()
		{
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				exchange = true;
			}
		}
		if (!exchange) break;//һ������û�н����κν�������������
	}
}














/***************************************************** ��������Hoare��******************************************************/
void QuickSort_1(vector<int>& v, int left, int right)
{
	if (left >= right) return;

	int begin = left, end = right;
	int keyIndex = begin;
	while (begin < end)//��ѡ������ߵ�ֵΪkey��һ��Ҫright�Ƚ����ƶ�����ѡ�����ұߵ�ֵΪkey,һ��Ҫleft�ȶ�
	{
		while (begin < end && v[end] >= v[keyIndex]) --end;//��С
		while (begin < end && v[begin] <= v[keyIndex]) ++begin;//�Ҵ�
		swap(v[begin], v[end]);
	}
	swap(v[begin], v[keyIndex]);
	QuickSort_1(v, left, begin - 1);
	QuickSort_1(v, begin + 1, right);
}
















/****************************************************** ���������ڿӷ���****************************************************/
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
















/************************************************** ��������ǰ��ָ�뷨��****************************************************/
//ͨ��currentָ���ҵ����б�keyС��ֵ��ͨ��prevָ��һ��������ǰ��
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












/***************************************************** �������򣨷ǵݹ飩*****************************************************/
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

		//�����ڿӷ�
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

		if (left < begin - 1) {//���������
			sk.push(begin - 1);
			sk.push(left);
		}
		if (right > begin + 1) {//���������
			sk.push(right);
			sk.push(begin + 1);
		}
	}
}














/**********************************************************����ȡ���Ż�*******************************************************/
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










/********************************************************** �鲢���� *********************************************************/
void _MergeSort(vector<int>& v, int left, int right, vector<int>& tmp)
{
	if (left >= right) return;
	//�ֽ�
	int mid = (left + right) >> 1;
	_MergeSort(v, left, mid, tmp);
	_MergeSort(v, mid + 1, right, tmp);
	//�ϲ�
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
	//���鲢�õ����ݿ�����ԭvector
	for (int i = left; i <= right; ++i) v[i] = tmp[i];
}
void MergeSort(vector<int>& v)
{
	vector<int> tmp(v.size());
	_MergeSort(v, 0, v.size() - 1, tmp);
}











/*********************************************************** �鲢���򣨷ǵݹ飩**********************************************************/
void MergeSort_S(vector<int>& v)
{
	vector<int> tmp(v.size());

	int gap = 1;//ÿ�����ݸ���
	while (gap < v.size())
	{
		for (int i = 0; i < v.size(); i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int current = i;

			if (end1 >= v.size()) {
				end1 = v.size() - 1;
				begin2 = v.size();//�����䲻�Ϸ�
				end2 = v.size() - 1;
			}
			else if (begin2 >= v.size()) {
				begin2 = v.size();//�����䲻�Ϸ�
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











/******************************************************* �������� *********************************************************/
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










/***************************************************** ���� ***************************************************************/
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