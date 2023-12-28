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









/******************************************* ���Ч���ţ�LeetCode��******************************************/
/*
����һ��ֻ���� '(' �� ')' ���ַ������ҳ����Ч����ʽ��ȷ�������������Ӵ��ĳ���
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
//        stack<int> sk;//�洢�±�
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










/****************************************** �Ƶ�Kλ���֣�LeetCode��********************************************/
/*
����һ�����ַ�����ʾ�ķǸ����� num ��һ������ k ���Ƴ�������е� k λ���֣�ʹ��ʣ�µ�������С
�������ַ�����ʽ���������С������
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