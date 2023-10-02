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