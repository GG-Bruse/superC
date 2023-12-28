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









/******************************************* 最长有效括号（LeetCode）******************************************/
/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度
*/
//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//class Solution {
//public:
//    int longestValidParentheses(string s)
//    {
//        int size = s.size();
//        stack<int> sk;//存储下标
//        sk.push(-1);
//        int ret = 0;
//        for (int i = 0; i < size; ++i)
//        {
//            if (s[i] == '(') sk.push(i);
//            else //s[i] == ')'
//            {
//                sk.pop();
//                if (sk.empty()) sk.push(i);
//                else ret = max(ret, i - sk.top());
//            }
//        }
//        return ret;
//    }
//};










/****************************************** 移掉K位数字（LeetCode）********************************************/
/*
给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小
请你以字符串形式返回这个最小的数字
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    string removeKdigits(string num, int k)
//    {
//        vector<char> sk;
//        for (int i = 0; i < num.size(); ++i)
//        {
//            while (!sk.empty() && sk.back() > num[i] && k > 0) {
//                sk.pop_back();
//                k -= 1;
//            }
//            sk.push_back(num[i]);
//        }
//        while (k--) sk.pop_back();
//
//        string ret = "";
//        bool isLeadingZero = true;
//        for (auto& it : sk)
//        {
//            if (isLeadingZero && it == '0') continue;
//            isLeadingZero = false;
//            ret += it;
//        }
//        return ret == "" ? "0" : ret;
//    }
//};