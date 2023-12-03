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










/****************************************** 使三个字符串相等（LeetCode）***********************************************/
/*
给你三个字符串 s1、s2 和 s3。 你可以根据需要对这三个字符串执行以下操作 任意次数 
在每次操作中，你可以选择其中一个长度至少为 2 的字符串 并删除其 最右位置上 的字符
如果存在某种方法能够使这三个字符串相等，请返回使它们相等所需的 最小 操作次数；否则，返回 -1
*/
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    int findMinimumOperations(string s1, string s2, string s3)
//    {
//        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
//        int minLength = min(size1, min(size2, size3));
//
//        int same = 0;
//        for (int i = 0; i < minLength; ++i)
//            if (s1[i] == s2[i] && s2[i] == s3[i])
//                ++same;
//            else break;
//
//        if (same == 0) return -1;
//        else return size1 + size2 + size3 - 3 * same;
//    }
//};









/******************************************* 区分黑球与白球（LeetCode）************************************************/
/*
桌子上有 n 个球，每个球的颜色不是黑色，就是白色
给你一个长度为 n 、下标从 0 开始的二进制字符串 s，其中 1 和 0 分别代表黑色和白色的球
在每一步中，你可以选择两个相邻的球并交换它们
返回「将所有黑色球都移到右侧，所有白色球都移到左侧所需的 最小步数」
*/
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    //对于每个0, 它左边有多少个1, 就移动多少次
//    long long minimumSteps(string s)
//    {
//        long long ret = 0;
//        int oneOfCount = 0;
//        for (char& ch : s)
//        {
//            if (ch == '1') ++oneOfCount;
//            else ret += oneOfCount;
//        }
//        return ret;
//    }
//};








/********************************************** 最大异或乘积（LeetCode）***********************************************/
/*
给你三个整数 a ，b 和 n ，请你返回 (a XOR x) * (b XOR x) 的 最大值 且 x 需要满足 0 <= x < 2n
由于答案可能会很大，返回它对 109 + 7 取余 后的结果
注意，XOR 是按位异或操作
*/
//#include <iostream>
//using namespace std;
//class Solution {
//public:
//    //若a和b在某个比特位上都为0, x在该比特位上取1
//    //若a和b在某个比特位上都为1, x在该比特位上取0
//    //若一个位上a、b, 一个位等于1，另一个位等于0, 则需要讨论, 但不管选什么1的数量不变, 即 a^x + b^x等于一个定值
//    const long long MOD = 1'000'000'007;
//    int maximumXorProduct(long long a, long long b, int n)
//    {
//        if (a < b) swap(a, b); //保证 a >= b
//
//        long long mask = (1LL << n) - 1; //n-1到0位都为1
//        long long ax = a & ~mask; //保留第n位及其左边, 无法被x影响
//        long long bx = b & ~mask;
//        a &= mask; //保留低于第n位, 都能被x影响
//        b &= mask;
//
//        long long discuss = a ^ b; // 一个位是0, 另一个位是1, 需要讨论
//        long long same = mask ^ discuss; // a和b在这个比特位全为0或者全为1
//
//        ax += same;
//        bx += same;
//
//        // 分配后应当使 ax 和 bx 尽量接近，乘积才能尽量大
//        if (discuss > 0 && ax == bx) //最高位给ax, 其余给bx
//        {
//            long long high_bit = 1LL << (63 - __builtin_clzll(discuss));
//            ax += high_bit;
//            discuss ^= high_bit;
//        }
//        bx |= discuss;
//        return (ax % MOD) * (bx % MOD) % MOD;
//    }
//};









/********************************************** 找出峰值（LeetCode）*********************************************/
/*
给你一个下标从 0 开始的数组 mountain 。你的任务是找出数组 mountain 中的所有峰值
以数组形式返回给定数组中 峰值 的下标，顺序不限
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> findPeaks(vector<int>& mountain)
//    {
//        int size = mountain.size();
//        vector<int> ret;
//        for (int i = 1; i < size - 1; ++i)
//            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
//                ret.push_back(i);
//        return ret;
//    }
//};









/**************************************** 需要添加的硬币的最小数量（LeetCode）***********************************/
/*
给你一个下标从 0 开始的整数数组 coins，表示可用的硬币的面值，以及一个整数 target
如果存在某个 coins 的子序列总和为 x，那么整数 x 就是一个 可取得的金额
返回需要添加到数组中的 任意面值 硬币的 最小数量 ，使范围 [1, target] 内的每个整数都属于 可取得的金额 
数组的 子序列 是通过删除原始数组的一些（可能不删除）元素而形成的新的 非空 数组，删除过程不会改变剩余元素的相对位置
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    int minimumAddedCoins(vector<int>& coins, int target)
//    {
//        sort(coins.begin(), coins.end());
//        int result = 0;
//        int right = 1; //可以组成[0, right - 1]中的所有数
//
//        int current = 0;
//        //当right > target, 此时[0, target]中的所有数字都可以组成了
//        while (right <= target)
//        {
//            //现在可以组成[0, right + coins[current]]中的所有数字
//            if (current < coins.size() && coins[current] <= right) {
//                right += coins[current];
//                ++current;
//            }
//            else {
//                right += right;
//                ++result;
//            }
//        }
//        return result;
//    }
//};









/***************************************** 统计完全子字符串（LeetCode）******************************************/
/*
给你一个字符串 word 和一个整数 k
如果 word 的一个子字符串 s 满足以下条件，我们称它是 完全字符串：
s 中每个字符 恰好 出现 k 次
相邻字符在字母表中的顺序 至多 相差 2 。也就是说，s 中两个相邻字符 c1 和 c2
它们在字母表中的位置相差 至多 为 2
请你返回 word 中 完全 子字符串的数
子字符串 指的是一个字符串中一段连续 非空 的字符序列
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int Handle(string str, int k)
//    {
//        int ret = 0;
//        //符合要求的字符串的长度肯定是k的倍数, 最长为26个字符每个出现k次
//        for (int groupNum = 1; groupNum <= 26 && k * groupNum <= str.size(); ++groupNum)
//        {
//            unordered_map<char, int> hash;//字符出现次数
//            for (int right = 0; right < str.size(); ++right)
//            {
//                ++hash[str[right]];
//                int left = right + 1 - k * groupNum;
//                if (left >= 0)
//                {
//                    bool flag = true;
//                    for (auto& it : hash)
//                        if (it.second != k) flag = false;
//                    if (flag) ++ret;
//                    --hash[str[left]];
//                    if (hash[str[left]] == 0) hash.erase(hash.find(str[left]));
//                }
//            }
//        }
//        return ret;
//    }
//    int countCompleteSubstrings(string word, int k)
//    {
//        int size = word.size();
//        int result = 0;
//        //一个一个区域处理
//        for (int i = 0; i < size;)
//        {
//            int start = i;
//            for (i++; i < size && abs(word[i] - word[i - 1]) <= 2; i++);
//            cout << word.substr(start, i - start) << endl;
//            result += Handle(word.substr(start, i - start), k);
//        }
//        return result;
//    }
//};