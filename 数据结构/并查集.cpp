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
		//路径压缩
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
		//本身在同一个集合,不需合并
		if (root1 == root2) return false;
		//合并操作: 数据量小的 往 数据量大的 合并
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
	// 构造函数
	UnionFindSetTempLate(const vector<T>& v): _ufs(v.size(), -1)
	{
		for (int i = 0; i < v.size(); ++i)
			_indexMap[v[i]] = i;
	}
	
	// 查找元素所在的集合
	int FindRoot(const T& value)
	{
		int root = _indexMap[value];
		while (_ufs[root] >= 0) root = _ufs[root];
		//路径压缩
		int tmp = _indexMap[value];
		while (_ufs[tmp] >= 0) {
			int parent = _ufs[tmp];
			_ufs[tmp] = root;
			tmp = parent;
		}
		return root;
	}

	// 判断两个元素是否在同一个集合
	bool IsSameSet(const T& value1, const T& value2) {
		return FindRoot(value1) == FindRoot(value2);
	}

	// 合并两个元素所在的集合
	bool Union(const T& value1, const T& value2)
	{
		int root1 = FindRoot(value1), root2 = FindRoot(value2);
		//本身在同一个集合,不需合并
		if (root1 == root2) return false;
		//合并操作: 数据量小的 往 数据量大的 合并
		if (abs(_ufs[root1]) < abs(_ufs[root2])) swap(root1, root2);
		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
		return true;
	}

	// 获取并查集中集合的个数
	size_t GetSetSize()
	{
		size_t count = 0;
		for (int i = 0; i < _ufs.size(); ++i)
			if (_ufs[i] < 0) ++count;
		return count;
	}
private:
	vector<int> _ufs; //维护各个结点间的关系
	unordered_map<T, int> _indexMap;//维护元素与下标之间的映射关系
};



//int main() {
//	vector<string> v = { "张三", "李四", "王五", "赵六", "田七", "周八", "吴九" };
//
//	UnionFindSetTempLate<string> ufs(v);
//	cout << ufs.GetSetSize() << endl; //7
//
//	ufs.Union("张三", "李四");
//	ufs.Union("王五", "赵六");
//	cout << ufs.GetSetSize() << endl; //5
//
//	ufs.Union("张三", "赵六");
//	cout << ufs.GetSetSize() << endl; //4
//
//	return 0;
//}
