
/*
给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。
*/




//暴力破解
#include<iostream>
using namespace std;
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        for (long long i = 1; i <= num ; ++i)
        {
            if (i * i == (long long)num)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    cout<<s.isPerfectSquare(1);
        return 0;
}





//二分查找
#include<iostream>
using namespace std;
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 0, right = num;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            long square = (long)mid * mid;
            if (square < num)
            {
                left = mid + 1;
            }
            else if (square > num)
            {
                right = mid - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    cout<<s.isPerfectSquare(16);
    return 0;
}





