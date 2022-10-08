/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即x^n ）。
*/




//超出时间限制
#include<iostream>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        double ret = 1;
        for (int i = 0; i < n; ++i)
        {
            ret *= x;
        }
        return ret;
    }
};
int main()
{
    Solution s;
    cout<<s.myPow(2.00000,10);
}







//快速幂+递归
#include<iostream>
using namespace std;
class Solution
{
public:
    double quickMul(double x, long long N)
    {
        if (N == 0)
        {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
    double myPow(double x, int n)
    {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};






//快速幂+递归
#include<iostream>
using namespace std;
class Solution
{
public:
    double quickMul(double x, long long N)
    {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n)
    {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
