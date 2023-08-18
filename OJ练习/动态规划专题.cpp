/*********************************************************** 解码方法（LeetCode）**********************************************************/
/*
一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
要解码已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
"AAJF" ，将消息分组为 (1 1 10 6)
"KJF" ，将消息分组为 (11 10 6)
注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。

给你一个只含数字的非空字符串s ，请计算并返回解码方法的总数 
题目数据保证答案肯定是一个 32 位 的整数
*/

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution_1 {
//public:
//    int numDecodings(string s)
//    {
//        //状态dp[i]: 从下标0到i处的子串，解码方法的总数
//        vector<int> dp(s.size(), 0);
//
//        //初始化
//        dp[0] = (s[0] != '0');
//        if (s.size() == 1) return dp[0];
//
//        int tmp = (s[0] - '0') * 10 + (s[1] - '0');
//        if (s[0] != '0' && s[1] != '0') ++dp[1];
//        if (tmp >= 10 && tmp <= 26) ++dp[1];
//
//        //状态转移方程：
//        //若s[i]可以单独解码, dp[i] += dp[i - 1];
//        //若s[i]和s[i - 1]结合后可以进行解码, dp[i] += dp[i - 2];
//        for (int i = 2; i < dp.size(); ++i)
//        {
//            if (s[i] != '0') dp[i] += dp[i - 1];
//            int tmp = (s[i - 1] - '0') * 10 + (s[i] - '0');
//            if (tmp >= 10 && tmp <= 26) dp[i] += dp[i - 2];
//        }
//        return dp.back();
//    }
//};
//class Solution_2 {//优化: 简化初始化以及边界问题，将初始化操作放入填表操作中
//public:
//    int numDecodings(string s)
//    {
//        //状态dp[i]: 从下标0到i - 1处的子串，解码方法的总数
//        vector<int> dp(s.size() + 1, 0);
//        //初始化
//        dp[0] = 1;//虚拟结点，需确保后面的填表是正确的
//        dp[1] = (s[0] != '0');
//
//        for (int i = 2; i < dp.size(); ++i)
//        {
//            if (s[i - 1] != '0') dp[i] += dp[i - 1];
//            int tmp = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
//            if (tmp >= 10 && tmp <= 26) dp[i] += dp[i - 2];
//        }
//        return dp.back();
//    }
//};
//int main()
//{
//    string str;
//    cin >> str;
//    Solution_1 s;
//    cout << s.numDecodings(str) << endl;
//    return 0;
//}
























