#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class UnionFindSet
{
public:
	UnionFindSet(size_t size):_ufs(size, -1) {}

	int FindRoot(int value)
	{
		int root = value;
		while (_ufs[root] >= 0) root = _ufs[root];
		//·��ѹ��
		while (_ufs[value] >= 0)
		{
			int parent = _ufs[value];
			_ufs[value] = root;
			value = parent;
		}
		return root;
	}
	bool Union(int value1, int value2)
	{
		int root1 = FindRoot(value1);
		int root2 = FindRoot(value2);
		//������ͬһ������,����ϲ�
		if (root1 == root2) return false;
		//�ϲ�����: ������С�� �� ��������� �ϲ�
		if (abs(_ufs[root1]) < abs(_ufs[root2])) swap(root1, root2);
		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
		return true;
	}

	int IsInSet(int value1, int value2) {
		return FindRoot(value1) == FindRoot(value2);
	}
	size_t GetSetSize()
	{
		size_t count = 0;
		for (int i = 0; i < _ufs.size(); ++i)
			if (_ufs[i] < 0) ++count;
		return count;
	}
private:
	vector<int> _ufs;
};



template<class T>
class UnionFindSetTempLate
{
public:
	// ���캯��
	UnionFindSetTempLate(const vector<T>& v): _ufs(v.size(), -1)
	{
		for (int i = 0; i < v.size(); ++i)
			_indexMap[v[i]] = i;
	}
	
	// ����Ԫ�����ڵļ���
	int FindRoot(const T& value)
	{
		int root = _indexMap[value];
		while (_ufs[root] >= 0) root = _ufs[root];
		//·��ѹ��
		int tmp = _indexMap[value];
		while (_ufs[tmp] >= 0) {
			int parent = _ufs[tmp];
			_ufs[tmp] = root;
			tmp = parent;
		}
		return root;
	}

	// �ж�����Ԫ���Ƿ���ͬһ������
	bool IsSameSet(const T& value1, const T& value2) {
		return FindRoot(value1) == FindRoot(value2);
	}

	// �ϲ�����Ԫ�����ڵļ���
	bool Union(const T& value1, const T& value2)
	{
		int root1 = FindRoot(value1), root2 = FindRoot(value2);
		//������ͬһ������,����ϲ�
		if (root1 == root2) return false;
		//�ϲ�����: ������С�� �� ��������� �ϲ�
		if (abs(_ufs[root1]) < abs(_ufs[root2])) swap(root1, root2);
		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
		return true;
	}

	// ��ȡ���鼯�м��ϵĸ���
	size_t GetSetSize()
	{
		size_t count = 0;
		for (int i = 0; i < _ufs.size(); ++i)
			if (_ufs[i] < 0) ++count;
		return count;
	}
private:
	vector<int> _ufs; //ά����������Ĺ�ϵ
	unordered_map<T, int> _indexMap;//ά��Ԫ�����±�֮���ӳ���ϵ
};



//int main() {
//	vector<string> v = { "����", "����", "����", "����", "����", "�ܰ�", "���" };
//
//	UnionFindSetTempLate<string> ufs(v);
//	cout << ufs.GetSetSize() << endl; //7
//
//	ufs.Union("����", "����");
//	ufs.Union("����", "����");
//	cout << ufs.GetSetSize() << endl; //5
//
//	ufs.Union("����", "����");
//	cout << ufs.GetSetSize() << endl; //4
//
//	return 0;
//}
