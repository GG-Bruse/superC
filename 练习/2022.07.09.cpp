#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0,right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right)/2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else 
            {
                return mid;
            }
        }
        return -1;
    }
};
int main()
{
	vector<int>nums;
	nums.push_back(-1);
	nums.push_back(0);
	Solution s;
	int num = s.search(nums,13);
	if(num == -1)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<nums[num]<<endl;
	return 0;
}






//线性搜索
//解题思路：利用二维数组行列递增特性
//
//由于行列递增，可以得出：
//a.在一列中的某个数字，其上的数字都比它小
//b.在一行中的某个数字，其右的数字都比它大
//搜索流程：
//a.首先从数组左下角搜索.
//b.如果当前数字大于target,那么查找往上移一位,如果当前数字小于target,那么查找往右移一位。
//c.查找到target,返回true; 如果越界，返回false;
#include<iostream>
using namespace std;
class Solution
{
public:
    bool Find(int target, vector<vector<int> > array)
	{
        if(array.size() == 0)  return false;
        int r = array.size();//行 
        int l = array[0].size();//列 
        int left = 0, down = r - 1;
        while(left<l && down>=0)
        {
            int tmp = array[down][left];
            if( tmp == target) return true;
            else if(tmp < target) left++;
            else down--;
        }
        return false;
    }
};








//给定一个长度为n的数组nums，请你找到峰值并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个所在位置即可。
//1.峰值元素是指其值严格大于左右相邻值的元素。严格大于即不能有等于
//2.假设 nums[-1] = nums[n] = 极小 
//3.对于所有有效的 i 都有 nums[i] != nums[i + 1]
class Solution
{
public:
    int findPeakElement(vector<int>& nums)
	{
        int left = 0;
        int right = nums.size() - 1;
        //二分法
        while(left < right){
            int mid = (left + right) / 2;
            //右边是往下，不一定有坡峰
            if(nums[mid] > nums[mid + 1])
                right = mid;
            //右边是往上，一定能找到波峰
            else
                left = mid + 1;
        }
        //其中一个波峰
        return right;
    }
};




//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组,求出这个数组中的逆序对的总数P。
//并将P对1000000007取模的结果输出。 即输出P mod 1000000007


//暴力解法
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int kmod = 1000000007;
class Solution
{
public:
    int InversePairs(vector<int> data)
	{
        int ret = 0;
        int n = data.size();
        for (int i = 0; i < n; ++i)
		{
            for (int j = i + 1; j < n; ++j)
			{
                if (data[i] > data[j])
				{
                    ret += 1;
                    ret %= kmod;
                }
            }
        }
 
        return ret;
    }
};
int main()
{
	vector<int>data;
	for(int i = 1;i<=3;++i)
	{
		data.push_back(i);
	}
	Solution s;
	cout<<s.InversePairs(data)<<endl;;
	return 0;
}





