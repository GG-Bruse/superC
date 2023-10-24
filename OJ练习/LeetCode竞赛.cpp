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










/****************************************** 合法分组的最少组数（LeetCode）*************************************/
/*
给你一个长度为n下标从0开始的整数数组nums
我们想将下标进行分组，使得 [0, n - 1] 内所有下标i都恰好被分到其中一组
如果以下条件成立，我们说这个分组方案是合法的：
对于每个组 g ，同一组内所有下标在nums中对应的数值都相等
对于任意两个组 g1 和 g2 ，两个组中下标数量的差值不超过1
请你返回一个整数，表示得到一个合法分组方案的 最少 组数
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int minGroupsForValidAssignment(vector<int>& nums)
//    {
//        unordered_map<int, int> counts;//记录每个数出现的频次
//        for (auto& it : nums) ++counts[it];
//        //求出最小组中元素的个数
//        int minSize = INT_MAX;
//        for (auto& [_, cnt] : counts) minSize = min(minSize, cnt);
//        //枚举每一种分组情况
//        for (int k = minSize; k > 0; --k)//最多分为minSize组, 每组中一个元素
//        {
//            int ret = 0;
//            for (auto& [_, cnt] : counts)
//            {
//                if (cnt / k < cnt % k) {//无法分成k和k+1组
//                    ret = 0;
//                    break;
//                }
//                ret += (cnt + k) / (k + 1);
//            }
//            if (ret) return ret;
//        }
//        return -1;
//    }
//};