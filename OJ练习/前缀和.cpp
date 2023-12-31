/************************************ 区域和检索 - 数组不可变（LeetCode）**************************************/
/*
给定一个整数数组  nums，处理以下类型的多个查询:
计算索引 left 和 right （包含 left 和 right）之间的 nums 元素的 和 ，其中 left <= right
实现 NumArray 类：
NumArray(int[] nums) 使用数组 nums 初始化对象
int sumRange(int i, int j)返回数组nums中索引left和right之间的元素的总和 ，
包含 left 和 right 两点（也就是 nums[left] + nums[left + 1] + ... + nums[right] )
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class NumArray {
//public:
//    NumArray(vector<int>& nums)
//    {
//        int size = nums.size();
//        prevSum = vector<int>(size + 1);
//        for (int i = 0; i < size; ++i)
//            prevSum[i + 1] = prevSum[i] + nums[i];
//    }
//
//    int sumRange(int left, int right) {
//        return prevSum[right + 1] - prevSum[left];
//    }
//private:
//    vector<int> prevSum;//前缀和 : prevSum[i] : nums[0]到nums[i]之间所有元素之和 
//};
///**
// * Your NumArray object will be instantiated and called as such:
// * NumArray* obj = new NumArray(nums);
// * int param_1 = obj->sumRange(left,right);
// */










/********************************** 二维区域和检索 - 矩阵不可变（LeetCode）************************************/
/*
给定一个二维矩阵 matrix，以下类型的多个请求：
计算其子矩形范围内元素的总和，该子矩阵的左上角为(row1, col1)，右下角为(row2, col2)
实现 NumMatrix 类：
NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、
右下角 (row2, col2) 所描述的子矩阵的元素 总和
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class NumMatrix {
//public:
//    NumMatrix(vector<vector<int>>& matrix)
//    {
//        row = matrix.size(), col = matrix[0].size();
//        //prevSum[i][j] : matrix[0][0]到matrix[i - 1][j - 1]之间所有元素之和 
//        prevSum = vector<vector<int>>(row + 1, vector<int>(col + 1));
//        prevSum[1][1] = matrix[0][0];
//        for (int i = 1; i <= row; ++i)
//            for (int j = 1; j <= col; ++j)
//                prevSum[i][j] = prevSum[i - 1][j] + prevSum[i][j - 1] - prevSum[i - 1][j - 1] + matrix[i - 1][j - 1];
//    }
//    int sumRegion(int row1, int col1, int row2, int col2)
//    {
//        ++row1, ++row2, ++col1, ++col2;
//        int ret = prevSum[row2][col2];
//        ret -= (prevSum[row2][col1 - 1] + prevSum[row1 - 1][col2]);
//        ret += prevSum[row1 - 1][col1 - 1];
//        return ret;
//    }
//private:
//    vector<vector<int>> prevSum;
//    int row = 0, col = 0;
//};
///**
// * Your NumMatrix object will be instantiated and called as such:
// * NumMatrix* obj = new NumMatrix(matrix);
// * int param_1 = obj->sumRegion(row1,col1,row2,col2);
// */









/****************************** 矩形区域不超过 K 的最大数值和（LeetCode）**************************************/
/*
给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和
题目数据保证总会存在一个数值和不超过 k 的矩形区域
*/
//#include <iostream>
//#include <vector>
//#include <set>
//using namespace std;
//class Solution {
//public:
//    int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
//    {
//        int ret = INT_MIN;
//        int row = matrix.size(), col = matrix[0].size();
//        for (int i = 0; i < row; ++i)//枚举上边界
//        {
//            vector<int> sum(col);//边界内 每列的元素和
//            for (int j = i; j < row; ++j)//枚举下边界
//            {
//                for (int k = 0; k < col; ++k)
//                    sum[k] += matrix[j][k];//更新每列的元素和
//
//                set<int> sumSet{ 0 };
//                int sRight = 0;
//                for (int it : sum)
//                {
//                    sRight += it;
//                    auto sLeft = sumSet.lower_bound(sRight - k);
//                    if (sLeft != sumSet.end())
//                        ret = max(ret, sRight - (*sLeft));
//                    sumSet.insert(sRight);
//                }
//            }
//        }
//        return ret;
//    }
//};









/*************************************** 连续的子数组和（LeetCode）********************************************/
/*
给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：
子数组大小 至少为 2 ，且子数组元素总和为 k 的倍数
如果存在，返回 true ；否则，返回 false
如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。0 始终视为 k 的一个倍数
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
///*
//当prefixSums[q] − prefixSums[p]为k的倍数时, prefixSums[p] 和 prefixSums[q]除以k的余数相同
//*/
//class Solution {
//public:
//    bool checkSubarraySum(vector<int>& nums, int k)
//    {
//        int size = nums.size();
//        if (size < 2) return false;
//
//        unordered_map<int, int> mp;//余数:第一次出现的下标
//        mp[0] = -1;
//        int prefixSum = 0;//前缀和的余数
//        for (int i = 0; i < size; ++i)
//        {
//            prefixSum = (prefixSum + nums[i]) % k;
//            if (mp.count(prefixSum))
//            {
//                int prevIndex = mp[prefixSum];
//                if (i - prevIndex >= 2) return true;
//            }
//            else mp[prefixSum] = i;
//        }
//        return false;
//    }
//};









/************************************* 最大平均值和的分组（LeetCode）******************************************/
/*
给定数组 nums 和一个整数 k 。我们将给定的数组 nums 分成 最多 k 个非空子数组，且数组内部是连续的
分数 由每个子数组内的平均值的总和构成
注意我们必须使用 nums 数组中的每一个数进行分组，并且分数不一定需要是整数
返回我们所能得到的最大 分数 是多少。答案误差在 10-6 内被视为是正确的
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    //平均值和最大的分组的子数组数目必定为k
//    double largestSumOfAverages(vector<int>& nums, int k)
//    {
//        int size = nums.size();
//
//        vector<double> prefix(size + 1);
//        for (int i = 0; i < size; ++i)
//            prefix[i + 1] = prefix[i] + nums[i];
//
//        //dp[i][j] : nums[0, i - 1]被切分为j个子数组的最大平均值和
//        vector<vector<double>> dp(size + 1, vector<double>(k + 1));
//        //初始化:  j=1时,dp[i][j]是对应区间[0,i−1]的平均值
//        for (int i = 1; i <= size; ++i)
//            dp[i][1] = prefix[i] / i;
//        //dp
//        for (int j = 2; j <= k; ++j)
//            for (int i = j; i <= size; ++i)
//                for (int x = j - 1; x < i; ++x)//遍历各种切割方法
//                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
//        return dp[size][k];
//    }
//};









/************************************* 和相同的二元子数组（LeetCode）******************************************/
/*
给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的非空子数组
子数组 是数组的一段连续部分
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//// class Solution {
//// public:
////     int numSubarraysWithSum(vector<int>& nums, int goal) 
////     {
////         int size = nums.size();
////         vector<int> prefix(size + 1);
////         for(int i = 1; i <= size; ++i)
////             prefix[i] = prefix[i - 1] + nums[i - 1];
//
////         int ret = 0;
////         unordered_map<int, int> hash;
////         ++hash[0];
////         for(int i = 1; i <= size; ++i)
////         {
////             int partRight = prefix[i];
////             if(hash.count(partRight - goal)) ret += hash[partRight - goal];
////             ++hash[partRight];
////         }
////         return ret;
////     }
//// };
////优化
//class Solution {
//public:
//    int numSubarraysWithSum(vector<int>& nums, int goal)
//    {
//        int size = nums.size();
//        int sum = 0;//统计当前元素和,代替前缀和数组
//
//        int ret = 0;
//        unordered_map<int, int> hash;
//        for (int i = 0; i < size; ++i)
//        {
//            ++hash[sum];
//            sum += nums[i];
//            if (hash.count(sum - goal)) ret += hash[sum - goal];
//        }
//        return ret;
//    }
//};










/***************************************** 构建回文串检测（LeetCode）******************************************/
/*
给你一个字符串 s，请你对 s 的子串进行检测
每次检测，待检子串都可以表示为 queries[i] = [left, right, k]
我们可以 重新排列 子串 s[left], ..., s[right]，并从中选择 最多 k 项替换成任何小写英文字母
如果在上述检测过程中，子串可以变成回文形式的字符串，那么检测结果为 true，否则结果为 false
返回答案数组 answer[]，其中 answer[i] 是第 i 个待检子串 queries[i] 的检测结果
注意：在替换时，子串中的每个字母都必须作为 独立的 项进行计数，也就是说，
如果 s[left..right] = "aaa" 且 k = 2，我们只能替换其中的两个字母
（另外，任何检测都不会修改原始字符串 s，可以认为每次检测都是独立的）
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
////注意:可以重新排列
//class Solution {
//public:
//    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries)
//    {
//        int size = s.size();
//        //异或前缀和
//        vector<int> count(size + 1);
//        for (int i = 0; i < size; ++i)
//            count[i + 1] = count[i] ^ (1 << (s[i] - 'a'));
//
//        vector<bool> ret;
//        for (auto& query : queries)
//        {
//            int left = query[0], right = query[1], k = query[2];
//            int bits = 0;
//            int tmp = count[right + 1] ^ count[left];
//            while (tmp > 0) {
//                tmp &= tmp - 1;//统计有几个1
//                ++bits;
//            }
//            ret.push_back(bits <= k * 2 + 1);
//        }
//        return ret;
//    }
//};










/**************************************** 可获得的最大点数（LeetCode）*****************************************/
/*
几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出
每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌
你的点数就是你拿到手中的所有卡牌的点数之和
给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    // 求连续的n - k张卡牌的最小值
//    int maxScore(vector<int>& cardPoints, int k)
//    {
//        int size = cardPoints.size();
//        int windowSize = size - k;
//        //选前size - k个作为初始值
//        int sum = 0;
//        for (int i = 0; i < size - k; ++i) sum += cardPoints[i];
//
//        int minSum = sum;
//        for (int i = windowSize; i < size; ++i)
//        {
//            sum += cardPoints[i] - cardPoints[i - windowSize];
//            minSum = min(minSum, sum);
//        }
//
//        int totalSum = 0;
//        for (int i = 0; i < size; ++i) totalSum += cardPoints[i];
//
//        return totalSum - minSum;
//    }
//};










/****************************** 和为目标值且不重叠的非空子数组的最大数目（LeetCode）***************************/
/*
给你一个数组 nums 和一个整数 target
请你返回 非空不重叠 子数组的最大数目，且每个子数组中数字和都为 target
*/
//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//    int maxNonOverlapping(vector<int>& nums, int target)
//    {
//        int size = nums.size();
//        int ret = 0;
//
//        //如果找到了一个符合条件的子数组，则接下来遍历时需要用一个新的哈希表
//        //而不是使用原有的哈希表，因为要确保每次找到的子数组都与此前找到的不重合
//        int current = 0;
//        while (current < size)
//        {
//            unordered_set<int> hash{ 0 };
//            int sum = 0;
//            while (current < size)
//            {
//                sum += nums[current];
//                if (hash.find(sum - target) != hash.end()) {
//                    ++ret;
//                    break;
//                }
//                else {
//                    hash.insert(sum);
//                    ++current;
//                }
//            }
//            ++current;
//        }
//        return ret;
//    }
//};