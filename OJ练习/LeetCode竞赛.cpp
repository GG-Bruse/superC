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









/************************************* 数组的最小相等和（LeetCode）***********************************************/
/*
给你两个由正整数和0组成的数组nums1和nums2 
你必须将两个数组中的所有0替换为严格正整数，并且满足两个数组中所有元素的和相等 
返回最小相等和，如果无法使两数组相等，则返回-1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    long long minSum(vector<int>& nums1, vector<int>& nums2)
//    {
//        long long ret1 = 0;
//        bool flag1 = false;
//        for (auto& it : nums1) {
//            if (it == 0) ret1 += 1, flag1 = true;
//            else ret1 += it;
//        }
//        long long ret2 = 0;
//        bool flag2 = false;
//        for (auto& it : nums2) {
//            if (it == 0) ret2 += 1, flag2 = true;
//            else  ret2 += it;
//        }
//        if (flag1 && !flag2 && ret1 > ret2) return -1;
//        else if (!flag1 && flag2 && ret1 < ret2) return -1;
//        else if (!flag1 && !flag2 && ret1 != ret2) return -1;
//        else return max(ret1, ret2);
//    }
//};









/********************************** 使数组变美的最小增量运算数（LeetCode）****************************************/
/*
给你一个下标从 0 开始、长度为n的整数数组nums，和一个整数k
你可以执行下述递增运算任意次（可以是 0 次）
从范围 [0, n - 1] 中选择一个下标 i ，并将nums[i]的值加1
如果数组中任何长度大于或等于3的子数组，其最大元素都大于或等于k，则认为数组是一个美丽数组
以整数形式返回使数组变为美丽数组需要执行的最小递增运算数
子数组是数组中的一个连续 非空 元素序列
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    long long minIncrementOperations(vector<int>& nums, int k)
//    {
//        int size = nums.size();
//        //dp[i] : 将nums[0] 到 nums[i]变为美丽数组, 且满足nums[i] >= k的最小增量运算数
//        vector<long long> dp(size);
//        for (int i = 0; i < 3; ++i)
//            dp[i] = max(k - nums[i], 0);
//        for (int i = 3; i < size; ++i)
//            dp[i] = min({ dp[i - 1], dp[i - 2], dp[i - 3] }) + max(k - nums[i], 0);
//        return min({ dp[size - 1], dp[size - 2], dp[size - 3] });
//    }
//};










/***************************************** 找出数组中的K-or值（LeetCode）*****************************************/
/*
给你一个下标从0开始的整数数组nums和一个整数k
nums 中的 K-or 是一个满足以下条件的非负整数：
只有在nums中，至少存在k个元素的第i位值为1，那么K-or中的第i位的值才是1
返回nums的K-or值
注意：对于整数x ，如果 (2i AND x) == 2i ，则x中的第i位值为1 ，其中AND为按位与运算符
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int findKOr(vector<int>& nums, int k)
//    {
//        unordered_map<int, int> hash;//bitNum : Count
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            int tmp = nums[i];
//            for (int j = 0; j < 32; ++j) {
//                if ((tmp & (1 << j)) != 0)
//                    ++hash[j];
//            }
//        }
//        int ret = 0;
//        for (auto& it : hash) {
//            if (it.second >= k) ret += pow(2, it.first);
//        }
//        return ret;
//    }
//};









/***************************************** 找到冠军I（LeetCode）******************************************/
/*
一场比赛中共有n支队伍，按从0到 n - 1编号
给你一个下标从 0 开始、大小为 n * n 的二维布尔矩阵grid
对于满足0 <= i, j <= n - 1且i != j的所有 i, j：如果grid[i][j] == 1，那么i队比j队强；否则，j队比i队强 
在这场比赛中，如果不存在某支强于 a 队的队伍，则认为 a 队将会是冠军
返回这场比赛中将会成为冠军的队伍
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findChampion(vector<vector<int>>& grid)
//    {
//        int size = grid.size();
//        //如果第 j 列的元素值都是 0, 说明没有队伍可以击败它，返回 j
//        for (int i = 0; i < size; ++i)//枚举各列
//        {
//            bool flag = false;//是否出现1 
//            for (int j = 0; j < size; ++j)//遍历该列元素
//                if (grid[j][i] == 1) flag = true;
//            if (flag == false) return i;
//        }
//        return -1;
//    }
//};