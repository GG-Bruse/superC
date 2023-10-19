﻿/********************************************** 移动零（LeetCode）***************************************************/
/*
给定一个数组nums，编写一个函数将所有0移动到数组的末尾，同时保持非零元素的相对顺序
请注意，必须在不复制数组的情况下原地对数组进行操作
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    //所有非0元素一个个往前放
//    void moveZeroes(vector<int>& nums) {
//        for (int dest = -1, current = 0; current < nums.size(); ++current)
//            if (nums[current] != 0) swap(nums[++dest], nums[current]);
//    }
//};











/************************************************** 复写零（LeetCode）***********************************************/
/*
给你一个长度固定的整数数组 arr ，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移
注意：请不要在超过该数组长度的位置写入元素。请对输入的数组 就地 进行上述修改，不要从函数返回任何东西
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr)
//    {
//        int size = arr.size();
//        //找到需要复写的最后一个数
//        int current = 0, dest = -1;
//        while (current < size)
//        {
//            if (arr[current] == 0) dest += 2;
//            else /*if(arr[current] != 0)*/ ++dest;
//            if (dest >= size - 1) break;
//            ++current;
//        }
//        //处理边界情况
//        if (dest == size) {
//            arr[size - 1] = 0;
//            dest -= 2, --current;
//        }
//        //从后向前复写
//        while (current >= 0) {
//            if (arr[current] != 0) arr[dest--] = arr[current--];
//            else /*if(arr[current] == 0)*/ arr[dest] = arr[dest - 1] = arr[current--], dest -= 2;
//        }
//    }
//};











/************************************************* 快乐数（LeetCode）************************************************/
/*
编写一个算法来判断一个数 n 是不是快乐数
「快乐数」 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和
然后重复这个过程直到这个数变为1，也可能是无限循环但始终变不到1
如果这个过程结果为1，那么这个数就是快乐数
如果n是快乐数就返回true；不是，则返回false
*/
////双指针解法：快慢指针
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int bitSum(int num)
//    {
//        int ret = 0;
//        while (num != 0)
//        {
//            ret += (num % 10) * (num % 10);
//            num /= 10;
//        }
//        return ret;
//    }
//    bool isHappy(int n)
//    {
//        int slow = n, fast = bitSum(n);
//        while (slow != fast) {
//            slow = bitSum(slow);
//            fast = bitSum(bitSum(fast));
//        }
//        return slow == 1;
//    }
//};
////记忆
//#include <iostream>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//    unordered_set<int> Set;
//    bool isHappy(int n)
//    {
//        while (true)
//        {
//            int ret = 0;
//            while (n) {
//                ret += (n % 10) * (n % 10);
//                n /= 10;
//            }
//            if (ret == 1) return true;
//            if (Set.find(ret) != Set.end()) return false;
//            Set.insert(ret);
//            n = ret;
//        }
//    }
//};










/************************************************** 盛最多水的容器（LeetCode）******************************************/
/*
给定一个长度为n的整数数组height 。有n条垂线，第i条线的两个端点是 (i, 0) 和 (i, height[i]) 
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水
返回容器可以储存的最大水量
说明：你不能倾斜容器
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*
//    V = height * width
//    left和right向中间移动, 导致width减小, 若想令V增大, 必须让高度增加, 于是每次将高度较低的丢弃
//    */
//    int maxArea(vector<int>& height)
//    {
//        int ret = 0;
//        int left = 0, right = height.size() - 1;
//        while (left < right) {
//            ret = max(ret, (right - left) * min(height[left], height[right]));
//            if (height[left] >= height[right]) --right;
//            else /*if(height[left] < height[right])*/ ++left;
//        }
//        return ret;
//    }
//};











/*********************************************** 有效三角形的个数（LeetCode）*******************************************/
/*
给定一个包含非负整数的数组nums ，返回其中可以组成三角形三条边的三元组个数
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    int triangleNumber(vector<int>& nums)
//    {
//        int size = nums.size();
//        sort(nums.begin(), nums.end());
//
//        int ret = 0;
//        for (int i = size - 1; i >= 2; --i)//先固定一个最大数
//        {
//            int left = 0, right = i - 1;
//            while (left < right)
//            {
//                if (nums[left] + nums[right] > nums[i]) {
//                    ret += right - left;
//                    --right;
//                }
//                else /*if(nums[left] + nums[right] <= nums[i])*/ {
//                    ++left;
//                }
//            }
//        }
//        return ret;
//    }
//};












/******************************************** 查找总价格为目标值的两个商品（LeetCode）**********************************/
/*
购物车内的商品价格按照升序记录于数组price。请在购物车中找到两个商品的价格总和刚好是target
若存在多种情况，返回任一结果即可
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& price, int target)
//    {
//        int size = price.size();
//        int left = 0, right = size - 1;
//        while (left < right)
//        {
//            int sum = price[left] + price[right];
//            if (sum > target) --right;
//            else if (sum < target) ++left;
//            else /* if(sum == target) */ return { price[left], price[right] };
//        }
//        return { 0,0 };
//    }
//};












/*************************************************** 三数之和（LeetCode）***********************************************/
/*
给你一个整数数组nums，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0
请你返回所有和为 0 且不重复的三元组
注意：答案中不可以包含重复的三元组
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums)
//    {
//        int size = nums.size();
//        sort(nums.begin(), nums.end());
//
//        vector<vector<int>> ret;
//        for (int i = size - 1; i >= 2;)//固定最后一个数
//        {
//            if (nums[i] < 0) return ret;//最后一个数都为负数, 此时已经不可能找到为0的组合了
//            int left = 0, right = i - 1;
//            int target = -nums[i];
//            while (left < right)
//            {
//                int sum = nums[left] + nums[right];
//                if (sum > target) --right;
//                else if (sum < target) ++left;
//                else /*sum == 0*/ {
//                    ret.push_back({ nums[left], nums[right], nums[i] });
//                    ++left, --right;
//                    //去重
//                    while (left < right && nums[left] == nums[left - 1]) left++;
//                    while (left < right && nums[right] == nums[right + 1]) right--;
//                }
//            }
//            --i;
//            while (i >= 2 && nums[i] == nums[i + 1]) i--;//去重
//        }
//        return ret;
//    }
//};












/************************************************* 四数之和（LeetCode）*************************************************/
/*
给你一个由n个整数组成的数组nums，和一个目标值target
请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] 
（若两个四元组元素一一对应，则认为两个四元组重复）：
0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按任意顺序返回答案
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target)
//    {
//        int size = nums.size();
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> ret;
//
//        for (int i = size - 1; i >= 3;)//先固定最后一个数
//        {
//            for (int j = i - 1; j >= 2;)//固定倒数第二个数
//            {
//                //双指针
//                int left = 0, right = j - 1;
//                long long aim = (long long)target - nums[i] - nums[j];
//                while (left < right)
//                {
//                    int sum = nums[left] + nums[right];
//                    if (sum > aim) --right;
//                    else if (sum < aim) ++left;
//                    else /*sum == 0*/ {
//                        ret.push_back({ nums[left++], nums[right--], nums[i], nums[j] });
//                        //去重
//                        while (left < right && nums[left] == nums[left - 1]) left++;
//                        while (left < right && nums[right] == nums[right + 1]) right--;
//                    }
//                }
//                --j;
//                while (j >= 2 && nums[j] == nums[j + 1]) --j;
//            }
//            --i;
//            while (i >= 3 && nums[i] == nums[i + 1]) --i;
//        }
//        return ret;
//    }
//};











/*********************************************** 长度最小的子数组（LeetCode）****************************************/
/*
给定一个含有 n 个正整数的数组和一个正整数target
找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
并返回其长度。如果不存在符合条件的子数组，返回 0
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums)
//    {
//        int size = nums.size();
//        int ret = INT_MAX, sum = 0;
//        for (int start = 0, end = 0; end < size; ++end)
//        {
//            sum += nums[end];
//            while (sum >= target) {
//                ret = min(ret, end - start + 1);
//                sum -= nums[start++];
//            }
//        }
//        return ret == INT_MAX ? 0 : ret;
//    }
//};










/******************************************* 无重复字符的最长子串（LeetCode）****************************************/
/*
给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度
*/
//#include <iostream>
//#include <unordered_map>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    unordered_map<char, int> hash;
//    int lengthOfLongestSubstring(string s)
//    {
//        int size = s.size();
//        int ret = 0;
//        for (int left = 0, right = 0; right < size; ++right)
//        {
//            ++hash[s[right]];
//            while (hash[s[right]] > 1) --hash[s[left++]];
//            ret = max(ret, right - left + 1);
//        }
//        return ret;
//    }
//};











/********************************************* 最大连续1的个数 III（LeetCode）***************************************/
/*
给定一个二进制数组nums和一个整数 k，如果可以翻转最多k个0 ，则返回 数组中连续1的最大个数
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*问题转化：找到最长的子数组, 子数组中0的个数不超过k个*/
//    int longestOnes(vector<int>& nums, int k)
//    {
//        int size = nums.size();
//        int ret = 0;
//        for (int left = 0, right = 0, zero = 0; right < size; ++right)
//        {
//            if (nums[right] == 0) ++zero;
//            while (zero > k)
//                if (nums[left++] == 0) --zero;
//            ret = max(ret, right - left + 1);
//        }
//        return ret;
//    }
//};












/******************************************** 将 x 减到 0 的最小操作数（LeetCode）***********************************/
/*
给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，
然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用
如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*
//    转化问题：
//    找到一段和为sum - x的最长数组
//    */
//    int minOperations(vector<int>& nums, int x)
//    {
//        int sum = 0;
//        for (auto& it : nums) sum += it;
//        int target = sum - x;
//        if (target < 0) return -1;
//
//        int ret = -1;
//        int size = nums.size();
//        for (int left = 0, right = 0, tmp = 0; right < size; ++right)
//        {
//            tmp += nums[right];
//            while (tmp > target) tmp -= nums[left++];
//            if (tmp == target) ret = max(ret, right - left + 1);
//        }
//        return ret == -1 ? -1 : size - ret;
//    }
//};












/********************************************** 水果成篮（LeetCode）*************************************************/
/*
你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组fruits表示，其中fruits[i]是第i棵树上的水果种类
你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：
你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制
你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果
采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘
一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘
给你一个整数数组 fruits ，返回你可以收集的水果的最大数目
*/
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int totalFruit(vector<int>& fruits)
//    {
//        unordered_map<int, int> hash;//种类 : 出现次数
//
//        int size = fruits.size();
//        int ret = 0;
//        for (int left = 0, right = 0; right < size; ++right)
//        {
//            ++hash[fruits[right]];
//            while (hash.size() > 2) {
//                --hash[fruits[left]];
//                if (hash[fruits[left]] == 0) hash.erase(fruits[left]);
//                ++left;
//            }
//            ret = max(ret, right - left + 1);
//        }
//        return ret;
//    }
//};











/***************************************** 找到字符串中所有字母异位词（LeetCode）***************************************/
/*
给定两个字符串s和p，找到s中所有p的异位词的子串，返回这些子串的起始索引。不考虑答案输出的顺序
异位词 指由相同字母重排列形成的字符串（包括相同的字符串）
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p)
//    {
//        vector<int> ret;
//        int Shash[26] = { 0 };//记录窗口中每个字母出现的次数
//        int Phash[26] = { 0 };//记录p中每个字母出现的次数
//        for (auto& it : p) ++Phash[it - 'a'];
//
//        int length = p.size();
//        for (int left = 0, right = 0, count = 0; right < s.size(); ++right)
//        {
//            char in = s[right];
//            if (++Shash[in - 'a'] <= Phash[in - 'a']) ++count;//符合要求, 进窗口
//            if (right - left + 1 > length)
//            {
//                char out = s[left++];
//                if (Shash[out - 'a']-- <= Phash[out - 'a']) --count;
//            }
//            if (count == length) ret.push_back(left);
//        }
//        return ret;
//    }
//};











/******************************************* 串联所有单词的子串（LeetCode）******************************************/
/*
给定一个字符串s和一个字符串数组words。words中所有字符串长度相同
s中的串联子串是指一个包含words中所有字符串以任意顺序排列连接起来的子串
例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab"
都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接
返回所有串联子串在s中的开始索引。你可以以任意顺序返回答案
*/
//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words)
//    {
//        unordered_map<string, int> hash1;//统计words中每个单词出现的次数
//        for (string& it : words) ++hash1[it];
//
//        vector<int> ret;
//        int size = words.size(), length = words[0].size();
//
//        for (int i = 0; i < length; ++i)
//        {
//            unordered_map<string, int> hash2;//统计窗口内每个单词出现的次数
//            for (int left = i, right = i, count = 0; right + length <= s.size(); right += length)
//            {
//                string in = s.substr(right, length);
//                ++hash2[in];
//                if (hash1.count(in) && hash2[in] <= hash1[in]) ++count;//进窗口单词为有效单词
//                if (right - left + 1 > length * size)
//                {
//                    string out = s.substr(left, length);
//                    if (hash1.count(out) && hash2[out] <= hash1[out]) --count;//出窗口单词为有效单词
//                    --hash2[out];
//                    left += length;
//                }
//                if (count == size) ret.push_back(left);
//            }
//        }
//        return ret;
//    }
//};












/********************************************* 最小覆盖子串（LeetCode）**********************************************/
/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串
如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
*/
//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    string minWindow(string s, string t)
//    {
//        int kinds = 0;//记录有效字符的种类数
//        int hash1[127] = { 0 };//统计string t中所有字符出现的个数
//        for (char& ch : t) if (hash1[ch]++ == 0) ++kinds;
//
//        int hash2[128] = { 0 };//维护窗口中所有字符出现的个数
//        int min_length = INT_MAX, begin = -1;
//
//        //count标记窗口中完全出现的有效字符的种类
//        for (int left = 0, right = 0, count = 0; right < s.size(); ++right)
//        {
//            char in = s[right];
//            ++hash2[in];
//            if (hash2[in] == hash1[in]) ++count;
//            while (count == kinds)
//            {
//                if (right - left + 1 < min_length)
//                {
//                    min_length = right - left + 1;
//                    begin = left;
//                }
//                char out = s[left];
//                if (hash2[out] == hash1[out]) --count;
//                ++left, --hash2[out];
//            }
//        }
//        if (begin == -1) return "";
//        else return s.substr(begin, min_length);
//    }
//};













/*********************************** 在排序数组中查找元素的第一个和最后一个位置（LeetCode）***************************/
/*
给你一个按照非递减顺序排列的整数数组nums，和一个目标值target。请你找出给定目标值在数组中的开始位置和结束位置
如果数组中不存在目标值target，返回[-1, -1]
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题
*/
////方法一
//#include <iostream>
//#include <vector>
//using namespace std;
////极端情况下,退化为O(n),如所有元素相同的情况
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target)
//    {
//        int beginRet = -1, endRet = -1;
//        int left = 0, right = nums.size() - 1;
//        int index = -1;
//        while (left <= right)
//        {
//            int mid = (left + right) >> 1;
//            if (nums[mid] > target) right = mid - 1;
//            else if (nums[mid] < target) left = mid + 1;
//            else {
//                index = mid;
//                break;
//            }
//        }
//        if (index != -1)
//        {
//            for (int i = index; i >= 0; --i) {
//                if (nums[i] == target) beginRet = i;
//                else break;
//            }
//            for (int i = index; i < nums.size(); ++i) {
//                if (nums[i] == target) endRet = i;
//                else break;
//            }
//        }
//        return { beginRet, endRet };
//    }
//};
////方法二
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target)
//    {
//        int beginRet = -1, endRet = -1;
//        if (nums.size() == 0) return { beginRet, endRet };
//        //找左端点
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] < target) left = mid + 1;
//            else /*if(nums[mid] >= target)*/ right = mid;
//        }
//        if (nums[left] == target) beginRet = left;
//        //找右端点
//        left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left + 1) / 2;
//            if (nums[mid] <= target) left = mid;
//            else /*if((nums[mid] > target)*/ right = mid - 1;
//        }
//        if (nums[left] == target) endRet = right;
//        return { beginRet, endRet };
//    }
//};










/************************************************* 搜索插入位置（LeetCode）**********************************************/
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置
请必须使用时间复杂度为 O(log n) 的算法
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target)
//    {
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (nums[mid] >= target) right = mid;
//            else /*if(nums[mid] < target)*/ left = mid + 1;
//        }
//        if (nums[left] < target) return right + 1;
//        else return right;
//    }
//};











/**************************************************** x的平方（LeetCode）*********************************************/
/*
给你一个非负整数x，计算并返回x的算术平方根
由于返回类型是整数，结果只保留整数部分，小数部分将被舍去
注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5
*/
//#include <iostream>
//using namespace std;
//class Solution {
//public:
//    int mySqrt(int x)
//    {
//        if (x < 1) return 0;
//        int left = 1, right = x;
//        while (left < right)
//        {
//            int mid = left + ((right - left + 1) >> 1);
//            if ((long long)mid * mid <= x) left = mid;
//            else /*if(tmp > x)*/ right = mid - 1;
//        }
//        return left;
//    }
//};











/*********************************************** 山脉数组的峰顶索引（LeetCode）******************************************/
/*
符合下列属性的数组 arr 称为 山脉数组 ：
arr.length >= 3
存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
给你由整数组成的山脉数组 arr ，返回满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]的下标i
你必须设计并实现时间复杂度为 O(log(n)) 的解决方案
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int peakIndexInMountainArray(vector<int>& arr)
//    {
//        int left = 1, right = arr.size() - 2;//第一个和最后一个一定不是结果
//        while (left < right)
//        {
//            int mid = left + ((right - left + 1) >> 1);
//            if (arr[mid] > arr[mid - 1]) left = mid;
//            else /*if(arr[mid] <= target)*/ right = mid - 1;
//        }
//        return left;
//    }
//};











/************************************************ 寻找峰值（LeetCode）***************************************************/
/*
峰值元素是指其值严格大于左右相邻值的元素
给你一个整数数组nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可
你可以假设 nums[-1] = nums[n] = -∞
你必须实现时间复杂度为O(log n)的算法来解决此问题
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findPeakElement(vector<int>& nums)
//    {
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (nums[mid] > nums[mid + 1]) right = mid;
//            else /*if(nums[mid] < target)*/ left = mid + 1;
//        }
//        return left;
//    }
//};











/***************************************** 寻找旋转排序数组中的最小值（LeetCode）****************************************/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findMin(vector<int>& nums)
//    {
//        int left = 0, right = nums.size() - 1;
//        int flag = nums[right];//记录翻转后数组中的最后一个数
//        while (left < right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (nums[mid] > flag) left = mid + 1;
//            else /*if(nums[mid] < flag)*/ right = mid;
//        }
//        return nums[right];
//    }
//};









/************************************************* 点名（LeetCode）******************************************************/
/*
某班级 n 位同学的学号为 0 ~ n-1。点名结果记录于升序数组 records。假定仅有一位同学缺席，请返回他的学号
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int takeAttendance(vector<int>& records)
//    {
//        int left = 0, right = records.size() - 1;
//        while (left < right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (records[mid] == mid) left = mid + 1;
//            else right = mid;
//        }
//        return records[left] == left ? left + 1 : left;
//    }
//};









/****************************************************** 前缀和（牛客）***************************************************/
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int num = 0, q = 0;
//    cin >> num >> q;
//
//    vector<long long> ret(num + 1, 0);
//    int tmp = 0;
//    for (int i = 1; i <= num; ++i) {
//        cin >> tmp;
//        ret[i] = ret[i - 1] + tmp;
//    }
//
//    for (int i = 0; i < q; ++i)
//    {
//        int left = 0, right = 0;
//        cin >> left >> right;
//        cout << ret[right] - ret[left - 1] << endl;
//    }
//    return 0;
//}









/*************************************************** 二维前缀和（牛客）**************************************************/
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int num = 0, m = 0, q = 0;
//    cin >> num >> m >> q;
//    vector<vector<long long>> ret(num + 1, vector<long long>(m + 1));
//
//    int tmp = 0;
//    for (int i = 1; i <= num; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            cin >> tmp;
//            ret[i][j] = ret[i - 1][j] + ret[i][j - 1] - ret[i - 1][j - 1] + tmp;
//        }
//    }
//    for (int i = 0; i < q; ++i)
//    {
//        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
//        cin >> x1 >> y1 >> x2 >> y2;
//        cout << ret[x2][y2] - ret[x2][y1 - 1] - ret[x1 - 1][y2] + ret[x1 - 1][y1 - 1] << endl;
//    }
//}










/*********************************************** 寻找数组的中心下标（LeetCode）******************************************/
/*
给你一个整数数组 nums ，请计算数组的中心下标
数组中心下标是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和
如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用
如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回-1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int pivotIndex(vector<int>& nums)
//    {
//        int total = 0;
//        for (int& it : nums) total += it;
//        int leftSum = 0;//记录左侧之和
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            if (i - 1 >= 0) leftSum += nums[i - 1];
//            if (2 * leftSum + nums[i] == total) return i;
//        }
//        return -1;
//    }
//};










/*********************************************** 除自身以外数组的乘积（LeetCode）****************************************/
/*
给你一个整数数组nums，返回数组answer，其中answer[i]等于nums中除nums[i]之外其余各元素的乘积
题目数据保证数组nums之中任意元素的全部前缀元素和后缀的乘积都在32位整数范围内
请不要使用除法，且在O(n)时间复杂度内完成此题
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums)
//    {
//        int size = nums.size();
//        vector<int> left(size), right(size);//left[i]: i左侧所有数字的乘积 、right[i]: i右侧所有数字的乘积
//        vector<int> answer(size);
//        //填充left、right
//        left[0] = right[size - 1] = 1;
//        for (int i = 1; i < size; ++i) left[i] = left[i - 1] * nums[i - 1];
//        for (int i = size - 2; i >= 0; --i) right[i] = right[i + 1] * nums[i + 1];
//        //填充answer
//        for (int i = 0; i < size; ++i) answer[i] = left[i] * right[i];
//        return answer;
//    }
//};










/************************************************ 和为K的子数组（LeetCode）**********************************************/
/*
给你一个整数数组nums和一个整数k，请你统计并返回该数组中和为k的连续子数组的个数
子数组是数组中元素的连续非空序列
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k)
//    {
//        unordered_map<int, int> hash;//统计前缀和出现的次数
//        hash[0] = 1;
//
//        int sum = 0, ret = 0;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            sum += nums[i];//计算当前位置的前缀和
//            if (hash.count(sum - k)) ret += hash[sum - k];//统计个数
//            ++hash[sum];
//        }
//        return ret;
//    }
//};










/********************************************** 和可被K整除的子数组（LeetCode）******************************************/
/*
给定一个整数数组nums和一个整数k，返回其中元素之和可被k整除的（连续、非空）子数组的数目
子数组是数组的连续部分
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution
//{
//public:
//    /*
//    同余定理:
//    (a - b) / p = k ... 0
//    a - b = p * k
//    a = b + p * k
//    a % p = (b + p * k) % p = b % p
//    可得 a % p = b % p
//    */
//    /*
//    C++中负数取模
//    (a % p + p) % p
//    */
//    int subarraysDivByK(vector<int>& nums, int k)
//    {
//        unordered_map<int, int> hash;
//        hash[0 % k] = 1;
//
//        int sum = 0, ret = 0;
//        for (auto x : nums)
//        {
//            sum += x; // 算出当前位置的前缀和
//            int r = (sum % k + k) % k; // 修正后的余数
//            if (hash.count(r)) ret += hash[r]; // 统计结果
//            hash[r]++;
//        }
//        return ret;
//    }
//};










/*************************************************** 连续数组（LeetCode）************************************************/
/*
给定一个二进制数组nums ,找到含有相同数量的0和1的最长连续子数组，并返回该子数组的长度
*/
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//class Solution
//{
//public:
//    /*
//    将0记为-1, 1记为1, 问题就变成了找出⼀段区间，这段区间的和等于0
//    */
//    int findMaxLength(vector<int>& nums)
//    {
//        unordered_map<int, int> hash;//前缀和 : 下标
//        hash[0] = -1;
//
//        int sum = 0, ret = 0;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            sum += (nums[i] == 0 ? -1 : 1);
//            if (hash.count(sum)) ret = max(ret, i - hash[sum]);
//            else hash[sum] = i;//只保留前面的,因为越长越好
//        }
//        return ret;
//    }
//};










/*********************************************** 矩阵区域和（LeetCode）**************************************************/
/*
给你一个m x n的矩阵mat和一个整数k，请你返回一个矩阵answer，其中每个answer[i][j]是所有满足下述条件的元素 mat[r][c] 的和：
i - k <= r <= i + k, j - k <= c <= j + k 且 (r, c) 在矩阵内
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
//    {
//        int row = mat.size(), col = mat[0].size();
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1));
//        //预处理前缀和矩阵(dp[i,j] : [1,1]到[i,j]所围成的矩阵的和)
//        for (int i = 1; i <= row; ++i)
//            for (int j = 1; j <= col; ++j)
//                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
//        //使用前缀和矩阵
//        vector<vector<int>> answer(row, vector<int>(col));
//        for (int i = 0; i < row; ++i)
//        {
//            for (int j = 0; j < col; ++j)
//            {
//                int x1 = max(0, i - k) + 1, y1 = max(0, j - k) + 1;
//                int x2 = min(row - 1, i + k) + 1, y2 = min(col - 1, j + k) + 1;
//                answer[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
//            }
//        }
//        return answer;
//    }
//};










/************************************************* 判定字符是否唯一（LeetCode）******************************************/
/*
实现一个算法，确定一个字符串s的所有字符是否全都不同
*/
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    bool isUnique(string astr)
//    {
//        if (astr.size() > 26) return false;
//
//        int bitMap = 0;
//        for (int i = 0; i < astr.size(); ++i)
//        {
//            int tmp = astr[i] - 'a';
//            if (((bitMap >> tmp) & 1) == 1) return false;
//            bitMap |= (1 << tmp);
//        }
//        return true;
//    }
//};










/**************************************************** 丢失的数字（LeetCode）*********************************************/
/*
给定一个包含[0, n]中n个数的数组nums，找出[0, n]这个范围内没有出现在数组中的那个数
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    int missingNumber(vector<int>& nums)
//    {
//        int ret = 0;
//        for (int i = 0; i <= nums.size(); ++i) ret ^= i;
//        for (int& it : nums) ret ^= it;
//        return ret;
//    }
//};










/*************************************************** 两整数之和（LeetCode）**********************************************/
/*
给你两个整数a和b，不使用运算符+和-​​​​​​，计算并返回两整数之和
*/
//class Solution {
//public:
//    int getSum(int a, int b)
//    {
//        while (b != 0)
//        {
//            int tmp = a ^ b;//a与b无进位相加
//            unsigned int carry = (a & b) << 1;//进位
//            a = tmp;
//            b = carry;
//        }
//        return a;
//    }
//};










/*********************************************** 只出现一次的数字II（LeetCode）*******************************************/
/*
给你一个整数数组nums，除某个元素仅出现一次外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素
你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*
//    每一位的情况：
//    3n个0 一个1     相加得1     %3   == 1
//    3n个0 一个0     相加得0     %3   == 0
//    3n个1 一个1     相加得3n+1  %3   == 1
//    3n个1 一个0     相加得3n    %3   == 0
//    */
//    int singleNumber(vector<int>& nums)
//    {
//        int ret = 0;
//        for (int i = 0; i < 32; ++i)//依次修改ret的每一位
//        {
//            int sum = 0;
//            for (int j = 0; j < nums.size(); ++j)
//                if (((nums[j] >> i) & 1) == 1) ++sum;
//            sum %= 3;
//            if (sum == 1) ret |= (1 << i);
//        }
//        return ret;
//    }
//};










/************************************************ 消失的两个数字（LeetCode）**********************************************/
/*
给定一个数组，包含从1到N所有的整数，但其中缺了两个数字。你能在O(N)时间内只用O(1)的空间找到它们吗？
以任意顺序返回这两个数字均可
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> missingTwo(vector<int>& nums)
//    {
//        int mask = 0;
//        for (int& it : nums) mask ^= it;
//        for (int i = 1; i <= nums.size() + 2; ++i) mask ^= i;
//
//        int type1 = 0, type2 = 0;
//        int lowbit = (mask == INT_MIN ? mask : mask & (-mask));
//
//        for (int& it : nums) {
//            if (it & lowbit) type1 ^= it;
//            else type2 ^= it;
//        }
//        for (int i = 1; i <= nums.size() + 2; ++i) {
//            if (i & lowbit) type1 ^= i;
//            else type2 ^= i;
//        }
//        return { type1, type2 };
//    }
//};















/************************************************* 替换所有的问号（LeetCode）**********************************************/
/*
给你一个仅包含小写英文字母和'?'字符的字符串s，请你将所有的'?'转换为若干小写字母，使最终的字符串不包含任何连续重复的字符
注意：你 不能 修改非 '?' 字符
题目测试用例保证 除 '?' 字符 之外，不存在连续重复的字符
在完成所有转换（可能无需转换）后返回最终的字符串。如果有多个解决方案，请返回其中任何一个。可以证明，在给定的约束条件下，答案总是存在的
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    string modifyString(string s)
//    {
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (s[i] == '?')
//            {
//                for (int j = 0; j < 26; ++j)
//                {
//                    if (i - 1 >= 0 && s[i - 1] == ('a' + j)) continue;
//                    if (i + 1 < s.size() && s[i + 1] == ('a' + j)) continue;
//                    s[i] = ('a' + j);
//                }
//            }
//        }
//        return s;
//    }
//};










/*************************************************** 提莫攻击（LeetCode）*************************************************/
/*
在《英雄联盟》的世界中，有一个叫“提莫”的英雄。他的攻击可以让敌方英雄艾希（编者注：寒冰射手）进入中毒状态
当提莫攻击艾希，艾希的中毒状态正好持续duration秒
正式地讲，提莫在t发起攻击意味着艾希在时间区间[t, t + duration - 1]（含t和t + duration - 1）处于中毒状态
如果提莫在中毒影响结束 前 再次攻击，中毒状态计时器将会重置，在新的攻击之后，中毒影响将会在duration秒后结束
给你一个非递减的整数数组timeSeries，其中timeSeries[i]表示提莫在timeSeries[i]秒时对艾希发起攻击，
以及一个表示中毒持续时间的整数duration。返回艾希处于中毒状态的总秒数
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findPoisonedDuration(vector<int>& timeSeries, int duration)
//    {
//        int ret = 0;
//        for (int i = 1; i < timeSeries.size(); ++i)
//        {
//            int tmp = timeSeries[i] - timeSeries[i - 1];
//            if (tmp >= duration) ret += duration;
//            else ret += tmp;
//        }
//        return ret + duration;
//    }
//};












/****************************************************** N字形变换（LeetCode）******************************************************/
/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串
*/
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    string convert(string s, int numRows)
//    {
//        if (numRows == 1) return s;
//        string ret;
//        int d = 2 * numRows - 2, size = s.size();
//        //第一行
//        for (int i = 0; i < size; i += d) ret += s[i];
//        //中间行
//        for (int k = 1; k < numRows - 1; ++k)//枚举每一行 
//        {
//            for (int i = k, j = d - k; i < size || j < size; i += d, j += d) {
//                if (i < size) ret += s[i];
//                if (j < size) ret += s[j];
//            }
//        }
//        //最后一行
//        for (int i = numRows - 1; i < size; i += d) ret += s[i];
//        return ret;
//    }
//};











/************************************************** 外观数列（LeetCode）***************************************************/
/*
给定一个正整数n，输出外观数列的第n项
「外观数列」是一个整数序列，从数字1开始，序列中的每一项都是对前一项的描述
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    string countAndSay(int n)
//    {
//        string ret = "1";
//        for (int i = 0; i < n - 1; ++i)
//        {
//            string tmp;
//            int length = ret.size();
//            for (int left = 0, right = 0; right < length;)
//            {
//                while (right < length && ret[left] == ret[right]) ++right;
//                tmp += (to_string(right - left) + ret[left]);
//                left = right;
//            }
//            ret = tmp;
//        }
//        return ret;
//    }
//};











/**************************************************** 数青蛙（LeetCode）**************************************************/
/*
给你一个字符串 croakOfFrogs，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合
由于同一时间可以有多只青蛙呱呱作响，所以croakOfFrogs中会混合多个“croak”
请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目
要想发出蛙鸣"croak"，青蛙必须依序输出‘c’,’r’,’o’,’a’,’k’这5个字母
如果没有输出全部五个字母，那么它就不会发出声音。如果字符串croakOfFrogs不是由若干有效的"croak"字符混合而成，请返回-1
*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int minNumberOfFrogs(string croakOfFrogs)
//    {
//        string str = "croak";
//        int size = str.size();
//
//        vector<int> hash(size);
//        unordered_map<char, int> index;//char字符存在hash中的哪个下标
//        for (int i = 0; i < size; ++i) index[str[i]] = i;
//
//        for (char& ch : croakOfFrogs)
//        {
//            if (ch == 'c') {
//                if (hash[size - 1] != 0) --hash[size - 1];
//                ++hash[0];
//            }
//            else {
//                int i = index[ch];
//                if (hash[i - 1] == 0) return -1;
//                else --hash[i - 1], ++hash[i];
//            }
//        }
//        for (int i = 0; i < size - 1; ++i) if (hash[i] != 0) return -1;
//        return hash[size - 1];
//    }
//};










/***************************************************** 颜色分类（LeetCode）***********************************************/
/*
给定一个包含红色、白色和蓝色、共n个元素的数组 nums ，原地对它们进行排序，
使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色
必须在不使用库内置的 sort 函数的情况下解决这个问题
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    //快排思想: 分三块  
//    void sortColors(vector<int>& nums)
//    {
//        int left = -1, right = nums.size(), current = 0;
//        while (current < right)
//        {
//            if (nums[current] == 0) swap(nums[++left], nums[current++]);
//            else if (nums[current] == 1) ++current;
//            else /*nums[current] == 2*/ swap(nums[--right], nums[current]);
//        }
//    }
//};











/************************************************** 排序数组（LeetCode）************************************************/
/*
给你一个整数数组 nums，请你将该数组升序排列
*/
//三区间快排
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    //适用有大量重复数据的情况
//    vector<int> sortArray(vector<int>& nums)
//    {
//        srand(time(NULL));
//        QuickSort(nums, 0, nums.size() - 1);
//        return nums;
//    }
//    void QuickSort(vector<int>& nums, int left, int right)
//    {
//        if (left >= right) return;
//        int keyValue = GetRandom(nums, left, right);
//        int begin = left - 1, end = right + 1, current = left;
//        while (current < end)
//        {
//            if (nums[current] < keyValue) swap(nums[++begin], nums[current++]);
//            else if (nums[current] == keyValue) ++current;
//            else /*nums[current] > keyValue*/ swap(nums[--end], nums[current]);
//        }
//        QuickSort(nums, left, begin);
//        QuickSort(nums, end, right);
//    }
//    int GetRandom(vector<int>& nums, int left, int right)
//    {
//        int randNum = rand();
//        return nums[randNum % (right - left + 1) + left];
//    }
//};











/********************************************** 数组中的第K个最大元素（LeetCode）**************************************/
/*
给定整数数组nums和整数k，请返回数组中第k个最大的元素
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k)
//    {
//        srand(time(NULL));
//        return GetResult(nums, 0, nums.size() - 1, k);
//    }
//    int GetResult(vector<int>& nums, int left, int right, int k)
//    {
//        if (left == right) return nums[left];
//
//        int keyValue = GetRandom(nums, left, right);
//        int begin = left - 1, end = right + 1, current = left;
//        while (current < end)
//        {
//            if (nums[current] < keyValue) swap(nums[++begin], nums[current++]);
//            else if (nums[current] == keyValue) ++current;
//            else /*nums[current] > keyValue*/ swap(nums[--end], nums[current]);
//        }
//        int b = end - begin - 1, c = right - end + 1;
//        if (c >= k) return GetResult(nums, end, right, k);//最右区间
//        else if (b + c >= k) return keyValue;//中间
//        else return GetResult(nums, left, begin, k - b - c);//最左区间
//    }
//    int GetRandom(vector<int>& nums, int left, int right) {
//        return nums[rand() % (right - left + 1) + left];
//    }
//};











/*************************************************** 库存管理III（LeetCode）*******************************************/
/*
仓库管理员以数组stock形式记录商品库存表，其中stock[i]表示对应商品库存余量
请返回库存余量最少的cnt个商品余量，返回顺序不限
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> inventoryManagement(vector<int>& stock, int cnt)
//    {
//        srand(time(NULL));
//        GetResult(stock, 0, stock.size() - 1, cnt);
//        return { stock.begin(), stock.begin() + cnt };
//    }
//    void GetResult(vector<int>& nums, int left, int right, int k)
//    {
//        if (left >= right) return;
//        int KeyValue = GetRandom(nums, left, right);
//        int begin = left - 1, end = right + 1, current = left;
//        while (current < end)
//        {
//            if (nums[current] < KeyValue) swap(nums[++begin], nums[current++]);
//            else if (nums[current] == KeyValue) ++current;
//            else swap(nums[--end], nums[current]);
//        }
//        int a = begin - left + 1, b = end - begin - 1;
//        if (a > k) GetResult(nums, left, begin, k);
//        else if (a + b >= k) return;
//        else GetResult(nums, end, right, k - a - b);
//    }
//    int GetRandom(vector<int>& nums, int left, int right) {
//        return nums[rand() % (right - left + 1) + left];
//    }
//};











/************************************************* 排序数组（LeetCode）************************************************/
/*
给你一个整数数组 nums，请你将该数组升序排列
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> sortArray(vector<int>& nums)
//    {
//        vector<int> tmp(nums.size());
//        _MerageSort(nums, 0, nums.size() - 1, tmp);
//        return nums;
//    }
//    void _MerageSort(vector<int>& nums, int left, int right, vector<int>& tmp)
//    {
//        if (left >= right) return;
//        int mid = left + ((right - left) >> 1);
//        _MerageSort(nums, left, mid, tmp);
//        _MerageSort(nums, mid + 1, right, tmp);
//
//        int current1 = left, current2 = mid + 1, index = left;
//        while (current1 <= mid && current2 <= right)
//            tmp[index++] = nums[current1] < nums[current2] ? nums[current1++] : nums[current2++];
//        while (current1 <= mid) tmp[index++] = nums[current1++];
//        while (current2 <= right) tmp[index++] = nums[current2++];
//
//        for (int i = left; i <= right; ++i) nums[i] = tmp[i];
//    }
//};










/********************************************* 交易逆序对的总数（LeetCode）********************************************/
/*
在股票交易中，如果前一天的股价高于后一天的股价，则可以认为存在一个「交易逆序对」
请设计一个程序，输入一段时间内的股票交易记录 record，返回其中存在的「交易逆序对」总数
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> tmp;
//    int reversePairs(vector<int>& record)
//    {
//        tmp.resize(record.size());
//        return _Merage(record, 0, record.size() - 1);
//    }
//    int _Merage(vector<int>& nums, int left, int right)
//    {
//        if (left >= right) return 0;
//        int ret = 0;
//        int mid = left + ((right - left) >> 1);
//        ret += _Merage(nums, left, mid);
//        ret += _Merage(nums, mid + 1, right);
//
//        int current1 = left, current2 = mid + 1, index = left;
//        while (current1 <= mid && current2 <= right)
//        {
//            if (nums[current1] <= nums[current2]) {
//                tmp[index++] = nums[current1++];
//            }
//            else {
//                ret += mid - current1 + 1;
//                tmp[index++] = nums[current2++];
//            }
//        }
//        while (current1 <= mid) tmp[index++] = nums[current1++];
//        while (current2 <= right) tmp[index++] = nums[current2++];
//        for (int i = left; i <= right; ++i) nums[i] = tmp[i];
//        return ret;
//    }
//};










/******************************************** 计算右侧小于当前元素的个数（LeetCode）***********************************/
/*
给你一个整数数组nums，按要求返回一个新数组counts
数组counts有该性质：counts[i]的值是nums[i]右侧小于nums[i]的元素的数量
*/
//#include <iostream>
//#include <vecctor>
//using namespace std;
//class Solution {
//public:
//    vector<int> ret;
//    vector<int> index;
//    vector<int> tmpNums;
//    vector<int> tmpIndex;
//
//    vector<int> countSmaller(vector<int>& nums)
//    {
//        int size = nums.size();
//        ret.resize(size);
//        index.resize(size);
//        tmpNums.resize(size);
//        tmpIndex.resize(size);
//        for (int i = 0; i < size; ++i) index[i] = i;
//
//        Merage(nums, 0, size - 1);
//        return ret;
//    }
//    void Merage(vector<int>& nums, int left, int right)
//    {
//        if (left >= right) return;
//        int mid = (left + right) >> 1;
//        Merage(nums, left, mid);
//        Merage(nums, mid + 1, right);
//
//        int current1 = left, current2 = mid + 1, it = left;
//        while (current1 <= mid && current2 <= right)
//        {
//            if (nums[current1] <= nums[current2]) {
//                tmpNums[it] = nums[current2];
//                tmpIndex[it++] = index[current2++];
//            }
//            else {
//                ret[index[current1]] += right - current2 + 1;
//                tmpNums[it] = nums[current1];
//                tmpIndex[it++] = index[current1++];
//            }
//        }
//        while (current1 <= mid) {
//            tmpNums[it] = nums[current1];
//            tmpIndex[it++] = index[current1++];
//        }
//        while (current2 <= right) {
//            tmpNums[it] = nums[current2];
//            tmpIndex[it++] = index[current2++];
//        }
//        for (int i = left; i <= right; ++i) {
//            nums[i] = tmpNums[i];
//            index[i] = tmpIndex[i];
//        }
//    }
//};










/************************************************* 翻转对（LeetCode）**************************************************/
/*
给定一个数组nums，如果i < j且nums[i] > 2 * nums[j]我们就将(i, j)称作一个重要翻转对
你需要返回给定数组中的重要翻转对的数量
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<int> tmp;
//    int reversePairs(vector<int>& nums)
//    {
//        int size = nums.size();
//        tmp.resize(size);
//        return Merage(nums, 0, size - 1);
//    }
//    int Merage(vector<int>& nums, int left, int right)
//    {
//        int ret = 0;
//        if (left >= right) return ret;
//
//        int mid = (right + left) >> 1;
//        ret += Merage(nums, left, mid);
//        ret += Merage(nums, mid + 1, right);
//
//        int current1 = left, current2 = mid + 1, it = left;
//        while (current1 <= mid) //降序
//        {
//            while (current2 <= right && nums[current2] >= nums[current1] / 2.0) current2++;
//            if (current2 > right) break;
//            ret += right - current2 + 1;
//            current1++;
//        }
//
//        current1 = left, current2 = mid + 1;
//        while (current1 <= mid && current2 <= right)
//            tmp[it++] = nums[current1] <= nums[current2] ? nums[current2++] : nums[current1++];
//        while (current1 <= mid) tmp[it++] = nums[current1++];
//        while (current2 <= right) tmp[it++] = nums[current2++];
//
//        for (int i = left; i <= right; ++i) nums[i] = tmp[i];
//        return ret;
//    }
//};












/**************************************************** 两数相加（LeetCode）************************************************/
/*
给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字
请你将两个数相加，并以相同形式返回一个表示和的链表
你可以假设除了数字 0 之外，这两个数都不会以 0 开头
*/
//#include <iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//    {
//        int tmp = 0;
//        ListNode* newHead = nullptr, * newTail = nullptr;
//        ListNode* list1 = l1, * list2 = l2;
//        while (list1 != nullptr || list2 != nullptr || tmp != 0)
//        {
//            int num1 = list1 ? list1->val : 0;
//            int num2 = list2 ? list2->val : 0;
//            int sum = num1 + num2 + tmp;
//            if (newHead == nullptr) {
//                newHead = newTail = new ListNode(sum % 10);
//            }
//            else {
//                newTail->next = new ListNode(sum % 10);
//                newTail = newTail->next;
//            }
//            tmp = sum / 10;
//            if (list1) list1 = list1->next;
//            if (list2) list2 = list2->next;
//        }
//        return newHead;
//    }
//};











/********************************************* 两两交换链表中的节点（LeetCode）*******************************************/
/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）
*/
//#include <iostream>
//using namespace std;
//struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head)
//    {
//        if (head == nullptr || head->next == nullptr) return head;
//
//        ListNode* newHead = new ListNode(0);
//        newHead->next = head;
//
//        ListNode* prev = newHead, * current = head, * next = current->next, * nnext = next->next;
//        while (current && next)
//        {
//            prev->next = next;
//            next->next = current;
//            current->next = nnext;
//
//            prev = current;
//            current = nnext;
//            if (current != nullptr) next = current->next;
//            if (next != nullptr) nnext = next->next;
//        }
//        current = newHead->next;
//        delete newHead;
//        return current;
//    }
//};












/***************************************************** 重排链表（LeetCode）***********************************************/
/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换
*/
//#include <iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    void reorderList(ListNode* head)
//    {
//        if (head == nullptr || head->next == nullptr) return;
//        ListNode* mid = GetMid(head);
//
//        ListNode* list1 = head;
//        ListNode* list2 = mid->next;
//        mid->next = nullptr;
//        list2 = ReverseList(list2);
//        Merage(list1, list2);
//    }
//    ListNode* GetMid(ListNode* head)
//    {
//        ListNode* slow = head, * fast = head;
//        while (fast != nullptr && fast->next != nullptr) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//    ListNode* ReverseList(ListNode* head)
//    {
//        ListNode* prev = nullptr;
//        ListNode* current = head;
//        while (current != nullptr)
//        {
//            ListNode* next = current->next;
//            current->next = prev;
//            prev = current;
//            current = next;
//        }
//        return prev;
//    }
//    void Merage(ListNode* list1, ListNode* list2)
//    {
//        ListNode* tmpL1 = nullptr, * tmpL2 = nullptr;
//        while (list1 != nullptr && list2 != nullptr)
//        {
//            tmpL1 = list1->next;
//            tmpL2 = list2->next;
//
//            list1->next = list2;
//            list1 = tmpL1;
//            list2->next = list1;
//            list2 = tmpL2;
//        }
//    }
//};









/***************************************** 合并K个升序链表（LeetCode）*************************************/
/*
给你一个链表数组，每个链表都已经按升序排列
请你将所有链表合并到一个升序链表中，返回合并后的链表
*/
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
////1.堆结构
//class Solution1 {
//public:
//    struct Compare {
//        bool operator()(ListNode* node1, ListNode* node2) {
//            return node1->val > node2->val;
//        }
//    };
//    ListNode* mergeKLists(vector<ListNode*>& lists)
//    {
//        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
//        for (ListNode* node : lists) if (node) pq.push(node);
//
//        ListNode* ret = new ListNode(0);
//        ListNode* tail = ret;
//        while (!pq.empty())
//        {
//            tail->next = pq.top();
//            pq.pop();
//            tail = tail->next;
//            if (tail->next != nullptr) pq.push(tail->next);
//        }
//        tail = ret->next;
//        delete ret;
//        return tail;
//    }
//};
////2.归并
//class Solution2 {
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        return Merage(lists, 0, lists.size() - 1);
//    }
//    ListNode* Merage(vector<ListNode*>& lists, int left, int right)
//    {
//        if (left > right) return nullptr;
//        if (left == right) return lists[left];
//        int mid = (left + right) >> 1;
//        ListNode* list1 = Merage(lists, left, mid);
//        ListNode* list2 = Merage(lists, mid + 1, right);
//        return Merage2List(list1, list2);
//    }
//    ListNode* Merage2List(ListNode* list1, ListNode* list2)
//    {
//        if (list1 == nullptr) return list2;
//        if (list2 == nullptr) return list1;
//        ListNode* newHead = new ListNode(0);
//        ListNode* current1 = list1, * current2 = list2, * tail = newHead;
//        while (current1 != nullptr && current2 != nullptr)
//        {
//            if (current1->val < current2->val) {
//                tail->next = current1;
//                current1 = current1->next;
//            }
//            else {
//                tail->next = current2;
//                current2 = current2->next;
//            }
//            tail = tail->next;
//        }
//        if (current1 != nullptr) tail->next = current1;
//        if (current2 != nullptr) tail->next = current2;
//        tail = newHead->next;
//        delete newHead;
//        return tail;
//    }
//};
//int main()
//{
//    //[1, 4, 5] , [1, 3, 4], [2, 6]
//    vector<ListNode*> v;
//    ListNode* node = nullptr;
//    v.push_back(node);
//    /*ListNode* L1 = new ListNode(1);
//    ListNode* L2 = new ListNode(4);
//    ListNode* L3 = new ListNode(5);
//    L1->next = L2;
//    L2->next = L3;
//    v.push_back(L1);
//    L1 = new ListNode(1);
//    L2 = new ListNode(3);
//    L3 = new ListNode(4);
//    L1->next = L2;
//    L2->next = L3;
//    v.push_back(L1);
//    L1 = new ListNode(2);
//    L2 = new ListNode(6);
//    L1->next = L2;
//    v.push_back(L1);*/
//
//    Solution2 s;
//    ListNode* list = s.mergeKLists(v);
//    while (list != nullptr) {
//        cout << list->val << " ";
//        list = list->next;
//    }
//    return 0;
//}










/***************************************** K个一组翻转链表（LeetCode）*************************************/
/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表
k是一个正整数，它的值小于或等于链表的长度。如果节点总数不是k的整数倍，那么请将最后剩余的节点保持原有顺序
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//}; 
//class Solution {
//public:
//    ListNode* reverseKGroup(ListNode* head, int k)
//    {
//        //计算出需要翻转多少次
//        int number = 0;
//        for (ListNode* current = head; current != nullptr; current = current->next, ++number);
//        number /= k;
//        //每次翻转k个为一组的链表
//        ListNode* newHead = new ListNode(0);
//        ListNode* tail = newHead;//每次头插到该结点的后一个位置
//        ListNode* current = head;
//        for (int i = 0; i < number; ++i)
//        {
//            ListNode* tmp = current;
//            for (int j = 0; j < k; ++j) {
//                ListNode* next = current->next;
//                current->next = tail->next;
//                tail->next = current;
//                current = next;
//            }
//            tail = tmp;
//        }
//        //将后续不需要翻转的结点连接起来
//        tail->next = current;
//        current = newHead->next;
//        delete newHead;
//        return current;
//    }
//};









/******************************************** 两数之和（LeetCode）******************************************/
/*
给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target的那两个整数，
并返回它们的数组下标
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现
你可以按任意顺序返回答案
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target)
//    {
//        unordered_map<int, int> hash;//key : index
//        for (int i = 0; i < nums.size(); ++i) hash[nums[i]] = i;
//        for (int i = 0; i < nums.size(); ++i) {
//            auto it = hash.find(target - nums[i]);
//            if (it != hash.end() && it->second != i) return { i, it->second };
//        }
//        return { -1, -1 };
//    }
//};










/**************************************** 判定是否互为字符重排（LeetCode）*********************************/
/*
给定两个由小写字母组成的字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，
能否变成另一个字符串
*/
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    bool CheckPermutation(string s1, string s2)
//    {
//        if (s1.size() != s2.size()) return false;
//        int hash[26] = { 0 };
//        for (char it : s1) hash[it - 'a']++;
//        for (char it : s2) hash[it - 'a']--;
//        bool ret = true;
//        for (int i = 0; i < 26; ++i) if (hash[i] != 0) ret = false;
//        return ret;
//    }
//};









/****************************************** 存在重复元素（LeetCode）***************************************/
/*
给你一个整数数组nums 。如果任一值在数组中出现至少两次，返回true；如果数组中每个元素互不相同，返回false
*/
//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums)
//    {
//        unordered_set<int> hash;
//        for (int i = 0; i < nums.size(); ++i)
//            if (hash.count(nums[i])) return true;
//            else hash.insert(nums[i]);
//        return false;
//    }
//};









/***************************************** 存在重复元素II（LeetCode）**************************************/
/*
给你一个整数数组nums和一个整数k，判断数组中是否存在两个不同的索引i和j，
满足nums[i] == nums[j]且abs(i - j) <= k。如果存在，返回true ；否则，返回false
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k)
//    {
//        unordered_map<int, int> hash;//num, index
//        int size = nums.size();
//        for (int i = 0; i < size; ++i)
//        {
//            auto it = hash.find(nums[i]);
//            if (it == hash.end()) hash[nums[i]] = i;
//            else if (i - it->second <= k) return true;
//            else hash[nums[i]] = i;
//        }
//        return false;
//    }
//};








/******************************************* 最长公共前缀（LeetCode）***************************************/
/*
编写一个函数来查找字符串数组中的最长公共前缀
如果不存在公共前缀，返回空字符串 ""
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs)
//    {
//        string ret = strs[0];
//        for (int i = 1; i < strs.size(); ++i)
//            ret = Compare(ret, strs[i]);
//        return ret;
//    }
//    string Compare(string ret, string str)
//    {
//        int size = min(ret.size(), str.size());
//        for (int i = 0; i < size; ++i) {
//            if (ret[i] == str[i]) continue;
//            else return string(ret.begin(), ret.begin() + i);
//        }
//        return string(ret.begin(), ret.begin() + size);
//    }
//};









/******************************************** 最长回文子串（LeetCode）*************************************/
/*
给你一个字符串 s，找到 s 中最长的回文子串
如果字符串的反序与原始字符串相同，则该字符串称为回文字符串
*/
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    string longestPalindrome(string s)
//    {
//        int size = s.size();
//        int left = 0, right = 0;
//        int begin = -1, maxLength = 0;
//        for (int i = 0; i < size; ++i)//固定一个中心点
//        {
//            //奇数结果
//            left = right = i;
//            while (left >= 0 && right < size && s[left] == s[right])
//                --left, ++right;
//            if (right - left - 1 > maxLength) {
//                begin = left + 1;
//                maxLength = right - left - 1;
//            }
//            //偶数结果
//            left = i, right = i + 1;
//            while (left >= 0 && right < size && s[left] == s[right])
//                --left, ++right;
//            if (right - left - 1 > maxLength) {
//                begin = left + 1;
//                maxLength = right - left - 1;
//            }
//        }
//        return s.substr(begin, maxLength);
//    }
//};









/****************************************** 二进制求和（LeetCode）*****************************************/
/*
给你两个二进制字符串a和b，以二进制字符串的形式返回它们的和
*/
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    string addBinary(string a, string b)
//    {
//        int end1 = a.size() - 1, end2 = b.size() - 1;
//        int tmp = 0;
//        string ret = "";
//        while (end1 >= 0 || end2 >= 0 || tmp > 0)
//        {
//            if (end1 >= 0) tmp += a[end1--] - '0';
//            if (end2 >= 0) tmp += b[end2--] - '0';
//            ret.insert(ret.begin(), (tmp % 2) + '0');
//            tmp /= 2;
//        }
//        return ret;
//    }
//};








/****************************************** 字符串相乘（LeetCode）*****************************************/
/*
给定两个以字符串形式表示的非负整数num1和num2，返回num1和num2的乘积，它们的乘积也表示为字符串形式
注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数
*/
//模拟列竖式运算
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    string multiply(string num1, string num2)
//    {
//        if (num1 == "0" || num2 == "0") return "0";
//        string sum = "0";
//        for (int i = 0; i < num2.size(); ++i)
//            sum = Add(sum, Mul(num1, num2[num2.size() - 1 - i]), i);
//        return sum;
//    }
//    string Mul(string& str, char& ch)
//    {
//        int tmp = 0;
//        string ret = "";
//        for (int i = str.size() - 1; i >= 0; --i)
//        {
//            int num1 = str[i] - '0';
//            tmp += num1 * (ch - '0');
//            ret.insert(ret.begin(), (tmp % 10) + '0');
//            tmp /= 10;
//        }
//        if (tmp != 0) ret.insert(ret.begin(), tmp + '0');
//        return ret;
//    }
//    string Add(string str1, string str2, int count)
//    {
//        for (int i = 0; i < count; ++i) str2 += '0';
//        string ret = "";
//        int tmp = 0;
//        int end1 = str1.size() - 1, end2 = str2.size() - 1;
//        while (end1 >= 0 || end2 >= 0 || tmp > 0)
//        {
//            if (end1 >= 0) tmp += str1[end1--] - '0';
//            if (end2 >= 0) tmp += str2[end2--] - '0';
//            ret.insert(ret.begin(), (tmp % 10) + '0');
//            tmp /= 10;
//        }
//        return ret;
//    }
//};
//无进位相乘后相加，最后处理进位
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    string multiply(string num1, string num2)
//    {
//        if (num1 == "0" || num2 == "0") return "0";
//        int size1 = num1.size(), size2 = num2.size();
//        vector<int> tmp(size1 + size2 - 1);
//        //无进位相乘后相加
//        for (int j = size2 - 1; j >= 0; --j)
//            for (int i = size1 - 1; i >= 0; --i)
//                tmp[i + j] += (num1[i] - '0') * (num2[j] - '0');
//        //处理进位
//        string ret = "";
//        int current = size1 + size2 - 2, tmpNum = 0;
//        while (current >= 0 || tmpNum > 0)
//        {
//            if (current >= 0) tmpNum += tmp[current--];
//            ret.insert(ret.begin(), (tmpNum % 10) + '0');
//            tmpNum /= 10;
//        }
//        return ret;
//    }
//};








/********************************** 删除字符串中的所有相邻重复项（LeetCode）**********************************/
/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们
在 S 上反复执行重复项删除操作，直到无法继续删除
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一
*/
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    string removeDuplicates(string s)
//    {
//        string ret = "";
//        for (int i = 0; i < s.size(); ++i) {
//            if (ret.size() == 0 || s[i] != ret.back()) ret.push_back(s[i]);
//            else ret.pop_back();
//        }
//        return ret;
//    }
//};









/*************************************** 比较含退格的字符串（LeetCode）***************************************/
/*
给定s和t两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回true 。#代表退格字符
注意：如果对空文本输入退格字符，文本继续为空
*/
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    bool backspaceCompare(string s, string t) {
//        return Handle(s) == Handle(t);
//    }
//    string Handle(string& str)
//    {
//        string ret = "";
//        for (int i = 0; i < str.size(); ++i) {
//            if (str[i] == '#' && !ret.empty()) ret.pop_back();
//            else if (str[i] != '#')ret.push_back(str[i]);
//        }
//        return ret;
//    }
//};









/******************************************** 基本计算器II（LeetCode）*****************************************/
/*
给你一个字符串表达式s，请你实现一个基本计算器来计算并返回它的值
整数除法仅保留整数部分
你可以假设给定的表达式总是有效的。所有中间结果将在 [-231, 231 - 1] 的范围内
注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval()
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    int calculate(string s)
//    {
//        vector<int> sk;//使用数组模拟栈
//        int size = s.size(), current = 0;
//        char op = '+';
//        while (current < size)
//        {
//            if (s[current] == ' ') ++current;
//            else if ('0' <= s[current] && s[current] <= '9')
//            {
//                //提取数字
//                int tmp = 0;
//                while (current < size && s[current] >= '0' && s[current] <= '9')
//                    tmp = tmp * 10 + (s[current++] - '0');
//                //处理操作符号
//                if (op == '+') sk.push_back(tmp);
//                else if (op == '-') sk.push_back(-1 * tmp);
//                else if (op == '*') sk.back() *= tmp;
//                else sk.back() /= tmp;
//            }
//            else {//s[current] == 操作符
//                op = s[current++];
//            }
//        }
//        int ret = 0;
//        for (int& it : sk) ret += it;
//        return ret;
//    }
//};










/******************************************* 字符串解码（LeetCode）********************************************/
/*
给定一个经过编码的字符串，返回它解码后的字符串
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入
*/
//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//class Solution {
//public:
//    string decodeString(string s)
//    {
//        stack<int> nums;
//        stack<string> sk;
//        sk.push("");
//
//        int current = 0, size = s.size();
//        while (current < size)
//        {
//            if (s[current] >= '0' && s[current] <= '9')
//            {
//                //提取数字
//                int tmp = 0;
//                while (current < size && s[current] >= '0' && s[current] <= '9')
//                    tmp = tmp * 10 + (s[current++] - '0');
//                nums.push(tmp);
//            }
//            else if (s[current] == '[')
//            {
//                //提取括号中的字符串
//                ++current;
//                string tmp = "";
//                while (s[current] >= 'a' && s[current] <= 'z')
//                    tmp += s[current++];
//                sk.push(tmp);
//            }
//            else if (s[current] == ']')
//            {
//                string tmp = sk.top();
//                sk.pop();
//                int k = nums.top();
//                nums.pop();
//                while (k--) sk.top() += tmp;
//                ++current;
//            }
//            else //提取不在括号中的字符串
//            {
//                string tmp = "";
//                while (current < size && s[current] >= 'a' && s[current] <= 'z')
//                    tmp += s[current++];
//                sk.top() += tmp;
//            }
//        }
//        return sk.top();
//    }
//};










/******************************************** 验证栈序列（LeetCode）*******************************************/
/*
给定pushed和popped两个序列，每个序列中的值都不重复，
只有当它们可能是在最初空栈上进行的推入push和弹出pop操作序列的结果时，返回true；否则，返回false
*/
//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//class Solution {
//public:
//    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
//    {
//        stack<int> sk;
//        int current = 0, size = popped.size();
//        for (int& it : pushed)
//        {
//            sk.push(it);
//            while (sk.size() != 0 && sk.top() == popped[current]) sk.pop(), ++current;
//        }
//        return current == size;
//    }
//};









/******************************************* N叉树的层序遍历（LeetCode）******************************************/
/*
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）
树的序列化输入是用层序遍历，每组子节点都由 null 值分隔
*/
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//class Node {
//public:
//    int val;
//    vector<Node*> children;
//    Node() {}
//    Node(int _val) { val = _val; }
//    Node(int _val, vector<Node*> _children) {
//        val = _val;
//        children = _children;
//    }
//};
//class Solution {
//public:
//    vector<vector<int>> levelOrder(Node* root)
//    {
//        vector<vector<int>> ret;
//        queue<Node*> qe;
//        qe.push(root);
//        if (root == nullptr) return {};
//
//        while (!qe.empty())
//        {
//            vector<int> layer;//存储本层的结点值
//            int size = qe.size();
//            for (int i = 0; i < size; ++i)
//            {
//                //插入结点值
//                Node* front = qe.front();
//                qe.pop();
//                layer.push_back(front->val);
//                //将子结点加入队列中
//                for (Node* it : front->children) if (it != nullptr) qe.push(it);
//            }
//            ret.push_back(layer);
//        }
//        return ret;
//    }
//};









/**************************************** 二叉树的锯齿形层序遍历（LeetCode）**************************************/
/*
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历
（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）
*/
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//class Solution {
//public:
//    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
//    {
//        if (root == nullptr) return {};
//
//        bool flag = true;//正序
//        vector<vector<int>> ret;
//        queue<TreeNode*> qe;
//        qe.push(root);
//
//        while (!qe.empty())
//        {
//            vector<TreeNode*> layer;
//            while (!qe.empty()) {
//                layer.push_back(qe.front());
//                qe.pop();
//            }
//            vector<int> tmp;
//            if (flag) {
//                for (int i = 0; i < layer.size(); ++i) {
//                    tmp.push_back(layer[i]->val);
//                    TreeNode* Left = layer[i]->left, * Right = layer[i]->right;
//                    if (Left) qe.push(Left);
//                    if (Right) qe.push(Right);
//                }
//            }
//            else {
//                for (int i = layer.size() - 1; i >= 0; --i) {
//                    tmp.push_back(layer[i]->val);
//                    TreeNode* Left = layer[layer.size() - 1 - i]->left, * Right = layer[layer.size() - 1 - i]->right;
//                    if (Left) qe.push(Left);
//                    if (Right) qe.push(Right);
//                }
//            }
//            flag == true ? flag = false : flag = true;
//            if (tmp.size() != 0) ret.push_back(tmp);
//        }
//        return ret;
//    }
//};










/******************************************* 二叉树最大宽度（LeetCode）****************************************/
/*
给你一棵二叉树的根节点root ，返回树的 最大宽度
树的最大宽度是所有层中最大的宽度
每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度
将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的null节点，这些null节点也计入长度
题目数据保证答案将会在32 位带符号整数范围内
*/
//#include <iostream>
//#include <queue>
//#include <utility>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//class Solution {
//public:
//    typedef unsigned long long ull;
//    int widthOfBinaryTree(TreeNode* root)
//    {
//        if (root == nullptr) return {};
//        ull maxWidth = 0;
//        queue<pair<TreeNode*, ull>> qe;
//        qe.push({ root, 1 });
//
//        while (!qe.empty())
//        {
//            //更新本层宽度
//            pair<TreeNode*, ull> front = qe.front();
//            pair<TreeNode*, ull> back = qe.back();
//            maxWidth = max(maxWidth, back.second - front.second + 1);
//            //记录本层队列中的元素个数
//            int count = qe.size();
//            //下一层进入队列 并 清空队列中本层元素
//            for (int i = 0; i < count; ++i) {
//                auto& [x ,y] = qe.front();//C++17新语法
//                if (x->left) qe.push({ x->left, y * 2 });
//                if (x->right) qe.push({ x->right, y * 2 + 1 });
//                qe.pop();
//            }
//        }
//        return (int)maxWidth;
//    }
//};










/****************************************** 在每个树行中找最大值（LeetCode）***********************************/
/*
给定一棵二叉树的根节点root ，请找出该二叉树中每一层的最大值
*/
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//class Solution {
//public:
//    vector<int> largestValues(TreeNode* root)
//    {
//        vector<int> ret;
//        if (root == nullptr) return ret;
//
//        queue<TreeNode*> qe;
//        qe.push(root);
//
//        while (!qe.empty())
//        {
//            int size = qe.size();
//            long long maxNum = LONG_MIN;//记录每层的最大值
//            for (int i = 0; i < size; ++i)
//            {
//                //取出队列中本层的每个元素
//                TreeNode* front = qe.front();
//                qe.pop();
//                //更新本层中的最大值
//                maxNum = max(maxNum, (long long)front->val);
//                //加入下一层结点
//                if (front->left) qe.push(front->left);
//                if (front->right) qe.push(front->right);
//            }
//            ret.push_back(maxNum);
//        }
//        return ret;
//    }
//};








/**************************************** 最后一块石头的重量（LeetCode）***************************************/
/*
有一堆石头，每块石头的重量都是正整数
每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎
假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回0
*/
//#include <iostream>
//#include <queue>
//using namespace std;
//class Solution {
//public:
//    int lastStoneWeight(vector<int>& stones)
//    {
//        priority_queue<int> qe;
//        for (auto& it : stones) qe.push(it);
//
//        while (qe.size() > 1)
//        {
//            int x = qe.top();
//            qe.pop();
//            int y = qe.top();
//            qe.pop();
//            if (x > y) qe.push(x - y);//因为使用的是大堆,不可能出现x < y的情况;若x == y,不处理则相当于丢弃
//        }
//        return qe.empty() ? 0 : qe.top();
//    }
//};








/************************************** 数据流中的第K大元素（LeetCode）****************************************/
/*
设计一个找到数据流中第k大元素的类（class）。注意是排序后的第k大元素，不是第k个不同的元素
请实现 KthLargest 类：
KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象
int add(int val)将val插入数据流 nums 后，返回当前数据流中第k大的元素
*/
//#include <iostream>
//#include <queue>
//using namespace std;
//class KthLargest {
//public:
//    priority_queue<int, vector<int>, greater<int>> _numbers;//小根堆
//    int _k;
//    KthLargest(int k, vector<int>& nums) {
//        for (int& it : nums) {
//            _numbers.push(it);
//            if (_numbers.size() > k) _numbers.pop();
//        }
//        _k = k;
//    }
//    int add(int val) {
//        _numbers.push(val);
//        if (_numbers.size() > _k) _numbers.pop();
//        return _numbers.top();
//    }
//};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */








/****************************************** 前K个高频单词（LeetCode）******************************************/
/*
给定一个单词列表words和一个整数 k ，返回前 k 个出现次数最多的单词
返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， 按字典顺序 排序
*/
//#include <iostream>
//#include <queue>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    struct Compare {
//        bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
//            if (p1.second == p2.second) // 频次相同，字典序按照⼤根堆的⽅式排列
//                return p1.first < p2.first;
//            return p1.second > p2.second;
//        }
//    };
//    vector<string> topKFrequent(vector<string>& words, int k)
//    {
//        unordered_map<string, int> hash;
//        for (auto& it : words) hash[it]++;
//
//        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> qe;
//        for (auto& it : hash) {
//            qe.push(it);
//            if (qe.size() > k) qe.pop();
//        }
//
//        vector<string> ret(k);
//        for (int i = k - 1; i >= 0; --i) {
//            ret[i] = qe.top().first;
//            qe.pop();
//        }
//        return ret;
//    }
//};








/***************************************** 数据流的中位数（LeetCode）******************************************/
/*
中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值
例如 arr = [2,3,4] 的中位数是3
例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5
实现 MedianFinder 类:
MedianFinder() 初始化 MedianFinder 对象
void addNum(int num) 将数据流中的整数 num 添加到数据结构中
double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受
*/
//#include <iostream>
//#include <queue>
//using namespace std;
//class MedianFinder {
//public:
//    priority_queue<int> _bigHeap;//大根堆 - left
//    priority_queue<int, vector<int>, greater<int>> _smallHeap;//小根堆 - right
//    MedianFinder() {}
//    void addNum(int num)
//    {
//        if (_bigHeap.size() == _smallHeap.size()) {
//            if (_bigHeap.empty() || num <= _bigHeap.top()) _bigHeap.push(num);
//            else {//num > _bigHeap.top()
//                _smallHeap.push(num);
//                _bigHeap.push(_smallHeap.top());
//                _smallHeap.pop();
//            }
//        }
//        else {
//            if (num <= _bigHeap.top()) {
//                _bigHeap.push(num);
//                _smallHeap.push(_bigHeap.top());
//                _bigHeap.pop();
//            }
//            else _smallHeap.push(num);
//        }
//    }
//    double findMedian() {
//        if (_bigHeap.size() == _smallHeap.size()) return (_bigHeap.top() + _smallHeap.top()) / 2.0;
//        else return _bigHeap.top();
//    }
//};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */








/******************************************** 下一个排列（LeetCode）*********************************************/
/*
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列
例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1]
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列
更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，
那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）

例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列
给你一个整数数组 nums ，找出 nums 的下一个排列
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    void nextPermutation(vector<int>& nums)
//    {
//        int indexOne = nums.size() - 2;
//        //找到符合nums[index] < nums[index + 1]的组合
//        while (indexOne >= 0 && nums[indexOne] >= nums[indexOne + 1])
//            --indexOne;//退出该循环时,[indexOne + 1, n)必是降序区间
//
//        if (indexOne >= 0)//若是indexOne < 0,说明找不到符合要求的组合,这个组合逆序,直接反转即可
//        {
//            int indexTwo = nums.size() - 1;
//            //找到尽可能小的右值
//            while (indexTwo >= 0 && nums[indexOne] >= nums[indexTwo])
//                --indexTwo;//退出该循环时, nums[indexOne] < nums[indexTwo]
//            swap(nums[indexOne], nums[indexTwo]);//此时[indexOne + 1, n)依然是降序区间
//        }
//        reverse(nums.begin() + indexOne + 1, nums.end());
//    }
//};