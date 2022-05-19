/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<int> temp;
        dfs(nums, temp);
        return ret;
    }
private:
    vector<vector<int>>ret;
    void dfs(vector<int>& nums, vector<int>& temp)
    {
        if (temp.size() == nums.size())
        {
            ret.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (count(temp.begin(), temp.end(), nums[i])) continue;
            temp.push_back(nums[i]);
            dfs(nums, temp);
            temp.pop_back();
        }
    }
};

int main()
{
    vector<int>v{ 0,1 };
    Solution s;
    vector<vector<int>>ret = s.permute(v);
    for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); ++it)
    {
        for (vector<int>::iterator its = (*it).begin(); its != (*it).end(); ++its)
        {
            cout << *its << " ";
        }
        cout << endl;
    }

    for_each(ret.begin(), ret.end(), [&](vector<int>temp) {
        for_each(temp.begin(), temp.end(), [&](int n) {
            cout << n << " ";
            });
        cout << endl;
        });
    return 0;
}
