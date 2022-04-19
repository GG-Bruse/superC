/*
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size < 3)
        {
            return nums[size - 1];
        }
        for (vector<int>::iterator it = nums.begin(); it != nums.end() - 2; ++it, --size)
        {
            if (*it == *(it + 1) && *it == *(it + 2))
            {
                it += 2;
                size -= 2;
            }
            else
            {
                if (*it == *(it + 1))
                {
                    return *(it + 2);
                }
                else if (*it == *(it + 2))
                {
                    return *(it + 1);
                }
                else
                {
                    return *it;
                }
            }
            if (size < 3)
            {
                return nums[nums.size() - 1];
            }
        }
        return -1;
    }
};
int main()
{
    vector<int>v{ 1};
    Solution s;
    cout<<s.singleNumber(v);
        return 0;
}












/*
给你一个混合字符串 s ，请你返回 s 中 第二大 的数字，如果不存在第二大的数字，请你返回 -1 。

混合字符串 由小写英文字母和数字组成。
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int secondHighest(string s)
    {
        sort(s.begin(), s.end());
        for (string::iterator it = s.begin(); it != s.end();)
        {
            if (*it >= 97 && *it <= 122)
            {
                it = s.erase(it);
            }
            else
            {
                ++it;
            }
        }
        if (s.size() == 0)
        {
            return -1;
        }
        for (string::reverse_iterator it = s.rbegin()+1; it != s.rend(); ++it)
        {
            if (*it != s[s.size() - 1])
            {
                return (int)((*it) - 48);
            }
        }
        return -1;
    }
};
int main()
{
    string str = "xyz";
    Solution s;
    cout << s.secondHighest(str);
        return 0;
}
