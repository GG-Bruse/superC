/************************************ ����ͼ��� - ���鲻�ɱ䣨LeetCode��**************************************/
/*
����һ����������  nums�������������͵Ķ����ѯ:
�������� left �� right ������ left �� right��֮��� nums Ԫ�ص� �� ������ left <= right
ʵ�� NumArray �ࣺ
NumArray(int[] nums) ʹ������ nums ��ʼ������
int sumRange(int i, int j)��������nums������left��right֮���Ԫ�ص��ܺ� ��
���� left �� right ���㣨Ҳ���� nums[left] + nums[left + 1] + ... + nums[right] )
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class NumArray {
//public:
//    NumArray(vector<int>& nums)
//    {
//        int size = nums.size();
//        prevSum = vector<int>(size + 1);
//        for (int i = 0; i < size; ++i)
//            prevSum[i + 1] = prevSum[i] + nums[i];
//    }
//
//    int sumRange(int left, int right) {
//        return prevSum[right + 1] - prevSum[left];
//    }
//private:
//    vector<int> prevSum;//ǰ׺�� : prevSum[i] : nums[0]��nums[i]֮������Ԫ��֮�� 
//};
///**
// * Your NumArray object will be instantiated and called as such:
// * NumArray* obj = new NumArray(nums);
// * int param_1 = obj->sumRange(left,right);
// */










/********************************** ��ά����ͼ��� - ���󲻿ɱ䣨LeetCode��************************************/
/*
����һ����ά���� matrix���������͵Ķ������
�������Ӿ��η�Χ��Ԫ�ص��ܺͣ����Ӿ�������Ͻ�Ϊ(row1, col1)�����½�Ϊ(row2, col2)
ʵ�� NumMatrix �ࣺ
NumMatrix(int[][] matrix) ������������ matrix ���г�ʼ��
int sumRegion(int row1, int col1, int row2, int col2) ���� ���Ͻ� (row1, col1) ��
���½� (row2, col2) ���������Ӿ����Ԫ�� �ܺ�
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class NumMatrix {
//public:
//    NumMatrix(vector<vector<int>>& matrix)
//    {
//        row = matrix.size(), col = matrix[0].size();
//        //prevSum[i][j] : matrix[0][0]��matrix[i - 1][j - 1]֮������Ԫ��֮�� 
//        prevSum = vector<vector<int>>(row + 1, vector<int>(col + 1));
//        prevSum[1][1] = matrix[0][0];
//        for (int i = 1; i <= row; ++i)
//            for (int j = 1; j <= col; ++j)
//                prevSum[i][j] = prevSum[i - 1][j] + prevSum[i][j - 1] - prevSum[i - 1][j - 1] + matrix[i - 1][j - 1];
//    }
//    int sumRegion(int row1, int col1, int row2, int col2)
//    {
//        ++row1, ++row2, ++col1, ++col2;
//        int ret = prevSum[row2][col2];
//        ret -= (prevSum[row2][col1 - 1] + prevSum[row1 - 1][col2]);
//        ret += prevSum[row1 - 1][col1 - 1];
//        return ret;
//    }
//private:
//    vector<vector<int>> prevSum;
//    int row = 0, col = 0;
//};
///**
// * Your NumMatrix object will be instantiated and called as such:
// * NumMatrix* obj = new NumMatrix(matrix);
// * int param_1 = obj->sumRegion(row1,col1,row2,col2);
// */









/****************************** �������򲻳��� K �������ֵ�ͣ�LeetCode��**************************************/
/*
����һ�� m x n �ľ��� matrix ��һ������ k ���ҳ������ؾ����ڲ���������Ĳ����� k �������ֵ��
��Ŀ���ݱ�֤�ܻ����һ����ֵ�Ͳ����� k �ľ�������
*/
//#include <iostream>
//#include <vector>
//#include <set>
//using namespace std;
//class Solution {
//public:
//    int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
//    {
//        int ret = INT_MIN;
//        int row = matrix.size(), col = matrix[0].size();
//        for (int i = 0; i < row; ++i)//ö���ϱ߽�
//        {
//            vector<int> sum(col);//�߽��� ÿ�е�Ԫ�غ�
//            for (int j = i; j < row; ++j)//ö���±߽�
//            {
//                for (int k = 0; k < col; ++k)
//                    sum[k] += matrix[j][k];//����ÿ�е�Ԫ�غ�
//
//                set<int> sumSet{ 0 };
//                int sRight = 0;
//                for (int it : sum)
//                {
//                    sRight += it;
//                    auto sLeft = sumSet.lower_bound(sRight - k);
//                    if (sLeft != sumSet.end())
//                        ret = max(ret, sRight - (*sLeft));
//                    sumSet.insert(sRight);
//                }
//            }
//        }
//        return ret;
//    }
//};