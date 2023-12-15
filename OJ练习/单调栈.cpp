/******************************************** 接雨水（LeetCode）***********************************************/
/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
*/
//#include <iostream>
//#include <vector>
//using namespace std;
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









/****************************************** 柱状图中最大的矩形（LeetCode）*************************************/
/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为1
求在该柱状图中，能够勾勒出来的矩形的最大面积
*/
//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
////单调栈
////最大面积一定在[往左第一个高度小于该柱子的柱子,往右第一个小于该柱子的柱子]之间
//class Solution
//{
//public:
//    int largestRectangleArea(vector<int>& heights)
//    {
//        stack<int> sk;
//        int ret = 0;
//        heights.push_back(-1);//保证栈被清空
//        for (int i = 0; i < heights.size(); ++i)
//        {
//            while (!sk.empty() && heights[i] < heights[sk.top()])
//            {
//                int index = sk.top();
//                sk.pop();
//                int left = sk.empty() ? -1 : sk.top();
//                ret = max(ret, (i - left - 1) * heights[index]);
//            }
//            sk.push(i);
//        }
//        return ret;
//    }
//};