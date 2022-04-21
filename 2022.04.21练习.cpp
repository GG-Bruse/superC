/*
给定一个非负整数 x ，计算并返回 x 的平方根，即实现 int sqrt(int x) 函数。

正数的平方根有两个，只输出其中的正数平方根。

如果平方根不是整数，输出只保留整数的部分，小数部分将被舍去。
*/

/*
由于 x 平方根的整数部分 ans 是满足 k^2 ≤x 的最大 k 值，因此我们可以对 k 进行二分查找，从而得到答案。
二分查找的下界为 0，上界可以粗略地设定为 x。在二分查找的每一步中，我们只需要比较中间元素 mid 的平方与 x 的大小关系，
并通过比较的结果调整上下界的范围。由于我们所有的运算都是整数运算，不会存在误差，因此在得到最终的答案 ans 后，也就不需要再去尝试 1ans+1 了。
*/
#include<iostream>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0, right = x, ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    cout << s.mySqrt(4) << endl;
        return 0;
}











/*
一个字符串如果没有 三个连续 相同字符，那么它就是一个 好字符串 。

给你一个字符串 s ，请你从 s 删除 最少 的字符，使它变成一个 好字符串 。

请你返回删除后的字符串。题目数据保证答案总是 唯一的 。
*/

//算法思想
/*
如果想使得好字符串对应的删除字符数量最少，那么最佳的删除策略是：对于 s 中每一个长度为 k(k≥3) 的连续相同字符子串，删去其中任意 k−2 个字符。

我们可以用一个新字符串 res 来维护删除最少字符后得到的好字符串，并从左至右遍历字符串 s 模拟删除过程。
每当遍历至一个新的字符时，我们检查 res 中的最后两个字符（如有）是否均等于当前字符：

如果是，则该字符应被删除，我们不将该字符添加进 res；

如果不是，则不需要删除该字符，我们应当将该字符添加进 res。

当遍历完成 ss 后，res 即为删除最少字符后得到的好字符串，我们返回 res 作为答案。
*/

#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    string makeFancyString(string s)
    {
        string res;   // 删除后的字符串
        // 遍历 s 添加元素模拟删除过程
        for (string::iterator it = s.begin(); it != s.end(); ++it)
        {
            int n = res.size();
            if (n >= 2 && res[n - 1] == *it && res[n - 2] == *it)
            {
                // 如果 res 最后两个字符与当前字符均相等，则不添加
                continue;
            }
            // 反之则添加
            res.push_back(*it);
        }
        return res;
    }
};
int main()
{
    string str = "leeetcode";
    Solution s;
    cout << s.makeFancyString(str) << endl;
        return 0;
}
