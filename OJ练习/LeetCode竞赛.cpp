/*********************************** Ԫ�غ���С��ɽ����Ԫ��II��LeetCode��**************************************/
/*
����һ���±��0��ʼ����������nums 
����±���Ԫ�� (i, j, k) ��������ȫ������������Ϊ����һ��ɽ����Ԫ�飺i < j < k
nums[i] < nums[j] �� nums[k] < nums[j]
�����ҳ�nums��Ԫ�غ���С��ɽ����Ԫ�飬��������Ԫ�غ͡����������������������Ԫ�飬����-1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minimumSum(vector<int>& nums)
//    {
//        int size = nums.size();
//        //dp[i] : ��nums[i]��nums[n - 1]����Сֵ
//        vector<int> dp(size);
//        dp[size - 1] = nums[size - 1];
//        for (int i = size - 2; i >= 0; --i)
//            dp[i] = min(dp[i + 1], nums[i]);
//
//        int prev = nums[0];//��¼ɽ����ǰ��С��Ԫ��
//        int minTop = INT_MAX;
//        for (int i = 1; i < size - 1; ++i)//ö��ɽ��
//        {
//            if (prev < nums[i] && nums[i] > dp[i + 1])
//                minTop = min(minTop, prev + nums[i] + dp[i + 1]);
//            prev = min(prev, nums[i]);
//        }
//        return minTop == INT_MAX ? -1 : minTop;
//    }
//};