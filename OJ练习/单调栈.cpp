/******************************************** ����ˮ��LeetCode��***********************************************/
/*
���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ
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









/****************************************** ��״ͼ�����ľ��Σ�LeetCode��*************************************/
/*
���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ1
���ڸ���״ͼ�У��ܹ����ճ����ľ��ε�������
*/
//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
////����ջ
////������һ����[�����һ���߶�С�ڸ����ӵ�����,���ҵ�һ��С�ڸ����ӵ�����]֮��
//class Solution
//{
//public:
//    int largestRectangleArea(vector<int>& heights)
//    {
//        stack<int> sk;
//        int ret = 0;
//        heights.push_back(-1);//��֤ջ�����
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