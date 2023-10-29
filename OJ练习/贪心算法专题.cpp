/********************************************* 柠檬水找零（LeetCode）******************************************/
/*
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯
每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元
你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付5美元
注意，一开始你手头没有任何零钱
给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false
*/
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool lemonadeChange(vector<int>& bills)
//    {
//        unordered_map<int, int> hash;//money : count
//        for (int i = 0; i < bills.size(); ++i)
//        {
//            if (bills[i] == 5) ++hash[5];
//            else if (bills[i] == 10) {
//                if (hash.count(5)) --hash[5], ++hash[10];
//                else return false;
//            }
//            else {/*bills[i] == 20*/
//                if (hash[5] >= 1 && hash[10] >= 1) --hash[5], --hash[10], ++hash[20];
//                else if (hash[5] >= 3) hash[5] -= 3, ++hash[20];
//                else return false;
//            }
//        }
//        return true;
//    }
//};








/*************************************** 将数组和减半的最少操作次数（LeetCode）********************************/
/*
给你一个正整数数组 nums 。每一次操作中，
你可以从nums中选择任意一个数并将它减小到恰好一半（注意，在后续操作中你可以对减半过的数继续执行操作）
请你返回将 nums 数组和 至少 减少一半的 最少 操作数
*/
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//class Solution {
//public:
//    int halveArray(vector<int>& nums)
//    {
//        int count = 0;
//        double target = 0;//需要删除的大小
//        priority_queue<double> qe;
//        for (int& it : nums) {
//            qe.push(it);
//            target += ((double)it / 2);
//        }
//
//        double del = 0;//已删除的大小
//        while (del < target) {
//            //取出此时最大数
//            double tmp = qe.top() / 2;
//            qe.pop();
//            //将最大数 / 2,重新插入
//            qe.push(tmp);
//            //增加已删除的数
//            del += tmp;
//            //增加操作次数
//            ++count;
//        }
//        return count;
//    }
//};









/*********************************************** 最大数（LeetCode）***********************************************/
/*
给定一组非负整数nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数
注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数
*/
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    string largestNumber(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end(), [](int num1, int num2) {
//            return to_string(num1) + to_string(num2) > to_string(num2) + to_string(num1);
//        });
//        string ret = "";
//        for (int& it : nums) ret += to_string(it);
//        if (ret[0] == '0') return "0";
//        return ret;
//    }
//};









/******************************************** 摆动序列（LeetCode）************************************************/
/*
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数
仅有一个元素或者含两个不等元素的序列也视作摆动序列
例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的
相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，
第二个序列是因为它的最后一个差值为零。
子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序
给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int wiggleMaxLength(vector<int>& nums)
//    {
//        int size = nums.size();
//        if (size < 2) return size;
//
//        int maxLength = 0, left = 0;
//        for (int i = 0; i < size - 1; ++i)
//        {
//            int right = nums[i + 1] - nums[i];//接下来的趋势
//            if (right == 0) continue;
//            if (left * right <= 0) ++maxLength;//左右趋势相反,即存在波峰或波谷
//            left = right;
//        }
//        return maxLength + 1;
//    }
//};









/****************************************** 最长递增子序列（LeetCode）********************************************/
/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums)
//    {
//        int size = nums.size();
//        vector<int> ret(1, nums[0]);
//        for (int i = 1; i < size; ++i)
//        {
//            if (nums[i] > ret.back()) ret.push_back(nums[i]);//能接在最后⼀个元素后⾯,直接放
//            else //二分插入(将nums[i]放在第一个大于等于nums[i]的位置)
//            {
//                int left = 0, right = ret.size() - 1;
//                while (left < right) {
//                    int mid = (left + right) >> 1;
//                    if (ret[mid] < nums[i]) left = mid + 1;
//                    else /*ret[mid] >= nums[i]*/ right = mid;
//                }
//                ret[left] = nums[i];
//            }
//        }
//        return ret.size();
//    }
//};









/***************************************** 递增的三元子序列（LeetCode）*******************************************/
/*
给你一个整数数组nums，判断这个数组中是否存在长度为3的递增子序列
如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回true
否则，返回false
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    //贪心算法
//    bool increasingTriplet(vector<int>& nums)
//    {
//        int one = nums[0], two = INT_MAX;//长度为1, 长度为2 的最小末尾
//        for (int i = 1; i < nums.size(); ++i)
//        {
//            if (nums[i] > two) return true;
//            else if (nums[i] > one) two = nums[i];
//            else one = nums[i];
//        }
//        return false;
//    }
//};









/******************************************* 最长连续递增序列（LeetCode）*****************************************/
/*
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度
连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，
都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findLengthOfLCIS(vector<int>& nums)
//    {
//        int size = nums.size(), ret = 0;
//        int begin = 0;
//        while (begin < size)
//        {
//            int end = begin + 1;
//            while (end < size && nums[end] > nums[end - 1]) ++end;//找到递增区间的末端
//            ret = max(end - begin, ret);
//            begin = end;//更新起点位置
//        }
//        return ret;
//    }
//};









/*************************************** 买卖股票的最佳时机（LeetCode）*******************************************/
/*
给定一个数组prices，它的第i个元素prices[i]表示一支给定股票第i天的价格
你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票
设计一个算法来计算你所能获取的最大利润
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回0
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maxProfit(vector<int>& prices)
//    {
//        //prevMin记录prices[i]元素之前的最小值
//        int ret = 0, prevMin = INT_MAX;
//        for (int i = 0; i < prices.size(); ++i) {
//            ret = max(prices[i] - prevMin, ret);
//            prevMin = min(prevMin, prices[i]);
//        }
//        return ret;
//    }
//};









/************************************** 买卖股票的最佳时机II（LeetCode）******************************************/
/*
给你一个整数数组prices，其中prices[i]表示某支股票第i天的价格
在每一天，你可以决定是否购买和/或出售股票
你在任何时候最多只能持有一股股票。你也可以先购买，然后在同一天出售
返回 你能获得的 最大 利润
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution1 {
//public:
//    int maxProfit(vector<int>& prices)
//    {
//        int size = prices.size();
//        int ret = 0;
//        for (int i = 0; i < size; ++i)
//        {
//            int j = i;
//            while (j + 1 < size && prices[j + 1] > prices[j]) ++j;//找上升区间的末端
//            ret += (prices[j] - prices[i]);
//            i = j;
//        }
//        return ret;
//    }
//};
//class Solution2 {
//public:
//    int maxProfit(vector<int>& prices)
//    {
//        int ret = 0;
//        for (int i = 1; i < prices.size(); ++i) {
//            int profit = prices[i] - prices[i - 1];
//            if (profit > 0) ret += profit;
//        }
//        return ret;
//    }
//};









/*************************************** K次取反后最大化的数组和（LeetCode）***********************************/
/*
给你一个整数数组nums和一个整数k ，按以下方法修改该数组：
选择某个下标i并将nums[i]替换为 -nums[i]
重复这个过程恰好k次。可以多次选择同一个下标i 
以这种方式修改数组后，返回数组可能的最大和
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    int largestSumAfterKNegations(vector<int>& nums, int k)
//    {
//        //记录所有小于0的数及其下标
//        vector<pair<int, int>> smallZero;
//        for (int i = 0; i < nums.size(); ++i) if (nums[i] < 0) smallZero.push_back({ nums[i], i });
//
//        if (smallZero.size() > k) { //将前k小负数变为正数
//            sort(smallZero.begin(), smallZero.end(), [&](pair<int, int>& p1, pair<int, int>& p2) {
//                return p1.first < p2.first; });
//            for (int i = 0; i < k; ++i) nums[smallZero[i].second] *= -1;
//        }
//        else if (smallZero.size() == k) { //将所有负数变为正数
//            for (int i = 0; i < k; ++i) nums[smallZero[i].second] *= -1;
//        }
//        else //smallZero.size() < k
//        {
//            //先将所有负数变为正数
//            for (int i = 0; i < smallZero.size(); ++i) nums[smallZero[i].second] *= -1;
//            //计算出还需取反几次
//            int last = k - smallZero.size();
//            //剩余取反次数若为偶数, 可相互抵消, 不做处理即可
//            //若为奇数, 找到最小的数, 将其转为负数
//            if (last % 2 != 0) {
//                int minNum = INT_MAX, minIndex = -1;
//                for (int i = 0; i < nums.size(); ++i) {
//                    if (minNum > nums[i]) {
//                        minNum = min(minNum, nums[i]);
//                        minIndex = i;
//                    }
//                }
//                nums[minIndex] *= -1;
//            }
//        }
//        int ret = 0;
//        for (auto& it : nums) ret += it;
//        return ret;
//    }
//};









/********************************************* 按身高排序（LeetCode）******************************************/
/*
给你一个字符串数组names，和一个由互不相同的正整数组成的数组heights。两个数组的长度均为n
对于每个下标 i，names[i]和heights[i]表示第i个人的名字和身高
请按身高降序顺序返回对应的名字数组names
*/
//#include <iostream>
//#include <vector>
//#include <string>
//#include <utility>
//#include <algorithm>
////创建二元组
//class Solution {
//public:
//    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
//    {
//        int size = names.size();
//        vector<pair<string, int>> reflect(size);
//        for (int i = 0; i < size; ++i) reflect[i] = { names[i], heights[i] };
//
//        sort(reflect.begin(), reflect.end(), [](pair<string, int>& p1, pair<string, int>& p2) {
//            return p1.second > p2.second; });
//
//        vector<string> ret(size);
//        for (int i = 0; i < size; ++i) ret[i] = reflect[i].first;
//        return ret;
//    }
//};
////下标排序
//using namespace std;
//class Solution {
//public:
//    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
//    {
//        int size = names.size();
//        vector<int> index(size);
//        for (int i = 0; i < size; ++i) index[i] = i;
//
//        sort(index.begin(), index.end(), [&](int i, int j) { //将下标进行排序
//            return heights[i] > heights[j]; });
//
//        vector<string> ret(size);
//        for (int i = 0; i < size; ++i) ret[i] = names[index[i]];
//        return ret;
//    }
//};









/********************************************* 最长回文串（LeetCode）*********************************************/
/*
给定一个包含大写字母和小写字母的字符串s，返回 通过这些字母构造成的 最长的回文串
在构造过程中，请注意区分大小写 。比如"Aa"不能当做一个回文字符串
*/
//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int longestPalindrome(string s)
//    {
//        unordered_map<char, int> hash;//char : 出现次数
//        for (char& it : s) ++hash[it];
//
//        int ret = 0;
//        bool flag = false;//是否出现过奇数个的字符
//        for (auto& it : hash) {
//            if (it.second % 2 == 0) ret += it.second;
//            else {
//                flag = true;
//                ret += (it.second - 1);
//            }
//        }
//        if (flag) ret += 1;
//        return ret;
//    }
//};










/***************************************** 增减字符串匹配（LeetCode）*********************************************/
/*
由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:
如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I'
如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D'
给定一个字符串s，重构排列perm并返回它。如果有多个有效排列perm，则返回其中任何一个
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*
//    遇到'I'时, 为了让下⼀个上升的数可选择的范围更多, 当前选择最⼩的那个数
//    当遇到'D'的时候, 为了让下⼀个下降的数可选择的范围更多, 选择当前最⼤的那个数
//    */
//    vector<int> diStringMatch(string s)
//    {
//        int size = s.size();
//        vector<int> ret(size + 1);
//        int minNum = 0, maxNum = size;//分别标记最小值和最大值
//        for (int i = 0; i < size; ++i) {
//            if (s[i] == 'I') ret[i] = minNum++;
//            else ret[i] = maxNum--;
//        }
//        ret.back() = minNum;
//        return ret;
//    }
//};








/******************************************* 合并区间（LeetCode）**********************************************/
/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals)
//    {
//        if (intervals.size() == 0) return {};
//        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
//            return v1[0] < v2[0];
//            });
//        vector<vector<int>> merged;
//        merged.push_back(intervals[0]);
//        for (int i = 1; i < intervals.size(); ++i)
//        {
//            if (intervals[i][0] > merged.back()[1]) merged.push_back(intervals[i]);
//            else merged.back()[1] = max(merged.back()[1], intervals[i][1]);
//        }
//        return merged;
//    }
//};