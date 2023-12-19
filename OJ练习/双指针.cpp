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