/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            ret[i].resize(i + 1);//每行大小设置
            ret[i][0] = ret[i][i] = 1;//每行第一个和最后一个元素都为1，其他元素也暂时赋值为1
            for (int j = 1; j < i; ++j)
            {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];//元素的值等于 上一行该位置的值 加 上一行对应位置前一个的值
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<vector<int>>v = s.generate(5);
    for_each(v.begin(), v.end(), [&](vector<int>temp) {
        for_each(temp.begin(), temp.end(), [&](int num) {
            cout << num << " ";
            });
        cout << endl;
        });
        return 0;
}
