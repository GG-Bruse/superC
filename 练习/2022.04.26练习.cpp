/*
丑数 就是只包含质因数 2、3 和 5 的正整数。

给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
*/

/*
当 n>0 时，若 n 是丑数，则 n 可以写成 n = 2^a x 3^b x 5^c 的形式，其中 a,b,c 都是非负整数。特别地，当 a,b,c 都是 0 时,n=1。

为判断 n 是否满足上述形式，可以对 n 反复除以 2,3,5，直到 n 不再包含质因数 2,3,5。
若剩下的数等于 1，则说明 n 不包含其他质因数，是丑数；否则，说明 n 包含其他质因数，不是丑数。

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        vector<int> factors = { 2, 3, 5 };
        for (vector<int>::iterator it = factors.begin(); it != factors.end(); ++it)
        {
            while (n % (*it) == 0)
            {
                n /= (*it);
            }
        }
        return n == 1;
    }
};
int main()
{
    Solution s;
    cout<<s.isUgly(7);
        return 0;
}









/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
*/

#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        return i == n;
    }
};
int main()
{
    string s = "abc", t = "ahbgdc";
    Solution sol;
    cout<<sol.isSubsequence(s, t);
        return 0;
}






#include<iostream>
using namespace std;
class Solution
{
public:
    int mySqrt(int num)
    {
        int left = 0, right = num, ret = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid <= num)
            {
                ret = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ret;
    }
};
int main()
{
    int num;
    cin >> num;
    Solution s;
    cout << s.mySqrt(num) << endl;
    return 0;
}





