/*
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，
那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
*/

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int findLengthOfLCIS(vector<int>& nums)
//    {
//        int count = 0;
//        vector<int>v;
//        for (vector<int>::iterator it = nums.begin()+1; it != nums.end(); ++it)
//        {
//            if (*(it - 1) < *it)
//            {
//                ++count;
//            }
//            else
//            {
//                v.push_back(count);
//                count = 0;
//            }
//        }
//        v.push_back(count);
//        sort(v.begin(), v.end());
//        return v[v.size() - 1] + 1;
//    }
//};
//int main()
//{
//    vector<int>nums{ 1,3,5,7};
//    Solution s;
//    cout<<s.findLengthOfLCIS(nums);
//	return 0;
//}


//#include<cmath>
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    int findLengthOfLCIS(vector<int>& nums)
//    {
//        int ans = 0;
//        int n = nums.size();
//        int start = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (i > 0 && nums[i] <= nums[i - 1])
//            {
//                start = i;
//            }
//            ans = max(ans, i - start + 1);
//        }
//        return ans;
//    }
//};












/*
nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
//    {
//        vector<int>v;
//        int count = 0;
//        bool flag = false;
//        for (int i = 0; i < nums1.size(); ++i)
//        {
//            for (int j = 0; j < nums2.size(); ++j)
//            {
//                if (nums1[i] == nums2[j])
//                {
//                    count = j;
//                    break;
//                }
//            }
//            for (int j = count + 1; j < nums2.size(); ++j)
//            {
//                if (nums2[count] < nums2[j])
//                {
//                    v.push_back(nums2[j]);
//                    flag = true;
//                    break;
//                }
//            }
//            if (flag == false)
//            {
//                v.push_back(-1);
//            }
//            flag = false;
//        }
//        return v;
//    }
//};
//int main()
//{
//    vector<int>nums1{ 4, 1, 2 }, nums2{ 1, 3, 4, 2 };
//    Solution s;
//    vector<int>ret = s.nextGreaterElement(nums1, nums2);
//    for (vector<int>::iterator it = ret.begin(); it != ret.end(); ++it)
//    {
//        cout << *it << " ";
//    }
//	return 0;
//}






//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
//    {
//        int m = nums1.size();
//        int n = nums2.size();
//        vector<int> res(m);
//        for (int i = 0; i < m; ++i)
//        {
//            int j = 0;
//            while (j < n && nums2[j] != nums1[i])
//            {
//                ++j;
//            }//找到元素相同时的下标
//            int k = j + 1;
//            while (k < n && nums2[k] < nums2[j])
//            {
//                ++k;
//            }//找到nums2[k]>nums2[j]
//            res[i] = k < n ? nums2[k] : -1;
//        }
//        return res;
//    }
//};