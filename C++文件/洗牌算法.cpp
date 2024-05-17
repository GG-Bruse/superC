#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void FisherYatesShuffle(vector<int>& nums)
{
	srand((unsigned int)time(nullptr));
	vector<int> ret;
	int size = nums.size();
	for (int i = 0; i < size; ++i)
	{
		int index = rand() % nums.size();
		ret.push_back(nums[index]);
		nums.erase(nums.begin() + index);
	}
	std::swap(ret, nums);
}

void KnuthDurstenfeldShuffle(vector<int>& nums)
{
	srand((unsigned int)time(nullptr));
	int size = nums.size();
	for (int i = size; i > 0; --i)//模数，余数范围为[size - 1, 0]; 下标
	{
		int index = rand() % i;
		swap(nums[index], nums[i - 1]);
	}
}

void InsideOutAlgorithm(vector<int>& nums)
{
	srand((unsigned int)time(nullptr));
	vector<int> ret = nums;
	for (int i = 0; i < nums.size(); ++i)
	{
		int index = rand() % (i + 1);//[0, i]
		/*ret[i] = ret[index];
		ret[index] = nums[i];*/
		swap(ret[index], ret[i]);
	}
	swap(ret, nums);
}


//int main()
//{
//	vector<int> nums1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	FisherYatesShuffle(nums1);
//	for (auto& it : nums1)
//		cout << it << " ";
//	cout << endl;
//
//	vector<int> nums2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	KnuthDurstenfeldShuffle(nums2);
//	for (auto& it : nums2)
//		cout << it << " ";
//	cout << endl;
//
//	vector<int> nums3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	InsideOutAlgorithm(nums3);
//	for (auto& it : nums3)
//		cout << it << " ";
//	cout << endl;
//
//	return 0;
//}