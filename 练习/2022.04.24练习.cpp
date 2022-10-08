/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串
*/

//贪心法
/*
在允许最多删除一个字符的情况下，同样可以使用双指针，通过贪心实现。初始化两个指针 low 和 high 分别指向字符串的第一个字符和最后一个字符。
每次判断两个指针指向的字符是否相同，如果相同，则更新指针，将 low 加 1，high 减 1，然后判断更新后的指针范围内的子串是否是回文字符串。
如果两个指针指向的字符不同，则两个字符中必须有一个被删除，此时我们就分成两种情况：即删除左指针对应的字符，留下子串 s[low+1:high]，
或者删除右指针对应的字符，留下子串 s[low:high−1]。当这两个子串中至少有一个是回文串时，就说明原始字符串删除一个字符之后就以成为回文串。
*/
#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int low = 0, high = s.size() - 1;
        while (low < high)
        {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2)
            {
                ++low;
                --high;
            }
            else
            {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
            }
        }
        return true;
    }
private:
    bool checkPalindrome(const string& s, int low, int high)//判断是否为回文串
    {
        for (int i = low, j = high; i < j; ++i, --j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    string str = "aba";
    Solution s;
    cout<<s.validPalindrome(str);
    return 0;
}















/*
给定一个 n x n 的二进制矩阵 image ，先 水平 翻转图像，然后 反转 图像并返回 结果 。
水平翻转图片就是将图片的每一行都进行翻转，即逆序。
反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
    {
        vector<vector<int>>ret;
        for (vector<vector<int>>::iterator it = image.begin(); it != image.end(); ++it)
        {
            vector<int>v;
            for (vector<int>::reverse_iterator its = (*it).rbegin(); its != (*it).rend(); ++its)
            {
                if (*its == 1)
                {
                    v.push_back(0);
                }
                else
                {
                    v.push_back(1);
                }
            }
            ret.push_back(v);
        }

        return ret;
    }
};
int main()
{
    vector<vector<int>>image = { {1, 1, 0},{1, 0, 1},{0, 0, 0} };
    Solution s;
    vector<vector<int>> ret = s.flipAndInvertImage(image);
    for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); ++it)
    {
        for (vector<int>::iterator its = (*it).begin(); its != (*it).end(); ++its)
        {
            cout << *its << " ";
        }
        cout << endl;
    }
        return 0;
}



