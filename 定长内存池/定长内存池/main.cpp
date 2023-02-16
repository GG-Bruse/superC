#include "Object_pool.h"
#include <vector>
#include <ctime>
using std::vector;

struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode()
		:_val(0)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

void TestObjectPool()
{
	const size_t Rounds = 5;// 申请释放的轮次
	const size_t N = 100000;// 每轮申请释放多少次

	std::vector<TreeNode*> v1;
	v1.reserve(N);
	size_t begin1 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i) v1.push_back(new TreeNode);
		for (int i = 0; i < N; ++i) delete v1[i];
		v1.clear();
	}
	size_t end1 = clock();


	std::vector<TreeNode*> v2;
	v2.reserve(N);
	ObjectPool<TreeNode> TNPool;
	size_t begin2 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i) v2.push_back(TNPool.New());
		for (int i = 0; i < N; ++i) TNPool.Delete(v2[i]);
		v2.clear();
	}
	size_t end2 = clock();

	cout << "new cost time:" << end1 - begin1 << endl;
	cout << "object pool cost time:" << end2 - begin2 << endl;
}
int main()
{
	TestObjectPool();
	return 0;
}