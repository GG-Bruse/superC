/*
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，
应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//1.
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>nums3;
        vector<int>ret;
        nums3.resize(min(nums1.size(), nums2.size()));
        vector<int>::iterator itend = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin());//程序在这一行崩溃
        for_each(nums3.begin(), itend, [&](int val){
            ret.push_back(val);
            });
        return ret;
    }
};

//2.
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int length1 = nums1.size(), length2 = nums2.size();
        vector<int> intersection;
        int index1 = 0, index2 = 0;
        while (index1 < length1 && index2 < length2)
        {
            if (nums1[index1] < nums2[index2])
            {
                index1++;
            }
            else if (nums1[index1] > nums2[index2])
            {
                index2++;
            }
            else
            {
                intersection.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        }
        return intersection;
    }
};

int main()
{
    vector<int>nums1{ 1,2,2,1 };
    vector<int>nums2{2,2};
    Solution s;
    vector<int>ret = s.intersect(nums1, nums2);
    for_each(ret.begin(), ret.end(), [=](int val) {
        cout << val << " ";
        });
        return 0;
}
