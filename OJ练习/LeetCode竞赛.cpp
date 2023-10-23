/*********************************** 元素和最小的山形三元组II（LeetCode）**************************************/
/*
给你一个下标从0开始的整数数组nums 
如果下标三元组 (i, j, k) 满足下述全部条件，则认为它是一个山形三元组：i < j < k
nums[i] < nums[j] 且 nums[k] < nums[j]
请你找出nums中元素和最小的山形三元组，并返回其元素和。如果不存在满足条件的三元组，返回-1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minimumSum(vector<int>& nums)
//    {
//        int size = nums.size();
//        //dp[i] : 从nums[i]到nums[n - 1]的最小值
//        vector<int> dp(size);
//        dp[size - 1] = nums[size - 1];
//        for (int i = size - 2; i >= 0; --i)
//            dp[i] = min(dp[i + 1], nums[i]);
//
//        int prev = nums[0];//记录山顶以前最小的元素
//        int minTop = INT_MAX;
//        for (int i = 1; i < size - 1; ++i)//枚举山顶
//        {
//            if (prev < nums[i] && nums[i] > dp[i + 1])
//                minTop = min(minTop, prev + nums[i] + dp[i + 1]);
//            prev = min(prev, nums[i]);
//        }
//        return minTop == INT_MAX ? -1 : minTop;
//    }
//};