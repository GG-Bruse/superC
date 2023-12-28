/************************************* 两数之和II - 输入有序数组（LeetCode）***********************************/
/*
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列，
请你从数组中找出满足相加之和等于目标数 target 的两个数
如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length
以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2
你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素
你所设计的解决方案必须只使用常量级的额外空间
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& numbers, int target)
//    {
//        int size = numbers.size();
//        int left = 0, right = size - 1;
//        while (left < right)
//        {
//            int tmpSum = numbers[left] + numbers[right];
//            if (tmpSum == target) return { left + 1, right + 1 };
//            else if (tmpSum > target) --right;
//            else ++left;
//        }
//        return { -1, -1 };
//    }
//};










/*********************************************** 接雨水（LeetCode）********************************************/
/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
*/
//#include <iostream>
//#include <vector>
//using namespace std;
////双指针
//class Solution {
//public:
//    int trap(vector<int>& height)
//    {
//        int left = 0, right = height.size() - 1;
//        int leftMax = 0, rightMax = 0;
//        int ret = 0;
//        while (left < right)
//        {
//            leftMax = max(leftMax, height[left]);
//            rightMax = max(rightMax, height[right]);
//            if (height[left] < height[right]) {
//                ret += (leftMax - height[left]);
//                ++left;
//            }
//            else {
//                ret += (rightMax - height[right]);
//                --right;
//            }
//        }
//        return ret;
//    }
//};










/***************************************** 最接近的三数之和（LeetCode）****************************************/
/*
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近
返回这三个数的和
假定每组输入只存在恰好一个解
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    int threeSumClosest(vector<int>& nums, int target)
//    {
//        sort(nums.begin(), nums.end());
//        int size = nums.size();
//
//        int ret = 0xfffff;
//        auto update = [&](int current) {
//            if (abs(current - target) < abs(ret - target))
//                ret = current;
//        };
//
//        for (int i = 0; i < size; ++i)//枚举第一个元素
//        {
//            if (i > 0 && nums[i] == nums[i - 1]) continue;//保证和上一次枚举的元素不相等
//            int left = i + 1, right = size - 1;
//            while (left < right)
//            {
//                int sum = nums[i] + nums[left] + nums[right];
//                if (sum == target) return target;
//                update(sum);
//
//                if (sum > target)//若和大于target,向前移动right
//                {
//                    int tmpRight = right - 1;
//                    //移动到下一个不相等的元素
//                    while (left < tmpRight && nums[tmpRight] == nums[right]) --tmpRight;
//                    right = tmpRight;
//                }
//                else//sum < target,向后移动left
//                {
//                    int tmpLeft = left + 1;
//                    while (tmpLeft < right && nums[tmpLeft] == nums[left]) ++tmpLeft;
//                    left = tmpLeft;
//                }
//            }
//        }
//        return ret;
//    }
//};










/***************************************** 三数之和（LeetCode）************************************************/
/*
给你一个整数数组 nums 
判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k 
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










/******************************************* 比较版本号（LeetCode）********************************************/
/*
给你两个版本号 version1 和 version2 ，请你比较它们
版本号由一个或多个修订号组成，各修订号由一个 '.' 连接。每个修订号由 多位数字 组成，可能包含前导零
每个版本号至少包含一个字符。修订号从左到右编号，下标从 0 开始，最左边的修订号下标为 0 ，下一个修订号下标为 1 ，
以此类推。例如，2.5.33 和 0.1 都是有效的版本号
比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，只需比较 忽略任何前导零后的整数值
也就是说，修订号 1 和修订号 001 相等 。如果版本号没有指定某个下标处的修订号，则该修订号视为 0
例如，版本 1.0 小于版本 1.1 ，因为它们下标为 0 的修订号相同，而下标为 1 的修订号分别为 0 和 1 ，0 < 1
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
////方法一
//class Solution {
//public:
//    int Compare(string str1, string str2)
//    {
//        int ret = atoi(str1.c_str()) - atoi(str2.c_str());
//        if (ret == 0) return ret;
//        return ret > 0 ? 1 : -1;
//    }
//    int compareVersion(string version1, string version2)
//    {
//        int sizeV1 = version1.size(), sizeV2 = version2.size();
//        int currentV1 = 0, prevV1 = currentV1;
//        int currentV2 = 0, prevV2 = currentV2;
//        while (currentV1 < sizeV1 || currentV2 < sizeV2)
//        {
//            while (currentV1 < sizeV1 && version1[currentV1] != '.') ++currentV1;
//            while (currentV2 < sizeV2 && version2[currentV2] != '.') ++currentV2;
//            int tmpRet = 0;
//
//            if (currentV1 > sizeV1)
//                tmpRet = Compare("0", version2.substr(prevV2, currentV2 - prevV2));
//            else if (currentV2 > sizeV2)
//                tmpRet = Compare(version1.substr(prevV1, currentV1 - prevV1), "0");
//            else if (currentV1 <= sizeV1 || currentV2 <= sizeV2)
//                tmpRet = Compare(version1.substr(prevV1, currentV1 - prevV1), version2.substr(prevV2, currentV2 - prevV2));
//            if (tmpRet != 0) return tmpRet;
//            ++currentV1, ++currentV2;
//            prevV1 = currentV1, prevV2 = currentV2;
//        }
//        return 0;
//    }
//};
////方法二
//class Solution {
//public:
//    int compareVersion(string version1, string version2)
//    {
//        int n = version1.length(), m = version2.length();
//        int i = 0, j = 0;
//        while (i < n || j < m)
//        {
//            long long x = 0;
//            for (; i < n && version1[i] != '.'; ++i)
//                x = x * 10 + version1[i] - '0';
//            ++i; // 跳过点号
//
//            long long y = 0;
//            for (; j < m && version2[j] != '.'; ++j)
//                y = y * 10 + version2[j] - '0';
//            ++j; // 跳过点号
//            if (x != y) return x > y ? 1 : -1;
//        }
//        return 0;
//    }
//};
